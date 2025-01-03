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

void	set_target_b(t_noeud *a, t_noeud *b)
{
	t_noeud	*current_a;
	t_noeud	*target_noeud;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_noeud = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_noeud = find_min(a);
		else
			b->target_noeud = target_noeud;
		b = b->next;
	}
}

void	init_pile_b(t_noeud *a, t_noeud *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
