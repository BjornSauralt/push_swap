/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarsaul <mgarsaul@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-18 12:34:50 by mgarsaul          #+#    #+#             */
/*   Updated: 2024-12-18 12:34:50 by mgarsaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	move_a_to_b(t_noeud **a, t_noeud **b)
{
	t_noeud	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median
		&& cheapest->target_noeud->above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest-> above_median)
		&& !(cheapest->target_noeud-> above_median))
		reverse_rotate_both(a, b, cheapest);
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->target_noeud, 'b');
	pb(b, a, false);
}

void	move_b_to_a(t_noeud **a, t_noeud **b)
{
	prep_for_push(a, (*b)->target_noeud, 'a');
	pa(a, b, false);
}

void	min_on_top(t_noeud **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	tri_pile(t_noeud **a, t_noeud **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !pile_trie(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !pile_trie(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !pile_trie(*a))
	{
		init_pile_a(*a, *b);
		move_a_to_b(a, b);
	}
	tri_three(a);
	while (*b)
	{
		init_pile_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
