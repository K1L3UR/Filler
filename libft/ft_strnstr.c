/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalced <lasalced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:12:46 by lasalced          #+#    #+#             */
/*   Updated: 2015/01/24 21:22:28 by lasalced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	tmp = (char *)s1;
	if (!s2 || !*s2)
		return (tmp);
	if (s1)
	{
		while (s1[i])
		{
			j = 0;
			while (s1[i] != '\0' && s1[i] == s2[j] && i < n)
			{
				i++;
				j++;
			}
			if (s2[j] == '\0')
				return (tmp + (i - ft_strlen(s2)));
			i = i - j;
			i++;
		}
	}
	return (NULL);
}
