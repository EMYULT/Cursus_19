/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 16:59:36 by tjuzen            #+#    #+#             */
/*   Updated: 2018/11/09 17:49:13 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	if (*n == '\0')
		return ((char *)h);
	if (!(*n))
		return ((char *)h);
	while (*h && len-- >= ft_strlen(n))
	{
		if (*h == *n && ft_memcmp(h, n, ft_strlen(n)) == 0)
			return ((char *)h);
		h++;
	}
	return (NULL);
}
