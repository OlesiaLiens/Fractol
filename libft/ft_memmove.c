/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 17:02:25 by oshyiata          #+#    #+#             */
/*   Updated: 2018/11/06 15:06:35 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			offset;
	unsigned char	*dst_c;
	unsigned char	*src_c;

	offset = 0;
	dst_c = (unsigned char*)dst;
	src_c = (unsigned char*)src;
	if (dst_c < src_c)
		while (len--)
		{
			*(dst_c + offset) = *(src_c + offset);
			offset++;
		}
	else
		while (len--)
			dst_c[len] = src_c[len];
	return (dst_c);
}
