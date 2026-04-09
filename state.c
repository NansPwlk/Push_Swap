/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:48:29 by npawlak           #+#    #+#             */
/*   Updated: 2026/03/04 12:48:29 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_state(int state[2][4], int size)
{
	state[0][0] = 0;
	state[0][1] = size - 1;
	state[0][2] = size;
	state[0][3] = size;
	state[1][0] = 0;
	state[1][1] = 0;
	state[1][2] = 0;
	state[1][3] = size;
}

void	minus_one(int *matrix)
{
	matrix[0] = matrix[0] - 1;
	matrix[1] = matrix[1] - 1;
	matrix[2] = matrix[2] - 1;
	matrix[3] = matrix[3] - 1;
	matrix[4] = matrix[4] - 1;
}

void	make_in_order(int *list_a, int state[2][4])
{
	int	i;
	int	min;
	int	index_min;
	int	current_idx;

	i = -1;
	min = 2147483647;
	while (++i < state[0][2])
	{
		current_idx = (state[0][0] + i) % state[0][3];
		if (list_a[current_idx] < min)
		{
			min = list_a[current_idx];
			index_min = i;
		}
	}
	if (index_min > state[0][2] / 2)
	{
		while (list_a[state[0][0]] != min)
			reverse_rotate_a(list_a, state, 0);
		return ;
	}
	while (list_a[state[0][0]] != min)
		rotate_a(list_a, state, 0);
}

void	order_in_make(int *list_b, int state[2][4])
{
	int	i;
	int	max;
	int	index_max;
	int	current_idx;

	i = -1;
	max = -2147483648;
	while (++i < state[1][2])
	{
		current_idx = (state[1][0] + i) % state[1][3];
		if (list_b[current_idx] > max)
		{
			max = list_b[current_idx];
			index_max = i;
		}
	}
	if (index_max > state[1][2] / 2)
	{
		while (list_b[state[1][0]] != max)
			reverse_rotate_b(list_b, state, 0);
		return ;
	}
	while (list_b[state[1][0]] != max)
		rotate_b(list_b, state, 0);
}
