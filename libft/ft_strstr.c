/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:48:22 by oshyiata          #+#    #+#             */
/*   Updated: 2018/11/06 15:22:15 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t len;
	size_t ind;
	size_t pos;

	len = 0;
	ind = 0;
	pos = 0;
	while (needle[len])
		len++;
	if (len == 0)
		return ((char *)haystack);
	while (haystack[ind])
	{
		while (needle[pos] == haystack[ind + pos])
		{
			if (pos == len - 1)
				return ((char *)haystack + ind);
			pos++;
		}
		pos = 0;
		ind++;
	}
	return (NULL);
}
