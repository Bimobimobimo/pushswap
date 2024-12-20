/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:39:57 by lcollong          #+#    #+#             */
/*   Updated: 2024/12/02 12:06:22 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_get_index(t_stack *a)
{
	int	i;
	int	middle;

	i = 0;
	if (!a)
		return ;
	middle = ft_get_len(a) / 2;
	while (a)
	{
		a->index = i;
		if (i <= middle)
			a->first_half = true;
		else
			a->first_half = false;
		a = a->next;
		i++;
	}
}

t_stack	*ft_get_min(t_stack *a)
{
	t_stack	*min;

	if (!a)
		return (NULL);
	min = a;
	while (a)
	{
		if (min->value > a->value)
			min = a;
		a = a->next;
	}
	return (min);
}

t_stack	*ft_get_max(t_stack *a)
{
	t_stack	*max;

	if (!a)
		return (NULL);
	max = a;
	while (a)
	{
		if (max->value < a->value)
			max = a;
		a = a->next;
	}
	return (max);
}

int	ft_get_len(t_stack *a)
{
	int	len;

	len = 0;
	if (!a)
		return (0);
	while (a)
	{
		a = a->next;
		len++;
	}
	return (len);
}
