/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:00:59 by tjuzen            #+#    #+#             */
/*   Updated: 2018/10/27 15:47:27 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*start;
	const char	*sub;
	char		*ret;

	if (!(*needle))
		return ((char *)haystack);
	while (*haystack)
	{
		start = haystack;
		sub = needle;
		while (*haystack && *sub && *haystack == *sub)
		{
			haystack++;
			sub++;
		}
		if (*sub == 0)
		{
			ret = ((char *)start);
			return (ret);
		}
		haystack = start + 1;
	}
	return (NULL);
}
