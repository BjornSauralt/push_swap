/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarsaul <mgarsaul@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-17 13:46:51 by mgarsaul          #+#    #+#             */
/*   Updated: 2024-12-17 13:46:51 by mgarsaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct t_noeud
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct t_noeud		*target_node;
	struct t_noeud		*next;
	struct t_noeud		*prev;
}	t_noeud;

int			error_syntax(char *str_n);
int			error_duplicate(t_noeud *a, int n);
void		free_stack(t_noeud **stack);
void		free_errors(t_noeud **a);
void		free_split(char **split);

void		init_stack_a(t_noeud **a, char **argv);
char		**ft_split(char *s, char c);

void		init_nodes_a(t_noeud *a, t_noeud *b);
void		init_nodes_b(t_noeud *a, t_noeud *b);
void		current_index(t_noeud *stack);
void		set_cheapest(t_noeud *stack);
t_noeud		*get_cheapest(t_noeud *stack);
void		prep_for_push(t_noeud **s, t_noeud *n, char c);

int			stack_len(t_noeud *stack);
t_noeud		*find_last(t_noeud *stack);
bool		stack_sorted(t_noeud *stack);
t_noeud		*find_min(t_noeud *stack);
t_noeud		*find_max(t_noeud *stack);

//***Commands
void		sa(t_noeud **a, bool print);
void		sb(t_noeud **b, bool print);
void		ss(t_noeud **a, t_noeud **b, bool print);
void		ra(t_noeud **a, bool print);
void		rb(t_noeud **b, bool print);
void		rr(t_noeud **a, t_noeud **b, bool print);
void		rra(t_noeud **a, bool print);
void		rrb(t_noeud **b, bool print);
void		rrr(t_noeud **a, t_noeud **b, bool print);
void		pa(t_noeud **a, t_noeud **b, bool print);
void		pb(t_noeud **b, t_noeud **a, bool print);

//***Algorithm
void		sort_three(t_noeud **a);
void		sort_stacks(t_noeud **a, t_noeud **b);

void		move_a_to_b(t_noeud **a, t_noeud **b);
void		rotate_both(t_noeud **a, t_noeud **b, t_noeud *cheapest_node);
void		rev_rotate_both(t_noeud **a, t_noeud **b, t_noeud *cheapest_node);
void		swap(t_noeud **head);
void		push(t_noeud **dst, t_noeud **src);
void		set_target_a(t_noeud *a, t_noeud *b);
void		set_target_b(t_noeud *a, t_noeud *b);
void		cost_analysis_a(t_noeud *a, t_noeud *b);
void		move_b_to_a(t_noeud **a, t_noeud **b);
void		min_on_top(t_noeud **a);
void		append_node(t_noeud **stack, int n);

#endif