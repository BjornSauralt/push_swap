/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarsaul <mgarsaul@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-17 15:29:29 by mgarsaul          #+#    #+#             */
/*   Updated: 2024-12-17 15:29:29 by mgarsaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_noeud **stack)
{
	t_noeud	*last_noeud;

	if (!*stack || !(*stack)->next)
		return ;
	last_noeud = find_last(*stack);
	last_noeud->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_noeud->next->prev = last_noeud;
	last_noeud->next->next = NULL;
}

static void	rotate_both(t_noeud **a, t_noeud **b, t_noeud *cheapest)
{
	while (*b != cheapest->target_noeud && *a != cheapest)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	ra(t_noeud **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_noeud **b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_noeud **a, t_noeud **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}
