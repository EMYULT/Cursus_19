/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 14:47:04 by tjuzen            #+#    #+#             */
/*   Updated: 2018/10/28 17:04:42 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		is_neg(long long int *n, char **str)
{
	if (*n < 0)
	{
		**str = '-';
		*n = -*n;
	}
}

char			*ft_itoa(long long int n)
{
	long long int		nb;
	char				*str;
	int					neg;
	int					len;

	len = (n < 0) ? 2 : 1;
	nb = (n < 0) ? -n : n;
	neg = 0;
	while (nb > 9)
	{
		nb /= 10;
		++len;
	}
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	is_neg(&n, &str);
	while (n > 9)
	{
		str[--len] = n % 10 + '0';
		n = n / 10;
	}
	str[--len] = n + '0';
	return (str);
}
