/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarsaul <mgarsaul@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-18 12:58:20 by mgarsaul          #+#    #+#             */
/*   Updated: 2024-12-18 12:58:20 by mgarsaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	current_index(t_noeud *stack)
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
		stack->above_median = (i <= median);
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_noeud *a, t_noeud *b)
{
	t_noeud	*current_b;
	t_noeud	*target_node;
	long	best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_noeud = find_max(b);
		else
			a->target_noeud = target_node;
		a = a->next;
	}
}

static void	cost_analysis_a(t_noeud *a, t_noeud *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!a->above_median)
			a->push_cost = len_a - a->index;
		if (a->target_noeud->above_median)
			a->push_cost += a->target_noeud->index;
		else
			a->push_cost += len_b - a->target_noeud->index;
		a = a->next;
	}
}

void	set_cheapest(t_noeud *stack)
{
	long	cheapest_value;
	t_noeud	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_noeud *a, t_noeud *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
