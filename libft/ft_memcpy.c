/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 17:55:07 by oshyiata          #+#    #+#             */
/*   Updated: 2018/11/15 15:37:30 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dst_c;
	unsigned char *src_c;

	dst_c = (unsigned char*)dst;
	src_c = (unsigned char*)src;
	if (dst == src)
		return (dst);
	while (n--)
		*dst_c++ = *src_c++;
	return (dst);
}
