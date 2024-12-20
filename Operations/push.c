/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:08:21 by lcollong          #+#    #+#             */
/*   Updated: 2024/12/02 11:20:15 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->prev = NULL;
	if (!*dest)
	{
		*dest = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = *dest;
		(tmp->next)->prev = tmp;
		*dest = tmp;
	}
}

void	ft_pa(t_stack **a, t_stack **b)
{
	ft_push(b, a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	write(1, "pb\n", 3);
}
