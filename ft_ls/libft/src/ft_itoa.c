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

#include "../includes/libft.h"

static int		intlen(int n)
{
	int i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void		isneg(int *n, int *neg)
{
	if (*n < 0)
	{
		*n = *n * -1;
		*neg = 1;
	}
}

char			*ft_itoa(int n)
{
	int		i;
	char	*nb;
	int		neg;
	int		len;

	i = 0;
	neg = 0;
	len = intlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	isneg(&n, &neg);
	len = len + neg;
	nb = ft_strnew(len);
	if (!(nb))
		return (NULL);
	while (len-- > 0)
	{
		nb[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg == 1)
		nb[0] = '-';
	return (nb);
}
