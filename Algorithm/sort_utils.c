/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:08:02 by lcollong          #+#    #+#             */
/*   Updated: 2024/12/02 13:46:36 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	ft_get_target_a(t_stack *a, t_stack *b)
{
	t_stack	*target;
	t_stack	*tmp;
	long	target_nb;

	while (a)
	{
		target_nb = LONG_MIN;
		tmp = b;
		while (tmp)
		{
			if (tmp->value < a->value && tmp->value > target_nb)
			{
				target_nb = tmp->value;
				target = tmp;
			}
			tmp = tmp->next;
		}
		if (target_nb == LONG_MIN)
			a->target = ft_get_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	ft_get_target_b(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	t_stack	*target;
	long	target_i;

	while (b)
	{
		target_i = LONG_MAX;
		tmp = a;
		while (tmp)
		{
			if (tmp->value > b->value && tmp->value < target_i)
			{
				target_i = tmp->value;
				target = tmp;
			}
			tmp = tmp->next;
		}
		if (target_i == LONG_MAX)
			b->target = ft_get_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	ft_prepare_a(t_stack *a, t_stack *b)
{
	ft_get_index(a);
	ft_get_index(b);
	ft_get_target_a(a, b);
	ft_get_push_cost(a, b);
	ft_get_cheapest(a);
}

void	ft_prepare_b(t_stack *a, t_stack *b)
{
	ft_get_index(a);
	ft_get_index(b);
	ft_get_target_b(a, b);
}
