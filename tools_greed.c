/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:30:44 by npawlak           #+#    #+#             */
/*   Updated: 2026/04/04 18:30:44 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_error(int *scores, int *path, int *next_index)
{
	free(next_index);
	free(scores);
	free(path);
	exit_error();
	return (0);
}

int	init_tab(int state[2][4], int *scores, int *next_index, int *path)
{
	int	i;

	i = 0;
	while (i < state[0][3])
	{
		scores[i] = 1;
		next_index[i] = -1;
		path[i] = 0;
		i++;
	}
	return (1);
}

int	*init_alg(int *list_a, int state[2][4])
{
	int	*scores;
	int	*path;
	int	*next_index;
	int	max_score;

	scores = NULL;
	path = NULL;
	next_index = NULL;
	scores = malloc(sizeof(int) * state[0][3]);
	path = malloc(sizeof(int) * state[0][3]);
	next_index = malloc(sizeof(int) * state[0][3]);
	if (!scores || !path || !next_index)
		free_error(scores, path, next_index);
	init_tab(state, scores, next_index, path);
	max_score = fnd_pth(list_a, state, scores, next_index);
	while (max_score != -1)
	{
		path[max_score] = 1;
		max_score = next_index[max_score];
	}
	free(scores);
	free(next_index);
	return (path);
}

int	fnd_pth(int *list_a, int state[2][4], int *scores, int *next_index)
{
	int	i;
	int	j;
	int	max_score;

	i = -1;
	j = 0;
	max_score = 0;
	while (++i < state[0][3])
	{
		j = i;
		while (--j >= 0)
		{
			if (list_a[j] < list_a[i] && scores[j] + 1 > scores[i])
			{
				scores[i] = scores[j] + 1;
				next_index[i] = j;
			}
		}
		if (scores[max_score] < scores[i])
			max_score = i;
	}
	return (max_score);
}

int	*mat_path(int *list_a, int *list_b, int state[2][4], int *matrix)
{
	int	*index_for_path;

	index_for_path = malloc(sizeof(int) * 2);
	if (matrix[0] + matrix[3] == matrix[4])
	{
		index_for_path[0] = 0;
		index_for_path[1] = 3;
	}
	else if (matrix[1] + matrix[2] == matrix[4])
	{
		index_for_path[0] = 1;
		index_for_path[1] = 2;
	}
	else if (matrix[0] == matrix[4] || matrix[2] == matrix[4])
	{
		index_for_path[0] = 0;
		index_for_path[1] = 2;
	}
	else if (matrix[1] == matrix[4] || matrix[3] == matrix[4])
	{
		index_for_path[0] = 1;
		index_for_path[1] = 3;
	}
	sort_path(list_a, list_b, state, index_for_path);
	return (index_for_path);
}
