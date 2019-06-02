/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:32:40 by tjuzen            #+#    #+#             */
/*   Updated: 2018/11/26 14:16:34 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		original_size;
	int		i;
	char	*duplicate_string;

	original_size = ft_strlen(s);
	i = 0;
	duplicate_string = (char *)malloc(sizeof(char) * (original_size + 1));
	if (duplicate_string == NULL)
		return (NULL);
	while (i < original_size && *s)
	{
		duplicate_string[i] = s[i];
		i++;
	}
	duplicate_string[i] = '\0';
	return (duplicate_string);
}
