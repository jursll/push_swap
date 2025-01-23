/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:08:56 by julrusse          #+#    #+#             */
/*   Updated: 2025/01/23 14:32:49 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_and_free_split(char **split_input)
{
	int	i;

	i = 0;
	while (split_input[i])
	{
		free(split_input[i]);
		i++;
	}
	free(split_input);
	error();
}
