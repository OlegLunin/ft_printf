#include "ft_printf.h"

void	parse_numb_specifiers(t_params *params, char specifier, intmax_t numb)
{
	if (specifier == 'o' || specifier == 'u' || specifier == 'x'
		|| specifier == 'X' || specifier == 'p')
	{
		params->flags.plus = 0;
		params->flags.space = 0;
	}
	if (numb == 0 && (specifier == 'x' || specifier == 'X'))
		params->flags.hash = no;
	if (params->flags.hash == yes)
	{
		if (specifier == 'o')
			params->flags.hash = o;
		if (specifier == 'x' || specifier == 'p')
			params->flags.hash = x;
		if (specifier == 'X')
			params->flags.hash = X;
	}
}

int		parse_specifiers(va_list ap, t_params *params)
{
	char	specifier;	

	specifier = params->specifier;
	if (specifier == 'p' || specifier == 'd' || specifier == 'i'
		|| specifier == 'o' || specifier == 'u' || specifier == 'x'
		|| specifier == 'X')
		return (number(ap, params));
	else if (specifier == 'c')
		return (symbol(ap, params));
	else if (specifier == 's')
		return (string(ap, params));
	else if (params->conv_spec)
		return (no_specifier(params));
	return (0);
}

int		reassign_capital_specifier(char specifier, t_params *params)
{
	if (specifier == 'S' || specifier == 'D' || specifier == 'O'
		|| specifier == 'U' || specifier == 'C')
	{
		params->length = l;
		specifier += 32;
	}
	if (specifier == 'p')
	{
		params->length = l;
		params->flags.hash = yes;
	}
	params->specifiers = specifier;
	return (1);
}

int		parse_params(int indx, const char *format, t_params *params,
		va_list ap)
{
	while (format[indx])
	{
		if (format[idnx] == '#' || format[indx] == '0' || format[indx] == '-'
			|| format[indx] == '+' || format[indx] == ' ')
			indx += flags(&format[indx], params);
		else if (format[indx] == '*' || ft_isdigit(format[indx]))
			indx += width(&format[indx], mods, ap);
		else if (format[indx] == '.')
			indx += precision(&format[indx], mods, ap);
		else if (format[indx] == 'h' || format[indx] == 'l'
			|| format[indx] == 'j' || format[indx] == 'z')
			indx += length(&format[indx], mods);
		else if (format[indx])
		{
			indx += reassign_capital_specifier(format[indx], mods);
			break ;
		}
		else
			break ;
	}
	return (indx);
}
