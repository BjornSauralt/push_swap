/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarsaul <mgarsaul@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-17 14:31:19 by mgarsaul          #+#    #+#             */
/*   Updated: 2024-12-17 14:31:19 by mgarsaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_noeud **head)
{
	if (!head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->prev = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

static void	push(t_noeud **dst, t_noeud **src)
{
	t_noeud	*push_noeud;

	if (!*src)
		return ;
	push_noeud = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_noeud->prev = NULL;
	if (!*dst)
	{
		*dst = push_noeud;
		push_noeud->next = NULL;
	}
	else
	{
		push_noeud->next = *dst;
		push_noeud->next->prev = push_noeud;
		*dst = push_noeud;
	}
}