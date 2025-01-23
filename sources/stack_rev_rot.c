/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rev_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:11:24 by julrusse          #+#    #+#             */
/*   Updated: 2025/01/23 14:33:21 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rev_rotate_a(t_stack *a)
{
	int		temp;
	int		i;

	if (a->size_a > 1)
	{
		i = a->size_a - 1;
		temp = a->stack_a[i];
		while (i > 0)
		{
			a->stack_a[i] = a->stack_a[i - 1];
			i--;
		}
		a->stack_a[0] = temp;
		ft_printf("rra\n");
	}
}

void	rev_rotate_b(t_stack *b)
{
	int	temp;
	int	i;

	if (b->size_b > 1)
	{
		i = b->size_b - 1;
		temp = b->stack_b[i];
		while (i > 0)
		{
			b->stack_b[i] = b->stack_b[i - 1];
			i--;
		}
		b->stack_b[0] = temp;
		ft_printf("rrb\n");
	}
}

void	rev_rotate_ab(t_stack *a, t_stack *b)
{
	int		swapped_a;
	int		swapped_b;

	swapped_a = 0;
	swapped_b = 0;
	if (a->size_a > 1)
	{
		rev_rotate_a(a);
		swapped_a = 1;
	}
	if (b->size_b > 1)
	{
		rev_rotate_b(b);
		swapped_b = 1;
	}
	if (swapped_a || swapped_b)
		ft_printf("rrr\n");
}
