#include "ft_printf.h"

int		precision(const char *format, t_params *params, va_list ap)
{
	int		indx;

	indx = 0;
	params->precision = 0;
	if (format[++indx] == '*')
	{
		params->precision = va_arg(ap, int);
		return (2);
	}
	while (ft_isdigit(format[indx]))
		params->precision = params->precision * 10 + (format[indx++] - '0');
	return (indx);
}
