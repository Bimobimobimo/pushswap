/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:36:02 by lcollong          #+#    #+#             */
/*   Updated: 2024/12/04 13:23:02 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_before_push(t_stack **s, t_stack *target, char c)
{
	while (*s != target)
	{
		if (c == 'a')
		{
			if (target->first_half == true)
				ft_ra(s);
			else
				ft_rra(s);
		}
		else if (c == 'b')
		{
			if (target->first_half == true)
				ft_rb(s);
			else
				ft_rrb(s);
		}
	}
}

void	ft_rotate_two(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		ft_rr(a, b);
	ft_get_index(*a);
	ft_get_index(*b);
}

void	ft_rev_rotate_two(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		ft_rrr(a, b);
	ft_get_index(*a);
	ft_get_index(*b);
}

void	ft_get_push_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_get_len(a);
	len_b = ft_get_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (a->first_half == false)
			a->push_cost = len_a - (a->index);
		if ((a->target)->first_half == true)
			a->push_cost += (a->target)->index;
		else
			a->push_cost += len_b - ((a->target)->index);
		a = a->next;
	}
}
