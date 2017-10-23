#include "ft_printf.h"

int		get_size(char *str, t_params *params)
{
	int		len;
	int		size;
	int		hash;

	len = (str[0] == '-') ? ft_strlen(str) - 1 : ft_strlen(str);
	hash = (params->specifier == 'o' && params->flags.hash
			&& len >= params->precision) ? 1 : 0;
	if ((params->specifier == 'x' || params->specifier == 'X'
		|| params->specifier == 'p') && params->flags.hash)
		hash += 2;
	if (params->width > len + hash && params->width > params->precision)
		size = params->width;
	else
	{
		size = len > params->precision ? len + hash : params->precision + hash;
		if (params->flags.plus || params->flags.space || str[0] == '-')
			size++;
	}
	return (size);
}
