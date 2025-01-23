/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:09:50 by julrusse          #+#    #+#             */
/*   Updated: 2025/01/23 14:32:56 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	handle_input(argc, argv, &a, &b);
	sort_and_cleanup(&a, &b);
	if (a.stack_a)
		free(a.stack_a);
	if (b.stack_b)
		free(b.stack_b);
	return (0);
}
