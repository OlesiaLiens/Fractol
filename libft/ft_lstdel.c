/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:06:15 by oshyiata          #+#    #+#             */
/*   Updated: 2018/11/16 13:23:01 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*next_1;

	if (alst && del)
	{
		next_1 = *alst;
		while (next_1 != NULL)
		{
			next = next_1->next;
			(*del)(next_1->content, next_1->content_size);
			free(next_1);
			next_1 = next;
		}
		*alst = NULL;
	}
}
