/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:59:30 by tjuzen            #+#    #+#             */
/*   Updated: 2018/10/27 16:02:08 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dest;
	if (dest > src)
	{
		while (len)
		{
			s2[len - 1] = s1[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(s2, s1, len);
	return ((unsigned char *)dest);
}
