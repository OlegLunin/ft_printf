/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olunin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:40:26 by olunin            #+#    #+#             */
/*   Updated: 2016/11/30 20:19:58 by olunin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	ft_memdel(void **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
