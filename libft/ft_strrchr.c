/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:43:42 by oshyiata          #+#    #+#             */
/*   Updated: 2018/11/15 16:56:12 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrchr(const char *str, int ch)
{
	const	char	*a;
	char			ch_1;

	a = str;
	ch_1 = (char)ch;
	while (*str++)
	{
		if (*str == ch_1)
			a = str;
	}
	if (*a == ch_1)
		return ((char *)a);
	else
		return (NULL);
}
