/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:08:09 by npawlak           #+#    #+#             */
/*   Updated: 2026/04/09 12:08:09 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_cpy_sort(int *lst, int state[2][4], int *cpy_lst, int is_ord)
{
	int	i;
	int	temp;

	i = -1;
	while (++i < state[0][3])
	{
		cpy_lst[i] = lst[i];
	}
	i = -1;
	while (is_ord == 1)
	{
		is_ord = 0;
		i = -1;
		while (++i < state[0][1])
		{
			if (cpy_lst[i] < cpy_lst[i + 1])
			{
				temp = cpy_lst[i];
				cpy_lst[i] = cpy_lst[i + 1];
				cpy_lst[i + 1] = temp;
				is_ord = 1;
			}
		}
	}
	return (cpy_lst);
}

int	chunk_repart(int state[2][4])
{
	int	nb_chunk;

	if (state[0][3] < 25)
		nb_chunk = 3;
	else if (state[0][3] <= 50)
		nb_chunk = 4;
	else if (state[0][3] <= 100)
		nb_chunk = 5;
	else if (state[0][3] <= 250)
		nb_chunk = 7;
	else if (state[0][3] <= 500)
		nb_chunk = 9;
	else if (state[0][3] <= 750)
		nb_chunk = 15;
	else
		nb_chunk = 20;
	return (nb_chunk);
}

void	repatriate_to_a(int *list_a, int *list_b, int state[2][4])
{
	int	debt;

	debt = 0;
	while (state[1][2] != 0)
	{
		order_in_make(list_b, state, &debt);
		push_a(list_b, list_a, state);
		if (debt == 1 && state[0][2] >= 2
			&& list_a[state[0][0]] > list_a[(state[0][0] + 1) % state[0][3]])
		{
			swap_a(list_a, state, 0);
			debt = 0;
		}
	}
}

void	get_podium(int *list_b, int state[2][4], int *i_max, int *i_max2)
{
	int	i;
	int	max;
	int	max2;

	i = -1;
	max = -2147483648;
	max2 = -2147483648;
	*i_max = 0;
	*i_max2 = 0;
	while (++i < state[1][2])
	{
		if (list_b[(state[1][0] + i) % state[1][3]] > max)
		{
			max2 = max;
			*i_max2 = *i_max;
			max = list_b[(state[1][0] + i) % state[1][3]];
			*i_max = i;
		}
		else if (list_b[(state[1][0] + i) % state[1][3]] > max2)
		{
			max2 = list_b[(state[1][0] + i) % state[1][3]];
			*i_max2 = i;
		}
	}
}
