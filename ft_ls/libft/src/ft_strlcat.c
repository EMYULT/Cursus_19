/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:08:15 by tjuzen            #+#    #+#             */
/*   Updated: 2018/10/27 16:22:37 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;

	dst_size = ft_strlen(dst);
	if (dst_size >= size)
		return (size + ft_strlen(src));
	while ((dst_size < size - 1) && *src)
		dst[dst_size++] = *src++;
	dst[dst_size] = '\0';
	return (ft_strlen(src) + ft_strlen(dst));
}
