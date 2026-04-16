/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:10:05 by npawlak           #+#    #+#             */
/*   Updated: 2026/04/09 12:10:05 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(int *list_a, int state[2][4], int who)
{
	static float	disorder;
	int				is_error;
	int				total_pairs;
	int				i;
	int				j;

	i = 0;
	is_error = 0;
	total_pairs = state[0][3] * (state[0][1]) / 2;
	if (who == 0)
		return (disorder);
	while (i < state[0][3])
	{
		j = i + 1;
		while (j < state[0][3])
		{
			if (list_a[i] > list_a[j])
				is_error++;
			j++;
		}
		i++;
	}
	disorder = (float)is_error / (float)total_pairs;
	return (disorder);
}

void	adapt_choice(int *lst_a, int *lst_b, int state[2][4], float disord)
{
	if (state[0][3] == 2)
		for_two(lst_a, state);
	else if (state[0][3] == 3)
		for_three(lst_a, state);
	else if (state[0][3] == 4)
		for_four(lst_a, lst_b, state);
	else if (state[0][3] == 5)
		for_five(lst_a, lst_b, state);
	else if (disord < 0.2 || (int)disord == 12)
		select_sort(lst_a, lst_b, state);
	else if ((disord >= 0.2 && disord < 0.5) || (int)disord == 22)
		chunk_sort(lst_a, lst_b, state);
	else if (disord >= 0.5 || (int)disord == 32)
		greed_sort(lst_a, lst_b, state);
}
