/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarsaul <mgarsaul@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-17 14:46:29 by mgarsaul          #+#    #+#             */
/*   Updated: 2024-12-17 14:46:29 by mgarsaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

void	sort_three(t_stack_node **a)
{
    t_stack_node	*biggest_node;

    biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}