#include "ft_printf.h"

void	set_symbol_params(t_params *params, char *str)
{
	if (!str[0] && params->width > 0)
		params->width--;
	params->flags.plus = 0;
	params->flags.space = 0;
	params->flags.hash = 0;
	params->precision = -1;
	params->length = 0;
}

char	*get_char(va_list ap)
{
	char	symbol;
	char	*str;

	str = (char *)ft_memalloc(2);
	symbol = va_arg(ap, int);
	str[0] = symbol;
	str[1] = '\0';
	return (str);
}

int		symbol(va_list ap, t_params *params)
{
	int		size;
	char	*str;
	char	*line;

	str = get_char(ap);
	set_symbol_params(params, str);
	size = get_size(str, params);
	line = (char *)ft_memalloc(size + 1);
	params->flags.minus ? push_left(params, &line, size, str)
		: push_right(params, &line, size, str);
	if (params->flags.minus && !str[0])
		ft_putchar('\0');
	ft_putstr(line);
	if (!params->flags.minus && !str[0])
		ft_putchar('\0');
	if (!str[0])
		size++;
	ft_strdel(&str);
	ft_strdel(&line);
	return (size);
}
