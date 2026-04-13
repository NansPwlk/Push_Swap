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

void	order_in_make(int *list_b, int state[2][4], int *debt)
{
	int	i_max;
	int	i_max2;
	int	cost1;
	int	cost2;
	int	t_val;

	get_podium(list_b, state, &i_max, &i_max2);
	cost1 = i_max;
	if (i_max > state[1][2] / 2)
		cost1 = state[1][2] - i_max;
	cost2 = i_max2;
	if (i_max2 > state[1][2] / 2)
		cost2 = state[1][2] - i_max2;
	if (*debt == 0 && cost2 < cost1)
	{
		i_max = i_max2;
		*debt = 1;
	}
	t_val = list_b[(state[1][0] + i_max) % state[1][3]];
	if (i_max > state[1][2] / 2)
		while (list_b[state[1][0]] != t_val)
			reverse_rotate_b(list_b, state, 0);
	else
		while (list_b[state[1][0]] != t_val)
			rotate_b(list_b, state, 0);
}
