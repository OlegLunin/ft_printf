#include "ft_printf.h"

char	*push_to_itoa(intmax_t numb, t_params *params, bool u_numb)
{
	char	specifier;
	char	*str;

	specifier = params->specifier;
	if (specifier == 'u' || specifier == 'd' || specifier == 'i')
		str = (u_numb == true) ? ft_uitoa_base(numb, 10, specifier)
			: ft_itoa(numb);
	else if (specifier == 'o')
		str = ft_uitoa_base(numb, 8, specifier);
	else if (specifier == 'x' || specifier == 'X' || specifier == 'p')
		str = ft_uitoa_base(numb, 16, specifier);
	else if (specifier == 'b')
		str = ft_uitoa_base(numb, 2, specifier);
	else
		return (NULL);
	if (numb == 0 && params->precision == 0)
		str[0] = '\0';
	return (str);
}

char	*convert_unsigned(va_list ap, t_params *params, char specifier)
{
	uintmax_t	numb;

	numb = va_arg(ap, uintmax_t);
	parse_numb_specifiers(params, specifier, numb);
	if (params->length == hh)
		return (push_to_itoa((unsigned char)numb, params, 1));
	else if (params->length == h)
		return (push_to_itoa((unsigned short)numb, params, 1));
	else if (params->length == l)
		return (push_to_itoa((unsigned long)numb, params, 1));
	else if (params->length == ll)
		return (push_to_itoa((unsigned long long)numb, params, 1));
	else if (params->length == j)
		return (push_to_itoa((uintmax_t)numb, params, 1));
	else if (params->length == z)
		return (push_to_itoa((ssize_t)numb, params, 1));
	else
		return (push_to_itoa((unsigned int)numb, params, 1));
}

char	*convert_negative(intmax_t numb, t_params *params)
{
	char	*str;

	if (params->length == l)
		str = (numb < 0) ? push_to_itoa((long)-numb, params, true)
			: push_to_itoa((long)numb, params, true);
	else if (params->length == ll)
		str = (numb < 0) ? push_to_itoa((long long)-numb, params, true)
			: push_to_itoa((long long)numb, params, true);
	else if (params->length == j)
		str = (numb < 0) ? push_to_itoa((intmax_t)-numb, params, true)
			: push_to_itoa((intmax_t)numb, params, true);
	else if (params->length == z)
		str = (numb < 0) ? push_to_itoa((size_t)-numb, params, true)
			: push_to_itoa((size_t)numb, params, true);
	if (numb < 0)
		return (ft_strjoin_free(ft_strdup("-"), str));
	return (str);
}

char	*convert_signed(va_list ap, t_params *params, char specifier)
{
	intmax_t	numb;

	numb = va_arg(ap, intmax_t);
	parse_numb_specifiers(params, specifier, numb);
	if (params->length == hh)
		return (push_to_itoa((char)numb, params, false));
	else if (params->length == h)
		return (push_to_itoa((short)numb, params, false));
	else if (params->length == l || params->length == ll || params->length == j
			|| params->length == z)
		return (convert_negative(numb, params));
	return (push_to_itoa((int)numb, params, false));
}

int		number(va_list ap, t_params *params)
{
	int		size;
	int		ret;
	char	specifier;
	char	*str;
	char	*line;

	specifier = params->specifier;
	if (specifier == 'p' || specifier == 'o' || specifier == 'u'
		|| specifier == 'x' || specifier == 'X')
		str = convert_unsigned(ap, params, specifier);
	else
		str = convert_signed(ap, params, specifier);
	size = get_size(str, params);
	line = (char *)ft_memalloc(size + 1);
	params->flags.minus ? push_left(params, &line, size, str)
		: push_right(params, &line, size, str);
	ft_putstr(line);
	ret = ft_strlen(line);
	ft_strdel(&str);
	ft_strdel(&line);
	return (ret);
}
