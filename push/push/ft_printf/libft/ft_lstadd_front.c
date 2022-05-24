/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:06:30 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/18 17:38:12 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst != NULL)
	{
		ft_lstlast(lst)->next = new;
		new->pre = (*lst)->pre;
		(*lst)->pre = new;
		new->next = *lst;
	}
	else
	{
		new->pre = new;
		new->next = new;
	}
	*lst = new;
}
