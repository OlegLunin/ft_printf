#include "ft_printf.h"

int		put_sign(t_params *params, char **line, int indx, char *str)
{
	if (str[0] == '-')
		(*line)[indx++] = '-';
	else if ((params->flags.hash == o && str[0] != '0')
		|| params->flags.hash == x || params->flags.hash == X)
	{
		(*line)[indx++] = '0';
		if (params->flags.hash == x)
			(*line)[indx++] = 'x';
		if (params->flags.hash == X)
			(*line)[indx++] = 'X';
	}
	else if (params->flags.plus)
		(*line)[indx++] = '+';
	else if (params->flags.space)
		(*line)[indx++] = ' ';
	return (indx);
}

int		put_content(t_params *params, char **line, int indx, char *str)
{
	int		j;
	int		len;
	int		precision;

	len = ft_strlen(str);
	precision = params->precision - len;
	j = 0;
	if (str[0] == '-')
	{
		j++;
		precision++;
	}
	while (precision-- > 0)
		(*line)[indx++] = '0';
	while (str[j])
		(*line)[indx++] = str[j++];
	return (indx);
}

int		regulate_indx(t_params *params, int indx, char *str, int len)
{
	if (((params->flags.plus || params->flags.space) && str[0] != '-')
			|| params->flags.hash == o)
		indx--;
	if (params->precision >= len && str[0] == '-')
		indx--;
	if (params->flags.hash == x || params->flags.hash == X)
		indx -= 2;
	return (indx);
}

void	push_right(t_params *params, char **line, int size, char *str)
{
	int		indx;
	int		value;
	int		len;

	indx = 0;
	if (params->precision < 0 && params->flags.zero)
	{
		indx = put_sign(params, line, indx, str);
		if (str[0] == '-')
			str++;
		len = ft_strlen(str);
		while (indx < size - len)
			(*line)[indx++] = '0';
	}
	else
	{
		len = ft_strlen(str);
		value = (len > params->precision) ? size - len
			: size - params->precision;
		while (indx < value)
			(*line)[indx++] = ' ';
		indx = regulate_indx(params, indx, str, len);
		indx = put_sign(params, line, indx, str);
	}
	indx = put_content(params, line, indx, str);
	(*line)[indx] = '\0';
}

void	push_left(t_params *params, char **line, int size, char *str)
{
	int		indx;

	indx = put_sign(params, line, 0, str);
	indx = put_content(params, line, indx, str);
	while (indx < size)
		(*line)[indx++] = ' ';
	(*line)[indx] = '\0';
}
