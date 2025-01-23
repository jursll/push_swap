/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:08:21 by julrusse          #+#    #+#             */
/*   Updated: 2025/01/23 14:32:39 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	is_valid_number(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	if (len == 0)
		error();
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		error();
	while (str[i])
		if (!ft_isdigit(str[i++]))
			error();
	if ((str[0] == '-' && len > 11) || (str[0] != '-' && len > 10))
		error();
	if (str[0] == '-' && len == 11 && ft_strncmp(str, "-2147483648", 11) > 0)
		error();
	if (str[0] != '-' && len == 10 && ft_strncmp(str, "2147483647", 10) > 0)
		error();
}

void	check_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				error();
			j++;
		}
		i++;
	}
}
