#include "ft_printf.h"

int		flags(const char *format, t_params *params)
{
	int		indx;

	indx = 0;
	while (format[indx] == '#' || format[indx] == '0' || format[indx] == '-'
		|| format[indx] == '+' || format[indx] == ' ')
	{
		if (format[indx] == '#')
			params->flags.hash = yes;
		else if (format[indx] == '0')
			params->flags.zero = 1;
		else if (format[indx] == '-')
			params->flags.minus = 1;
		else if (format[indx] == '+')
			params->flags.plus = 1;
		else if (format[indx] == ' ')
			params->flags.space = 1;
		indx++;
	}
	return (indx);
}
