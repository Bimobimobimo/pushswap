/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:59:14 by lcollong          #+#    #+#             */
/*   Updated: 2024/12/05 15:24:54 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_syntax_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] != '+' && str[0] != '-' && !ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_doubles(t_stack *a, int nb)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == nb)
			return (1);
		a = a->next;
	}
	return (0);
}

void	ft_param_error(t_stack **a, char **argv)
{
	t_stack	*tmp;
	t_stack	*node;

	ft_free_tab(argv, ft_tab_len(argv));
	if (!a)
		exit (1);
	node = *a;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*a = NULL;
	write (2, "Error\n", 6);
	exit (1);
}

void	ft_param_error2(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*node;

	if (!a)
		exit (1);
	node = *a;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*a = NULL;
	write (2, "Error\n", 6);
	exit (1);
}

int	ft_tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i + 1);
}
