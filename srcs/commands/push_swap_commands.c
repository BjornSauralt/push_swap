/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarsaul <mgarsaul@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-17 13:41:31 by mgarsaul          #+#    #+#             */
/*   Updated: 2024-12-17 13:41:31 by mgarsaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b); 
	if (!print) 
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}

void	sa(t_stack_node	**a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}
