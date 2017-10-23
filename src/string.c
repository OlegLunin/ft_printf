#include "ft_printf.h"

static char	*reg_mbstr(char *new_str)
{
	int		indx;
	int		count_byte;

	indx = 0;
	while (new_str[indx])
	{
		if ((count_byte = is_multibyte(&new_str[indx])))
			indx += count_byte;
		else
		{
			new_str[indx] = '\0';
			break ;
		}
	}
	return (new_str);
}

char	*reg_str(t_params *params, char *str)
{
	int		indx;
	char	*new_str;

	if (params->precision > -1)
	{
		indx = -1;
		new_str = (char *)ft_memalloc(params->precision + 1);
		while (++indx < params->precision)
			new_str[indx] = str[indx];
		new_str[indx] = '\0';
		new_str = reg_mbstr(new_str);
		params->precision = -1;
		ft_strdel(&str);
		return (new_str);
	}
	else
		return (str);
}

char	*get_str(va_list ap, t_params *params)
{
	wchar_t	*old_wide_str;
	char	*old_str;
	char	*str;

	if (params->length == l)
	{
		if ((old_wide_str = va_arg(ap, wchar_t *)) == NULL)
			str = ft_strdup("(null)");
		else
		{
			str = (char *)ft_memalloc(ft_wcslen(old_wide_str) + 1);
			ft_wcstombs(str, old_wide_str, ft_wcslen(old_wide_str) + 1);
		}
	}
	else
	{
		if ((old_str = va_arg(ap, char *)) == NULL)
			str = ft_strdup("(null)");
		else
			str = ft_strdup(old_str);
	}
	if (!(str = reg_str(params, str)))
		return (NULL);
	return (str);
}

int		string(va_list ap, t_params *params)
{
	int		size;
	char	*str;
	char	*line;

	str = get_str(ap, params);
	params->flags.plus = 0;
	params->flags.space = 0;
	params->flags.hash = 0;
	params->length = 0;
	size = (params->width < (int)ft_strlen(str)) ? (int)ft_strlen(str)
		: params->width;
	line = (char *)ft_memalloc(size + 1);
	params->flags.minus ? push_left(params, &line, size, str)
		: push_right(params, &line, size, str);
	ft_putstr(line);
	ft_strdel(&str);
	ft_strdel(&line);
	return (size);
}
