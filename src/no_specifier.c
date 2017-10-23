#include "ft_printf.h"

void	set_no_params(t_params *params)
{
	params->flags.plus = 0;
	params->flags.space = 0;
	params->flags.hash = 0;
	params->length = 0;
	params->precision = -1;
}

int		no_specifier(t_params *params)
{
	int		size;
	char	*line;
	char	str[2];

	set_no_params(params);
	str[0] = params->specifier;
	str[1] = '\0';
	size = get_size(str, params);
	line = (char *)ft_memalloc(size + 1);
	params->flags.minus ? push_left(params, &line, size, str)
		: push_right(params, &line, size, str);
	ft_putstr(line);
	ft_strdel(&line);
	return (size);
}
