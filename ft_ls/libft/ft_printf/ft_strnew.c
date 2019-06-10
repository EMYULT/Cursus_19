/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 16:06:29 by tjuzen            #+#    #+#             */
/*   Updated: 2018/10/27 16:18:57 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem;

	mem = malloc(sizeof(char) * (size + 1));
	if (!mem)
		return (NULL);
	ft_bzero(mem, size + 1);
	return (mem);
}