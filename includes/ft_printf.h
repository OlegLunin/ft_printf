#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"

/*
**							  == Regular font colors ==
*/

# define DEF		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define GREY		"\033[37m"

/*
**							   == Bold font colors ==
*/

# define B_DEF		"\033[0;39m"
# define B_BLACK	"\033[1;30m"
# define B_RED		"\033[1;31m"
# define B_GREEN	"\033[1;32m"
# define B_YELLOW	"\033[1;33m"
# define B_BLUE		"\033[1;34m"
# define B_MAGENTA	"\033[1;35m"
# define B_CYAN		"\033[1;36m"
# define B_GREY		"\033[1;37m"

/*
**							  == Background colors ==
*/

# define DG_DEF		"\033[49m"
# define BG_BLACK	"\033[40m"
# define BG_RED		"\033[41m"
# define BG_GREEN	"\033[42m"
# define BG_YELLOW	"\033[43m"
# define BG_BLUE	"\033[44m"
# define BG_MAGENTA	"\033[45m"
# define BG_CYAN	"\033[46m"
# define BG_GREY	"\033[47m"

/*
**									== Length ==
*/

typedef enum
{
	none,
	hh,
	h,
	l,
	ll,
	j,
	z,
}	t_length;

/*
**									 == Hash ==
*/

typedef enum
{
	no,
	yes,
	o,
	x,
	X,
}	t_hash;

/*
**								 == Flags struct ==
*/

typedef struct	s_flags
{
	t_hash		hash;
	int			zero;
	int			minus;
	int			plus;
	int			space;
}				t_flags;

/*
**							  == Parameters struct ==
*/

typedef struct	s_params
{
	t_flags		flags;
	int			width;
	int			precision;
	t_length	length;
	char		specifier;
}				t_params;

/*
**									 == Main ==
*/

int				ft_printf(const char *format, ...);

/*
**									== Parser ==
*/

int				parse_params(int indx, const char *format, t_params *params,
				va_list ap);
int				parse_specifiers(va_list ap, t_params *params);
void			parse_numb_specifiers(t_params *params, char specifier,
				intmax_t numb);

/*
**								  == Parameters ==
*/

int				flags(const char *format, t_params *params);
int				width(const char *format, t_params *params, va_list ap);
int				precision(const char *format, t_params *params, va_list ap);
int				length(const char *format, t_params *params);

/*
**								 == Types of data ==
*/

int				number(va_list ap, t_params *params);
int				symbol(va_list ap, t_params *params);
int				string(va_list ap, t_params *params);
int				no_specifier(t_params *params);

/*
**								  == Positioning ==
*/

void			push_left(t_params *params, char **line, int size, char *str);
void			push_right(t_params *params, char **line, int size, char *str);

/*
**								 	 == Else ==
*/

int				get_size(char *str, t_params *params);
int				is_multibyte(char *str);

#endif
