/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:21:27 by npawlak           #+#    #+#             */
/*   Updated: 2026/04/01 16:21:27 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(int *list_a, int state[2][4], int silence)
{
	int	temp;

	if (state[0][2] <= 1)
		return (0);
	temp = list_a[(state[0][0] + 1) % state[0][3]];
	list_a[(state[0][0] + 1) % state[0][3]] = list_a[state[0][0]];
	list_a[state[0][0]] = temp;
	if (silence == 0)
		write(1, "sa\n", 3);
	count_op(1);
	return (1);
}

int	swap_b(int *list_b, int state[2][4], int silence)
{
	int	temp;

	if (state[1][2] <= 1)
		return (0);
	temp = list_b[(state[1][0] + 1) % state[1][3]];
	list_b[(state[1][0] + 1) % state[1][3]] = list_b[state[1][0]];
	list_b[state[1][0]] = temp;
	if (silence == 0)
		write(1, "sb\n", 3);
	count_op(2);
	return (1);
}

int	swap_double(int *list_a, int state[2][4], int *list_b)
{
	swap_a(list_a, state, 1);
	swap_b(list_b, state, 1);
	write(1, "ss\n", 3);
	count_op(3);
	return (1);
}
