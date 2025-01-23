/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:10:38 by julrusse          #+#    #+#             */
/*   Updated: 2025/01/23 14:33:03 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->stack_a[0] > a->stack_a[1])
		swap_a(a);
}

void	sort_three(t_stack *a)
{
	if (a->stack_a[0] > a->stack_a[2] && a->stack_a[2] > a->stack_a[1])
		rotate_a(a);
	else if (a->stack_a[0] < a->stack_a[2] && a->stack_a[2] < a->stack_a[1])
	{
		rev_rotate_a(a);
		swap_a(a);
	}
	else if (a->stack_a[1] < a->stack_a[0] && a->stack_a[0] < a->stack_a[2])
	{
		swap_a(a);
	}
	else if (a->stack_a[0] < a->stack_a[1] && a->stack_a[1] > a->stack_a[2])
		rev_rotate_a(a);
	else if (a->stack_a[0] > a->stack_a[1] && a->stack_a[1] > a->stack_a[2])
	{
		rotate_a(a);
		swap_a(a);
	}
}

void	sort_four(t_stack *a, t_stack *b)
{
	find_min_index(a);
	bring_min_top(a);
	push_b(a, b);
	sort_three(a);
	push_a(b, a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	find_min_index(a);
	bring_min_top(a);
	push_b(a, b);
	find_min_index(a);
	bring_min_top(a);
	push_b(a, b);
	sort_three(a);
	push_a(b, a);
	push_a(b, a);
}
