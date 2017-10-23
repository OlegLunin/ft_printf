/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olunin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:08:10 by olunin            #+#    #+#             */
/*   Updated: 2016/12/06 15:22:35 by olunin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t index;

	index = 0;
	if (s && f)
	{
		while (s[index])
		{
			(*f)(&(s[index]));
			index++;
		}
	}
}
