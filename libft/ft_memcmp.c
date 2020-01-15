/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 18:13:09 by oshyiata          #+#    #+#             */
/*   Updated: 2018/11/17 12:08:31 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	const unsigned char *arr1_1 = (const unsigned char*)arr1;
	const unsigned char *arr2_2 = (const unsigned char*)arr2;
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (arr1_1[i] != arr2_2[i])
			return ((unsigned char)arr1_1[i] - (unsigned char)arr2_2[i]);
		i++;
	}
	return (0);
}
