#include "ft_printf.h"

int		width(const char *format, t_params *params, va_list ap)
{
	int		indx;

	indx = 0;
	if (format[indx] == '*')
	{
		params->width = va_arg(ap, int);
		if (params->width < 0)
		{
			params->flags.minus = 1;
			params->width *= -1;
		}
		return (1);
	}
	if (ft_isdigit(format[indx]))
		params->width = 0;
	while (ft_isdigit(format[indx]))
		params->width = params->width * 10 + (format[indx++] - '0');
	return (indx);
}
