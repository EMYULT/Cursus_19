/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:32:40 by tjuzen            #+#    #+#             */
/*   Updated: 2018/11/22 10:45:34 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*string;
	char	*duplicate_string;

	if (!(string = ft_strnew(ft_strlen(s))))
		return (NULL);
	duplicate_string = string;
	while (*s)
	{
		*duplicate_string = *s;
		duplicate_string++;
		s++;
	}
	*duplicate_string = '\0';
	return (string);
}
