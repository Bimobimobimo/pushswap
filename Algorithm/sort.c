/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:26:41 by lcollong          #+#    #+#             */
/*   Updated: 2024/12/03 17:51:28 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_three(t_stack **a)
{
	if ((*a)->value > ((*a)->next)->value)
	{
		if (((*a)->next)->value > ft_lstlast(*a)->value)
		{
			ft_sa(a);
			ft_rra(a);
		}
		else if ((*a)->value > ft_lstlast(*a)->value)
			ft_ra(a);
		else
			ft_sa(a);
	}
	else if ((*a)->value < ((*a)->next)->value)
	{
		if ((*a)->value < ft_lstlast(*a)->value)
		{
			ft_sa(a);
			ft_ra(a);
		}
		else
			ft_rra(a);
	}
}

void	ft_move_atob(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = ft_cheapest(*a);
	if (cheapest->first_half == true && (cheapest->target)->first_half == true)
		ft_rotate_two(a, b, cheapest);
	else if (cheapest->first_half == false
		&& (cheapest->target)->first_half == false)
		ft_rev_rotate_two(a, b, cheapest);
	ft_before_push(a, cheapest, 'a');
	ft_before_push(b, cheapest->target, 'b');
	ft_pb(a, b);
}

void	ft_move_btoa(t_stack **a, t_stack **b)
{
	ft_before_push(a, (*b)->target, 'a');
	ft_pa(a, b);
}

void	ft_ascending_order(t_stack **a)
{
	while ((*a)->value != (ft_get_min(*a))->value)
	{
		if ((ft_get_min(*a))->first_half == true)
			ft_ra(a);
		else
			ft_rra(a);
	}
}

void	ft_sorting_algo(t_stack **a, t_stack **b)
{
	int	stack_len;

	stack_len = ft_get_len(*a);
	if (stack_len-- > 3 && !ft_is_sorted(*a))
		ft_pb(a, b);
	if (stack_len-- > 3 && !ft_is_sorted(*a))
		ft_pb(a, b);
	while (stack_len > 3 && !ft_is_sorted(*a))
	{
		ft_prepare_a(*a, *b);
		ft_move_atob(a, b);
		stack_len--;
	}
	if (!ft_is_sorted(*a))
		ft_sort_three(a);
	while (*b)
	{
		ft_prepare_b(*a, *b);
		ft_move_btoa(a, b);
	}
	ft_get_index(*a);
	ft_ascending_order(a);
}
