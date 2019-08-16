/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 14:45:48 by tjuzen            #+#    #+#             */
/*   Updated: 2018/10/29 18:14:23 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		n;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	n = ft_strlen(s) - 1;
	while ((s[i] == ' ') || (s[i] == ',') || (s[i] == '\n') || (s[i] == '\t'))
		i++;
	if (i == n + 1)
	{
		str = ft_strdup("");
		return (str);
	}
	while ((s[n] == ' ') || (s[n] == ',') || (s[n] == '\n') || (s[n] == '\t'))
		n--;
	n = n - i + 1;
	str = ft_strsub(s, i, n);
	return (str);
}
