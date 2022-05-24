/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:08:06 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/18 18:04:26 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list **lst)
{
	int		cnt;
	t_list	*tmp;

	tmp = *lst;
	if (*lst == NULL)
		return (0);
	cnt = 1;
	while (tmp->next != *lst)
	{
		tmp = tmp->next;
		cnt++;
	}
	return (cnt);
}
