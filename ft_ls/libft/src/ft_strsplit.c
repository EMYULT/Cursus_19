/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 14:46:40 by tjuzen            #+#    #+#             */
/*   Updated: 2018/10/28 17:28:15 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	size_t	count_len(char const *s, char c, size_t b)
{
	size_t j;

	j = 0;
	while (s[b] == c)
		b++;
	while ((s[b]) && (s[b] != c))
	{
		b++;
		j++;
	}
	return (j);
}

static	size_t	count(char const *s, char c)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if ((s[i] != c) && (s[i] != '\0'))
			j++;
		while ((s[i]) && (s[i] != c))
			i++;
	}
	return (j);
}

static	size_t	start(char const *s, char c, size_t b)
{
	while (s[b] == c)
		b++;
	return (b);
}

static void		*ft_free(char **str, size_t x)
{
	while (x--)
		free(str[x]);
	free(str);
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	x;
	size_t	z;
	size_t	b;
	size_t	a;
	char	**str;

	if (!s || !c)
		return (NULL);
	x = 0;
	b = 0;
	a = count(s, c);
	if (!(str = malloc(sizeof(*str) * (a + 1))))
		return (NULL);
	while (x < a)
	{
		b = start(s, c, b);
		z = count_len(s, c, b);
		if (!(str[x] = ft_strsub(s, b, z)))
			return (ft_free(str, x));
		while (z--)
			b++;
		x++;
	}
	str[x] = NULL;
	return (str);
}
