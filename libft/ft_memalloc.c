/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:21:03 by oshyiata          #+#    #+#             */
/*   Updated: 2018/11/15 17:53:44 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*res;

	if (size == 0)
		return (0);
	res = (void *)malloc(sizeof(void) * size);
	if (res == NULL)
		return (0);
	ft_bzero(res, size);
	return ((void *)res);
}
