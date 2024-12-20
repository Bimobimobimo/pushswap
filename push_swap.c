/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:00:09 by lcollong          #+#    #+#             */
/*   Updated: 2024/12/03 18:18:02 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pre_sort(t_stack **a, t_stack *b)
{
	if (ft_get_len(*a) == 2)
		ft_sa(a);
	else if (ft_get_len(*a) == 3)
		ft_sort_three(a);
	else
		ft_sorting_algo(a, &b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**param_tab;
	int		i;

	i = 0;
	a = NULL;
	b = NULL;
	param_tab = NULL;
	if (argc == 1)
		return (1);
	else if (argc == 2)
	{
		param_tab = ft_split(argv[1], ' ');
		ft_fill_a(&a, param_tab);
		ft_free_tab(param_tab, ft_get_len(a));
	}
	else if (argc > 2)
		while (argv[++i])
			ft_fill_a2(&a, argv[i]);
	if (!ft_is_sorted(a))
		ft_pre_sort(&a, b);
	ft_lstclear(&a);
	return (0);
}
