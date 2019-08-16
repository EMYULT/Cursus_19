/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:26:41 by tjuzen            #+#    #+#             */
/*   Updated: 2019/03/28 15:26:42 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_itoa_base_unsigned(unsigned long long n, int base)
{
	char				*s;
	unsigned long long	nb;
	long long			len;

	len = 1;
	nb = n;
	while (nb >= (unsigned long long)base)
	{
		nb /= base;
		++len;
	}
	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s[len] = '\0';
	while (n >= (unsigned long long)base)
	{
		s[--len] = n % base < 10 ? (n % base) + 48 : (n % base) + 55;
		n /= base;
	}
	s[--len] = n % base < 10 ? (n % base) + 48 : (n % base) + 55;
	return (s);
}

char	*ft_itoa_unsigned(unsigned long long int n)
{
	unsigned long long	nb;
	char				*str;
	int					len;

	len = 1;
	nb = n;
	while (nb > 9)
	{
		nb /= 10;
		++len;
	}
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	while (n > 9)
	{
		str[--len] = n % 10 + '0';
		n = n / 10;
	}
	str[--len] = n + '0';
	return (str);
}

char	*ft_itoa_base(long long n, int base)
{
	char		*s;
	long long	nb;
	int			len;

	len = 1;
	n < 0 ? ++len : 0;
	nb = n < 0 ? -n : n;
	while (nb >= base)
	{
		nb /= base;
		++len;
	}
	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s[len] = '\0';
	n < 0 ? *s = '-' : 0;
	n < 0 ? n = -n : 0;
	while (n >= base)
	{
		s[--len] = n % base < 10 ? (n % base) + 48 : (n % base) + 55;
		n /= base;
	}
	s[--len] = n % base < 10 ? (n % base) + 48 : (n % base) + 55;
	return (s);
}

int		ft_atoi_sub(const char *str, int start, int len)
{
	int					i;
	unsigned long long	nb;
	int					neg;

	i = start;
	nb = 0;
	neg = 0;
	while (((i - start) < len) && ((str[i] == ' ') || (str[i] == '\t') ||
	(str[i] == '\v') || (str[i] == '\n') || (str[i] == '\r') ||
	(str[i] == '\f')))
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9') && ((i - start) < len))
	{
		nb = nb * 10;
		nb = nb + (str[i] - '0');
		i++;
	}
	if (nb > 9223372036854775807)
		return ((neg == 1) ? 0 : -1);
	return (((neg == 1)) ? ((int)-nb) : ((int)nb));
}

int		ft_atoi(const char *str)
{
	int					i;
	unsigned long long	nb;
	int					neg;

	i = 0;
	nb = 0;
	neg = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\v')
			|| (str[i] == '\n') || (str[i] == '\r') || (str[i] == '\f'))
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nb = nb * 10;
		nb = nb + (str[i] - '0');
		i++;
	}
	if (nb > 9223372036854775807)
		return ((neg == 1) ? 0 : -1);
	if (neg == 1)
		return ((int)-nb);
	return ((int)nb);
}
