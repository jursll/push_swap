/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:13:18 by julrusse          #+#    #+#             */
/*   Updated: 2025/01/26 11:19:21 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;
	int		smallest_index;
}	t_stack;

int		error(void);
void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swap_ab(t_stack *a, t_stack *b);
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_ab(t_stack *a, t_stack *b);
void	rev_rotate_a(t_stack *a);
void	rev_rotate_b(t_stack *b);
void	rev_rotate_ab(t_stack *a, t_stack *b);   
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	two_to_five(t_stack *a, t_stack *b);
void	normalize_stack(t_stack *a);
void	radix_sort(t_stack *a, t_stack *b);
void	bring_min_top(t_stack *a);
void	find_min_index(t_stack *a);
void	handle_input(int argc, char **argv, t_stack *a, t_stack *b);
void	handle_multiple_inputs(int argc, char **argv, t_stack *a, t_stack *b);
void	handle_single_input(char *arg, t_stack *a, t_stack *b);
void	is_valid_number(char *str);
void	check_duplicates(int *arr, int size);
int		is_sorted(t_stack *a);
void	sort_and_cleanup(t_stack *a, t_stack *b);
void	error_and_free_split(char **split_input);

#endif
