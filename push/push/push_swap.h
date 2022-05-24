/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:11:21 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/22 17:07:12 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"

void	s(t_list **l);
void	p(t_list **l1, t_list **l2);
void	r(t_list **l);
void	rr(t_list **l);

int		is_min_max(t_list **l, int n);
int		get_cnt(int cnt_a, int cnt_b);
void	do_oper(t_list **l, int cnt);
int		calculate_a(t_list **l, int a);
int		calculate_b(t_list **l, int n);
void	before_push(t_list **a, t_list **b, int size);
int		find_element(t_list **a, t_list **b, int size);
void	after_push(t_list **l);

int		find_min(t_list **l);
void	sort_b(t_list **l);
int		find_max_loc(t_list **l);

void	sort_2(t_list **l);
void	sort_3(t_list **l);
void	sort_4(t_list **a, t_list **b);
void	sort_5(t_list **a, t_list **b);
void	sort(t_list **a, t_list **b);

void	free_all(long long *num_list, char **split_str, int cnt);
int		split_init(char *s, char ***split_str, long long **num_list);
int		list_split(char *s, t_list **l);
void	make_index(t_list **l);

int		sorted(t_list *l);
int		chk_dup(t_list *l);
int		chk_arg(char *s);
int		chk_int(long long n);
#endif
