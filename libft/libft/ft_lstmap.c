/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:19:02 by junpkim           #+#    #+#             */
/*   Updated: 2022/03/14 21:00:46 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*ret;

	new = malloc(sizeof(t_list));
	if (new == NULL || lst == NULL)
		return (0);
	ret = new;
	new->content = f(lst->content);
	new->next = NULL;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new->next = malloc(sizeof(t_list));
		if (new->next == NULL)
		{
			ft_lstclear(&ret, del);
			return (0);
		}
		new = new->next;
		new->content = f(lst->content);
		new->next = NULL;
	}
	return (ret);
}
