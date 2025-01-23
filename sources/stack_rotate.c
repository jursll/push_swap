/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:11:49 by julrusse          #+#    #+#             */
/*   Updated: 2025/01/23 14:33:26 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack *a)
{
	int		temp;
	int		i;

	if (a->size_a > 1)
	{
		temp = a->stack_a[0];
		i = 0;
		while (i < (a->size_a - 1))
		{
			a->stack_a[i] = a->stack_a[i + 1];
			i++;
		}
		a->stack_a[a->size_a - 1] = temp;
		ft_printf("ra\n");
	}
}

void	rotate_b(t_stack *b)
{
	int		temp;
	int		i;

	if (b->size_b > 1)
	{
		temp = b->stack_b[0];
		i = 0;
		while (i < b->size_b - 1)
		{
			b->stack_b[i] = b->stack_b[i + 1];
			i++;
		}
		b->stack_b[b->size_b - 1] = temp;
		ft_printf("rb\n");
	}
}

void	rotate_ab(t_stack *a, t_stack *b)
{
	int		swapped_a;
	int		swapped_b;

	swapped_a = 0;
	swapped_b = 0;
	if (a->size_a > 1)
	{
		rotate_a(a);
		swapped_a = 1;
	}
	if (b->size_b > 1)
	{
		rotate_b(b);
		swapped_a = 1;
	}
	if (swapped_a || swapped_b)
		ft_printf("rr\n");
}
