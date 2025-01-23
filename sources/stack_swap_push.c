/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:12:07 by julrusse          #+#    #+#             */
/*   Updated: 2025/01/23 14:33:31 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack *a)
{
	int	tmp;

	if (a->size_a > 1)
	{
		tmp = a->stack_a[0];
		a->stack_a[0] = a->stack_a[1];
		a->stack_a[1] = tmp;
		ft_printf("sa\n");
	}
}

void	swap_b(t_stack *b)
{
	int	tmp;

	if (b->size_b > 1)
	{
		tmp = b->stack_b[0];
		b->stack_b[0] = b->stack_b[1];
		b->stack_b[1] = tmp;
		ft_printf("sb\n");
	}
}

void	swap_ab(t_stack *a, t_stack *b)
{
	if (a->size_a > 1)
		swap_a(a);
	if (b->size_b > 1)
		swap_b(b);
}

void	push_a(t_stack *b, t_stack *a)
{
	int	i;

	if (b->size_b > 0)
	{
		i = a->size_a;
		while (i > 0)
		{
			a->stack_a[i] = a->stack_a[i - 1];
			i--;
		}
		a->stack_a[0] = b->stack_b[0];
		a->size_a++;
		b->size_b--;
		i = 0;
		while (i < b->size_b)
		{
			b->stack_b[i] = b->stack_b[i + 1];
			i++;
		}
		b->stack_b[b->size_b] = 0;
		ft_printf("pa\n");
	}
}

void	push_b(t_stack *a, t_stack *b)
{
	int	i;

	if (a->size_a > 0)
	{
		i = b->size_b;
		while (i > 0)
		{
			b->stack_b[i] = b->stack_b[i - 1];
			i--;
		}
		b->stack_b[0] = a->stack_a[0];
		b->size_b++;
		a->size_a--;
		i = 0;
		while (i < a->size_a)
		{
			a->stack_a[i] = a->stack_a[i + 1];
			i++;
		}
		a->stack_a[a->size_a] = 0;
		ft_printf("pb\n");
	}
}
