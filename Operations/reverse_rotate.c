/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:02:08 by lcollong          #+#    #+#             */
/*   Updated: 2024/12/02 13:25:26 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rev_rotate(t_stack **lst)
{
	t_stack	*last;

	if (!(*lst)->next || !*lst || !lst)
		return ;
	last = ft_lstlast(*lst);
	(last->prev)->next = NULL;
	last->next = *lst;
	last->prev = NULL;
	*lst = last;
	(last->next)->prev = last;
}

void	ft_rra(t_stack **a)
{
	ft_rev_rotate(a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b)
{
	ft_rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	write(1, "rrr\n", 4);
}
