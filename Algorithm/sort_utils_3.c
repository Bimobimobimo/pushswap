/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:27:39 by lcollong          #+#    #+#             */
/*   Updated: 2024/12/03 15:59:59 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_get_cheapest(t_stack *s)
{
	long	cheapest_cost;
	t_stack	*cheapest_node;

	if (!s)
		return ;
	cheapest_cost = LONG_MAX;
	while (s)
	{
		if (s->push_cost < cheapest_cost)
		{
			cheapest_cost = s->push_cost;
			cheapest_node = s;
		}
		s = s->next;
	}
	cheapest_node->cheapest = true;
}

t_stack	*ft_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
