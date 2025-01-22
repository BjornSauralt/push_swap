/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarsaul <mgarsaul@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-17 14:11:41 by mgarsaul          #+#    #+#             */
/*   Updated: 2024-12-17 14:11:41 by mgarsaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	initialize_stacks(int argc, char **argv,
			t_noeud **a, char ***split_argv)
{
	*split_argv = NULL;
	if (argc == 2)
	{
		*split_argv = ft_split(argv[1], ' ');
		argv = *split_argv;
	}
	init_stack_a(a, argv + 1);
}

void	sort_stacks_if_needed(t_noeud **a, t_noeud **b)
{
	if (!stack_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a, false);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else
			sort_stacks(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_noeud	*a;
	t_noeud	*b;
	char	**split_argv;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	initialize_stacks(argc, argv, &a, &split_argv);
	sort_stacks_if_needed(&a, &b);
	free_stack(&a);
	if (split_argv)
		free_split(split_argv);
	return (0);
}
