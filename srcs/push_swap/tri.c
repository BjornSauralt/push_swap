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

void	tri_three(t_noeud **a)
{
	t_noeud	*gros_noeud;

	gros_noeud = find_max(*a);
	if (gros_noeud == *a)
		ra(a, false);
	else if ((*a)->next == gros_noeud)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}
