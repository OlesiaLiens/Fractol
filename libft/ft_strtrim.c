/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:36:21 by oshyiata          #+#    #+#             */
/*   Updated: 2018/11/18 14:20:49 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;
	int		res;

	if (!s)
		return (0);
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	len = ft_strlen(s);
	while (len != 1
			&& (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n'))
		len--;
	res = len - i;
	if (res <= 0)
		return (ft_memalloc(sizeof(char)));
	return (ft_strsub(s, i, (size_t)res));
}
