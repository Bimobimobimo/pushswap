/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:01:22 by lcollong          #+#    #+#             */
/*   Updated: 2024/12/02 12:06:43 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate(t_stack **lst)
{
	t_stack	*last;

	if (!*lst || !(*lst)->next || !lst)
		return ;
	last = ft_lstlast(*lst);
	last->next = *lst;
	*lst = (*lst)->next;
	(*lst)->prev = NULL;
	(last->next)->prev = last;
	(last->next)->next = NULL;
}

void	ft_ra(t_stack **lst)
{
	ft_rotate(lst);
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack **lst)
{
	ft_rotate(lst);
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}
