/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:10:56 by julrusse          #+#    #+#             */
/*   Updated: 2025/01/23 14:33:17 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *a)
{
	int		i;

	i = 0;
	while (i < a->size_a - 1)
	{
		if (a->stack_a[i] > a->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	two_to_five(t_stack *a, t_stack *b)
{
	if (a->size_a == 2)
		sort_two(a);
	else if (a->size_a == 3)
		sort_three(a);
	else if (a->size_a == 4)
		sort_four(a, b);
	else if (a->size_a == 5)
		sort_five(a, b);
}

void	find_min_index(t_stack *a)
{
	int	i;

	a->smallest_index = 0;
	i = 1;
	while (i < a->size_a)
	{
		if (a->stack_a[i] < a->stack_a[a->smallest_index])
		{
			a->smallest_index = i;
		}
		i++;
	}
}

void	bring_min_top(t_stack *a)
{
	int	i;

	find_min_index(a);
	if (a->smallest_index == 0)
		return ;
	i = 0;
	if (a->smallest_index < a->size_a / 2)
	{
		while (i < a->smallest_index)
		{
			rotate_a(a);
			i++;
		}
	}
	else
	{
		while (i++ < a->size_a - a->smallest_index)
			rev_rotate_a(a);
	}
}
