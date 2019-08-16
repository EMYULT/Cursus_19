/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:46:44 by tjuzen            #+#    #+#             */
/*   Updated: 2018/10/29 15:41:06 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *s;

	s = NULL;
	while (*str)
	{
		if (*str == c)
			s = (char *)str;
		str++;
	}
	if (*str == c)
		s = (char *)str;
	return (s);
}
