/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:49:56 by npawlak           #+#    #+#             */
/*   Updated: 2026/04/02 15:49:56 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	greed_sort(int *list_a, int *list_b, int state[2][4])
{
	int	*path;
	int	*matrix;
	int	*index_for_path;
	int	i;

	i = -1;
	path = init_alg(list_a, state);
	while (++i < state[0][3])
	{
		if (path[i] == 1)
			rotate_a(list_a, state, 0);
		if (path[i] == 0)
			push_b(list_a, list_b, state);
	}
	i = -1;
	while (state[1][2] != 0)
	{
		matrix = calc_matrix(list_a, list_b, state);
		index_for_path = mat_path(list_a, list_b, state, matrix);
		sort_path(list_a, list_b, state, matrix);
		free(index_for_path);
		free(matrix);
	}
	make_in_order(list_a, state);
}

void	sort_path(int *list_a, int *list_b, int state[2][4], int *matr)
{
	static int	indx_m[3] = {0, 0, 0};

	if (indx_m[2] != 2147483647)
	{
		copy_matrix(matr, indx_m, 1, 2);
	}
	else
	{
		while (matr[4] > 0)
		{
			if (indx_m[0] == 0 && indx_m[1] == 2)
				exec_rotates(list_a, list_b, state, matr);
			else if (indx_m[0] == 1 && indx_m[1] == 3)
				exec_rev_rot(list_a, list_b, state, matr);
			else if (indx_m[0] == 0 && indx_m[1] == 3)
				exec_mix_a_up(list_a, list_b, state, matr);
			else if (indx_m[0] == 1 && indx_m[1] == 2)
				exec_mix_b_up(list_a, list_b, state, matr);
			minus_one(matr);
		}
		indx_m[2] = 0;
		push_a(list_b, list_a, state);
	}
}

int	*calc_matrix(int *list_a, int *list_b, int state[2][4])
{
	int	b;
	int	a;
	int	cost[5];
	int	*best;

	best = malloc(sizeof(int) * 5);
	if (!best)
		return (NULL);
	cost[4] = 2147483647;
	copy_matrix(cost, best, 2147483647, 1);
	b = -1;
	while (++b < state[1][2])
	{
		a = get_targ(list_b[(state[1][0] + b) % state[1][3]], list_a, state, 1);
		cost[0] = a;
		cost[1] = state[0][2] - a;
		cost[2] = b;
		cost[3] = state[1][2] - b;
		calc_matrix_bis(cost, best);
	}
	return (best);
}

int	*copy_matrix(int *cost_matrix, int *best_matrix, int bs, int first)
{
	int	i;

	i = -1;
	if (first == 2)
	{
		best_matrix[0] = cost_matrix[0];
		best_matrix[1] = cost_matrix[1];
		best_matrix[2] = 2147483647;
		return (best_matrix);
	}
	if (first == 1)
	{
		cost_matrix[0] = 2147483647;
		cost_matrix[1] = 2147483647;
		cost_matrix[2] = 2147483647;
		cost_matrix[3] = 2147483647;
		cost_matrix[4] = 2147483647;
	}
	while (++i < 4)
		best_matrix[i] = cost_matrix[i];
	best_matrix[4] = bs;
	cost_matrix[4] = bs;
	return (best_matrix);
}

int	*calc_matrix_bis(int *cm, int *bm)
{
	if (cm[0] + cm[3] < bm[4])
		copy_matrix(cm, bm, (cm[0] + cm[3]), 0);
	if (cm[1] + cm[2] < bm[4])
		copy_matrix(cm, bm, (cm[1] + cm[2]), 0);
	if (cm[0] < bm[4] && cm[2] < bm[4])
	{
		if (cm[0] < cm[2])
			cm[4] = cm[2];
		else
			cm[4] = cm[0];
		copy_matrix(cm, bm, cm[4], 0);
	}
	if (cm[1] < bm[4] && cm[3] < bm[4])
	{
		if (cm[1] < cm[3])
			cm[4] = cm[3];
		else
			cm[4] = cm[1];
		copy_matrix(cm, bm, cm[4], 0);
	}
	return (bm);
}
