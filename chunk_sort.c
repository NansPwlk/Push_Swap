/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 21:25:06 by npawlak           #+#    #+#             */
/*   Updated: 2026/04/07 21:25:06 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(int *list_a, int *list_b, int state[2][4])
{
	int	*cpy_lista;
	int	nb_chunk;
	int	*opt_chk;

	cpy_lista = malloc(sizeof(int) * state[0][3]);
	if (!cpy_lista)
		exit_error();
	nb_chunk = chunk_repart(state);
	cpy_lista = get_cpy_sort(list_a, state, cpy_lista, 1);
	while (nb_chunk > 0)
	{
		opt_chk = one_chunk(state, cpy_lista);
		push_chunk(list_a, list_b, state, opt_chk);
		free(opt_chk);
		nb_chunk--;
	}
	while (state[0][2] != 0)
		push_b(list_a, list_b, state);
	while (state[1][2] != 0)
	{
		order_in_make(list_b, state);
		push_a(list_b, list_a, state);
	}
	free(cpy_lista);
}

int	*one_chunk(int state[2][4], int *cpy_lst)
{
	int			i;
	int			nb_chunk;
	static int	count = 0;
	int			*opt_chk;

	nb_chunk = chunk_repart(state);
	opt_chk = malloc(sizeof(int) * ((state[0][3] / nb_chunk) + 1));
	i = 0;
	while (i < state[0][3] / nb_chunk)
	{
		opt_chk[i] = cpy_lst[count];
		i++;
		count++;
	}
	opt_chk[i] = 2147483647;
	return (opt_chk);
}

void	push_chunk(int *list_a, int *list_b, int state[2][4], int *opt_chk)
{
	int	chunk_size;
	int	pushed;

	chunk_size = 0;
	while (opt_chk[chunk_size] != 2147483647)
		chunk_size++;
	pushed = 0;
	while (pushed < chunk_size)
	{
		if (is_in_chunk(list_a[state[0][0]], opt_chk) == 1)
		{
			push_b(list_a, list_b, state);
			do_i_rotate(list_b, state, opt_chk);
			pushed++;
		}
		else
		{
			rotate_a(list_a, state, 0);
		}
	}
}

int	is_in_chunk(int value, int *opt_chk)
{
	int	i;

	i = 0;
	while (opt_chk[i] != 2147483647)
	{
		if (value == opt_chk[i])
			return (1);
		i++;
	}
	return (0);
}

void	do_i_rotate(int *list_b, int state[2][4], int *opt_chk)
{
	int	med;
	int	i;

	i = 0;
	while (opt_chk[i] != 2147483647)
		i++;
	med = opt_chk[i / 2];
	if (list_b[state[1][0]] <= med)
	{
		rotate_b(list_b, state, 0);
	}
}
