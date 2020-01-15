/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:01:12 by oshyiata          #+#    #+#             */
/*   Updated: 2018/11/17 12:56:59 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (s && *s)
	{
		res = (char *)malloc(sizeof(char) * (len + 1));
		if (res == NULL)
			return (NULL);
		res[len] = '\0';
		res = ft_strncpy(res, &s[start], len);
		return (res);
	}
	return (NULL);
}
