/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:16:15 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/09/07 18:41:26 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin_free(char *s1, char *s2, size_t i)
{
	char	*join;
	size_t	k;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	k = (ft_strlen(s1) + ft_strlen(s2));
	if (!(join = ft_strnew(k)))
		return (NULL);
	ft_strcpy(join, s1);
	ft_strcat(join, s2);
	if (i == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	if (i == 2)
		ft_strdel(&s2);
	if (i == 1)
		ft_strdel(&s1);
	return (join);
}
