/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:00:15 by lcollong          #+#    #+#             */
/*   Updated: 2024/12/05 15:27:15 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_cost;
	bool				first_half;
	bool				cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack;

//* ~ PARAMETERS ~
// Filling stack a :
void	ft_fill_a(t_stack **a, char **argv);
void	ft_fill_a2(t_stack **a, char *argv);
int		ft_syntax_error(char *str);
int		ft_doubles(t_stack *a, int nb);
void	ft_param_error2(t_stack **a);
void	ft_param_error(t_stack **a, char **argv);
void	ft_add_node(t_stack **stack, int nb);
int		ft_tab_len(char **tab);
// Split :
char	**ft_split(char const *s, char c);
int		ft_count_words(const char *str, char c);
char	*ft_tab_lign(const char *s, char c);
void	ft_free_tab(char **tab, int j);

//* ~ ALGORITHM ~
// Sorting
void	ft_pre_sort(t_stack **a, t_stack *b);
void	ft_sort_three(t_stack **a);
void	ft_move_atob(t_stack **a, t_stack **b);
void	ft_move_btoa(t_stack **a, t_stack **b);
void	ft_ascending_order(t_stack **a);
void	ft_sorting_algo(t_stack **a, t_stack **b);
// Sorting Utils
int		ft_is_sorted(t_stack *a);
void	ft_get_target_a(t_stack *a, t_stack *b);
void	ft_get_target_b(t_stack *a, t_stack *b);
void	ft_prepare_a(t_stack *a, t_stack *b);
void	ft_prepare_b(t_stack *a, t_stack *b);
void	ft_get_cheapest(t_stack *s);
t_stack	*ft_cheapest(t_stack *stack);
void	ft_before_push(t_stack **s, t_stack *target, char c);
void	ft_rotate_two(t_stack **a, t_stack **b, t_stack *cheapest);
void	ft_rev_rotate_two(t_stack **a, t_stack **b, t_stack *cheapest);
void	ft_get_push_cost(t_stack *a, t_stack *b);

//* ~ ANNEXES ~
// Ft_get_...
void	ft_get_index(t_stack *a);
t_stack	*ft_get_min(t_stack *a);
t_stack	*ft_get_max(t_stack *a);
int		ft_get_len(t_stack *a);
// Utils
t_stack	*ft_lstlast(t_stack *a);
void	ft_lstclear(t_stack **a);
long	ft_atol(const char *str);
int		ft_isdigit(char c);

//* ~ OPERATIONS ~
void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);
void	ft_push(t_stack **pile1, t_stack **pile2);
void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_swap(t_stack **lst);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_rotate(t_stack **lst);
void	ft_ra(t_stack **lst);
void	ft_rb(t_stack **lst);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rev_rotate(t_stack **lst);
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);

#endif
