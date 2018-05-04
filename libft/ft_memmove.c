/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalced <lasalced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:12:46 by lasalced          #+#    #+#             */
/*   Updated: 2015/10/05 18:48:40 by lasalced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	tmp_src = (unsigned char *)src;
	tmp_dst = (unsigned char *)dst;
	i = 0;
	if (tmp_src < tmp_dst)
	{
		tmp_dst += len;
		tmp_src += len;
		while (len--)
			*--tmp_dst = *--tmp_src;
	}
	else
	{
		while (i < len)
		{
			*tmp_dst = *tmp_src;
			tmp_src++;
			tmp_dst++;
			i++;
		}
	}
	return (dst);
}
