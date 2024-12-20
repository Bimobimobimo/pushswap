/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:18:21 by lcollong          #+#    #+#             */
/*   Updated: 2024/12/05 15:25:31 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_fill_a(t_stack **a, char **argv)
{
	long	nb;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (ft_syntax_error(argv[i]))
			ft_param_error(a, argv);
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_param_error(a, argv);
		if (ft_doubles(*a, (int)nb))
			ft_param_error(a, argv);
		ft_add_node(a, (int)nb);
		i++;
	}
}

void	ft_fill_a2(t_stack **a, char *argv)
{
	long	nb;

	if (argv[0] == '\0')
		ft_param_error2(a);
	if (ft_syntax_error(argv))
		ft_param_error2(a);
	nb = ft_atol(argv);
	if (nb > INT_MAX || nb < INT_MIN)
		ft_param_error2(a);
	if (ft_doubles(*a, (int)nb))
		ft_param_error2(a);
	ft_add_node(a, (int)nb);
}

void	ft_add_node(t_stack **a, int nb)
{
	t_stack	*new;
	t_stack	*last;

	if (!a)
		return ;
	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return ;
	new->next = NULL;
	new->value = nb;
	if (!(*a))
	{
		*a = new;
		new->prev = NULL;
	}
	else
	{
		last = ft_lstlast(*a);
		last->next = new;
		new->prev = last;
	}
}
