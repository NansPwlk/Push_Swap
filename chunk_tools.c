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
