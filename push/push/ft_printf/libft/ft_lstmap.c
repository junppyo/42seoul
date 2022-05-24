/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:19:02 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/13 19:54:17 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), int (*del)(int))
{
	t_list	*new;
	t_list	*ret;

	new = malloc(sizeof(t_list));
	if (new == NULL || lst == NULL || del == NULL)
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
			return (0);
		}
		new = new->next;
		new->content = f(lst->content);
		new->next = NULL;
	}
	return (ret);
}
