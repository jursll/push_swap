/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:09:28 by julrusse          #+#    #+#             */
/*   Updated: 2025/01/23 14:32:53 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	handle_input(int argc, char **argv, t_stack *a, t_stack *b)
{
	if (argc == 2)
		handle_single_input(argv[1], a, b);
	else
		handle_multiple_inputs(argc, argv, a, b);
	check_duplicates(a->stack_a, a->size_a);
}

void	handle_single_input(char *arg, t_stack *a, t_stack *b)
{
	char	**split_input;
	int		i;

	split_input = ft_split(arg, ' ');
	if (!split_input || !split_input[0])
	{
		free(split_input);
		error();
	}
	a->size_a = 0;
	while (split_input[a->size_a])
		a->size_a++;
	b->size_b = 0;
	a->stack_a = malloc(a->size_a * sizeof(int));
	b->stack_b = malloc(a->size_a * sizeof(int));
	if (!a->stack_a || !b->stack_b)
		error_and_free_split(split_input);
	i = -1;
	while (++i < a->size_a)
	{
		is_valid_number(split_input[i]);
		a->stack_a[i] = ft_atoi(split_input[i]);
		free(split_input[i]);
	}
	free(split_input);
}

void	handle_multiple_inputs(int argc, char **argv, t_stack *a, t_stack *b)
{
	int		i;

	a->size_a = argc - 1;
	b->size_b = 0;
	a->stack_a = malloc(a->size_a * sizeof(int));
	b->stack_b = malloc(a->size_a * sizeof(int));
	if (!a->stack_a || !b->stack_b)
		error();
	i = 0;
	while (i < a->size_a)
	{
		is_valid_number(argv[i + 1]);
		a->stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

void	sort_and_cleanup(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size_a >= 2 && a->size_a <= 5)
		two_to_five(a, b);
	else
	{
		normalize_stack(a);
		radix_sort(a, b);
	}
}
