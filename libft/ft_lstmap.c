/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:35:52 by oshyiata          #+#    #+#             */
/*   Updated: 2018/11/11 18:08:49 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list *new;
	t_list *begin;

	begin = NULL;
	if (lst && f)
	{
		new = f(lst);
		begin = new;
		lst = lst->next;
		while (lst && f)
		{
			new->next = f(lst);
			new = new->next;
			lst = lst->next;
		}
	}
	return (begin);
}
