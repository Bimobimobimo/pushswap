/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:59:30 by lcollong          #+#    #+#             */
/*   Updated: 2024/12/02 11:21:02 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_stack **lst)
{
	int	tmp;

	if (!*lst || !(*lst)->next || !lst)
		return ;
	tmp = (*lst)->value;
	(*lst)->value = ((*lst)->next)->value;
	((*lst)->next)->value = tmp;
}

void	ft_sa(t_stack **a)
{
	ft_swap(a);
	write (1, "sa\n", 3);
}

void	ft_sb(t_stack **b)
{
	ft_swap(b);
	write (1, "sb\n", 3);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
	write (1, "ss\n", 3);
}
