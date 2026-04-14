/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 01:05:32 by npawlak           #+#    #+#             */
/*   Updated: 2026/03/04 01:05:32 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a(int *list_a, int state[2][4], int silence)
{
	int	new_bottom;

	if (state[0][2] <= 1)
		return (0);
	new_bottom = (state[0][1] + 1) % state[0][3];
	list_a[new_bottom] = list_a[state[0][0]];
	state[0][1] = new_bottom;
	state[0][0] = (state[0][0] +1) % state[0][3];
	if (silence == 0)
		write(1, "ra\n", 3);
	count_op(6);
	return (1);
}

int	rotate_b(int *list_b, int state[2][4], int silence)
{
	int	new_bottom;

	if (state[1][2] <= 1)
		return (0);
	new_bottom = (state[1][1] + 1) % state[1][3];
	list_b[new_bottom] = list_b[state[1][0]];
	state[1][1] = new_bottom;
	state[1][0] = (state[1][0] + 1) % state[1][3];
	if (silence == 0)
		write(1, "rb\n", 3);
	count_op(7);
	return (1);
}

int	rotate_double(int *list_a, int state[2][4], int *list_b)
{
	rotate_a(list_a, state, 1);
	rotate_b(list_b, state, 1);
	write(1, "rr\n", 3);
	count_op(8);
	return (1);
}
