/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarsaul <mgarsaul@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-18 13:03:18 by mgarsaul          #+#    #+#             */
/*   Updated: 2024-12-18 13:03:18 by mgarsaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	set_target_a(t_noeud *a, t_noeud *b)
{
	t_noeud			*current_b;
	t_noeud			*target_node;
	long			best_match_index;

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
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	set_target_b(t_noeud *a, t_noeud *b)
{
	t_noeud			*current_a;
	t_noeud			*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_cheapest(t_noeud *stack)
{
	long			cheapest_value;
	t_noeud			*cheapest_node;

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
