/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olunin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:18:37 by olunin            #+#    #+#             */
/*   Updated: 2016/12/06 15:48:16 by olunin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s && (*s != (char)c))
		s++;
	if (*s != (char)c)
		return (NULL);
	return ((char *)s);
}
