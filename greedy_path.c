/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 16:50:50 by npawlak           #+#    #+#             */
/*   Updated: 2026/04/07 16:50:50 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_rotates(int *list_a, int *list_b, int state[2][4], int *matr)
{
	if (matr[0] > 0 && matr[2] > 0)
		rotate_double(list_a, state, list_b);
	else if (matr[0] > 0)
		rotate_a(list_a, state, 0);
	else if (matr[2] > 0)
		rotate_b(list_b, state, 0);
}

void	exec_rev_rot(int *list_a, int *list_b, int state[2][4], int *matr)
{
	if (matr[1] > 0 && matr[3] > 0)
		revrot_double(list_a, state, list_b);
	else if (matr[1] > 0)
		reverse_rotate_a(list_a, state, 0);
	else if (matr[3] > 0)
		reverse_rotate_b(list_b, state, 0);
}

void	exec_mix_a_up(int *list_a, int *list_b, int state[2][4], int *matr)
{
	if (matr[0] > 0 && matr[3] > 0)
	{
		rotate_a(list_a, state, 0);
		reverse_rotate_b(list_b, state, 0);
	}
	else if (matr[0] > 0)
		rotate_a(list_a, state, 0);
	else if (matr[3] > 0)
		reverse_rotate_b(list_b, state, 0);
}

void	exec_mix_b_up(int *list_a, int *list_b, int state[2][4], int *matr)
{
	if (matr[1] > 0 && matr[2] > 0)
	{
		rotate_b (list_b, state, 0);
		reverse_rotate_a(list_a, state, 0);
	}
	else if (matr[2] > 0)
		rotate_b(list_b, state, 0);
	else if (matr[1] > 0)
		reverse_rotate_a(list_a, state, 0);
}
