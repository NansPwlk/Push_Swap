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

float	compute_disorder(int *list_a, int state[2][4])
{
	float	disorder;
	int		is_error;
	int		total_pairs;
	int		i;
	int		j;

	i = 0;
	is_error = 0;
	total_pairs = state[0][3] * (state[0][1]) / 2;
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
	if (disord < 0.2)
		select_sort(lst_a, lst_b, state);
	else if (disord >= 0.2 && disord < 0.5)
		chunk_sort(lst_a, lst_b, state);
	else if (disord >= 0.5)
		greed_sort(lst_a, lst_b, state);
}
