#include "ft_printf.h"

int		parse_double_length(const char *format, t_params *params, int indx)
{
	if (format[indx] == 'h')
	{
		if (params->length == h)
			params->length = hh;
		else if (params->length < h)
			params->length = h;
	}
	else if (format[indx] == 'l')
	{
		if (params->length == l)
			params->length = ll;
		else if (params->length < l)
			params->length = l;
	}
	return (indx);
}

int		length(const char *format, t_params *params)
{
	int		indx;

	indx = 0;
	if (format[indx] == 'h' || format[indx] == 'l')
		indx = parse_double_length(format, params, indx);
	else if (format[indx] == 'j')
		params->length = j;
	else if (format[indx] == 'z')
		params->length = z;
	else
		return (0);
	return (1);
}
