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

# include <stdbool.h>
# include <limits.h>
# include "../libft/includes/libft.h"

typedef struct s_noeud
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_noeud	*target_noeud;
	struct s_noeud	*next;
	struct s_noeud	*prev;
}	t_noeud;

void		current_index(t_noeud *stack);
static void	set_target_a(t_noeud *a, t_noeud *b);
static void	cost_analysis_a(t_noeud *a, t_noeud *b);
void		set_cheapest(t_noeud *stack);
void		init_nodes_a(t_noeud *a, t_noeud *b);
static void	set_target_b(t_noeud *a, t_noeud *b);
void		init_nodes_b(t_noeud *a, t_noeud *b);
static void	append_node(t_noeud **stack, int n);
void		init_stack_a(t_noeud **a, char **argv);
t_noeud		*get_cheapest(t_noeud *stack);
void		prep_for_push(t_noeud **stack, t_noeud *top_node, char stack_name);
int			main(int argc, char **argv);
void		tri_pile(t_noeud **a, t_noeud **b);
static void	move_b_to_a(t_noeud **a, t_noeud **b);
static void	min_on_top(t_noeud **a);
static void	move_a_to_b(t_noeud **a, t_noeud **b);
static void	swap(t_noeud **head);
static void	push(t_noeud **dst, t_noeud **src);
void		pa(t_noeud **a, t_noeud **b, bool print);
void		pb(t_noeud **a, t_noeud **b, bool print);
void		sa(t_noeud **a, bool print);
void		sb(t_noeud **b, bool print);
void		ss(t_noeud **a, t_noeud **b, bool print);
static void	reverse_rotate(t_noeud **stack);
static void	reverse_rotate_both(t_noeud **a, t_noeud **b, t_noeud *cheapest);
void		rra(t_noeud **a, bool print);
void		rrb(t_noeud **b, bool print);
void		rrr(t_noeud **a, t_noeud **b, bool print);
static void	rotate(t_noeud **stack);
static void	rotate_both(t_noeud **a, t_noeud **b, t_noeud *cheapest);
void		ra(t_noeud **a, bool print);
void		rb(t_noeud **b, bool print);
void		rr(t_noeud **a, t_noeud **b, bool print);
void		tri_three(t_noeud **a);
int			stack_len(t_noeud *stack);
t_noeud		*find_last(t_noeud *stack);
bool		stack_sorted(t_noeud *stack);
t_noeud		*find_min(t_noeud *stack);
t_noeud		*find_max(t_noeud *stack);
int			error_syntax(char *str_n);
int			error_duplicate(t_noeud *a, int n);
void		free_stack(t_noeud **stack);
void		free_errors(t_noeud **a);

#endif