/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:02:06 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/13 13:09:26 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_set_mods(t_mods *mods)
{
	mods->flags.left = 0;
	mods->flags.plus = 0;
	mods->flags.space = 0;
	mods->flags.hash = no;
	mods->flags.zero = 0;
	mods->flags.unread = 0;
	mods->flags.quote_mark = 0;
	mods->width = 0;
	mods->precision = -1;
	mods->length = none;
	mods->qualifier = '\0';
	mods->base = 10;
	mods->sigfig = -1;
	mods->exp_base = 10;
	mods->exp_char = 0;
	mods->exp_len = 2;
}

static int	ft_parse_mods(int i, const char *format, t_mods *mods, va_list ap)
{
	while (format[i])
	{
		if (format[i] == '-' || format[i] == '+' || format[i] == ' '
			|| format[i] == '#' || format[i] == '0' || format[i] == 'r'
			|| format[i] == '\'')
			i += ft_flags(&format[i], mods);
		else if (format[i] == '*' || ft_isdigit(format[i]))
			i += ft_width(&format[i], mods, ap);
		else if (format[i] == '.')
			i += ft_precision(&format[i], mods, ap);
		else if (format[i] == 'h' || format[i] == 'l' || format[i] == 'j'
				|| format[i] == 'z' || format[i] == 'L')
			i += ft_length(&format[i], mods);
		else if (format[i])
		{
			i += ft_qualifier(format[i], mods);
			break ;
		}
		else
			break ;
	}
	return (i);
}

static int	ft_parse_convs(va_list ap, t_mods *mods, int ret)
{
	char	c;

	c = mods->qualifier;
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x'
			|| c == 'X' || c == 'p' || c == 'b')
		return (ft_numb(ap, mods));
	else if (c == 'c')
		return (ft_char(ap, mods));
	else if (c == 's')
		return (ft_str(ap, mods));
	else if (c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g'
			|| c == 'G' || c == 'a' || c == 'A')
		return (ft_float(ap, mods));
	else if (c == 'n')
	{
		*va_arg(ap, int*) = ret;
		return (0);
	}
	else if (mods->qualifier)
		return (ft_no_qual(mods));
	return (0);
}

int		print(const char *format, int ret, t_mods *mods, va_list args)
{
	unsigned int	index;
	char			*tmp;

	index = 0;
	while (format[index])
	{
		if ((tmp = ft_strchr(&format[index], '%')))
		{
			ft_putstr(&format[index]);
			// write(1, &format[index], tmp - &format[index]);
			ret += tmp - &format[index];
			ft_set_mods(mods);
			index = ft_parse_mods(index + tmp - &format[index] + 1, format, mods, args);
			ret += ft_parse_convs(args, mods, ret);
		}
		else
		{
			ft_putstr(&format[index]);
			ret += ft_strlen(&format[index]);
			break ;
		}
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	t_mods	mods;
	int		ret;

	if (!format)
		return (0);
	va_start(args, format);
	ret = 0;
	if ((ret = print(format, ret, &mods, args)) < 0)
		return (-1);
	va_end(args);
	return (ret);
}
