/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:10:09 by julrusse          #+#    #+#             */
/*   Updated: 2025/01/23 14:32:59 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	bit;
	int	i;
	int	size;

	max_bits = 0;
	size = a->size_a;
	while ((size - 1) >> max_bits != 0)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((a->stack_a[0] >> bit) & 1) == 0)
				push_b(a, b);
			else
				rotate_a(a);
			i++;
		}
		while (b->size_b > 0)
			push_a(b, a);
		bit++;
	}
}

void	normalize_stack(t_stack *a)
{
	int	*temp;
	int	i;
	int	j;
	int	index;

	temp = (int *)malloc(sizeof(int) * a->size_a);
	if (!temp)
		error();
	i = -1;
	while (++i < a->size_a)
		temp[i] = a->stack_a[i];
	i = -1;
	while (++i < a->size_a)
	{
		index = 0;
		j = -1;
		while (++j < a->size_a)
			if (temp[j] < temp[i])
				index++;
		a->stack_a[i] = index;
	}
	free(temp);
}
