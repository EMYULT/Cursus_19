/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 14:44:41 by tjuzen            #+#    #+#             */
/*   Updated: 2018/11/22 10:45:51 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned long	j;
	unsigned long	l;

	if (s1 == NULL || s2 == NULL || \
			(!(str = ft_strnew((ft_strlen(s1)) + (ft_strlen(s2))))))
		return (NULL);
	j = 0;
	l = 0;
	while (j != (ft_strlen(s1)))
	{
		str[j] = s1[j];
		j++;
	}
	while (j != (ft_strlen(s1)) + (ft_strlen(s2)))
		str[j++] = s2[l++];
	return (str);
}
