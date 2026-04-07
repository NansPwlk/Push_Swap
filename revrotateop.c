/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotateop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:12:21 by npawlak           #+#    #+#             */
/*   Updated: 2026/04/01 15:12:21 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate_a(int *list_a, int state[2][4], int silence)
{
	int	new_top;

	if (state[0][2] <= 1)
		return (0);
	new_top = (state[0][0] - 1 + state[0][3]) % state[0][3];
	list_a[new_top] = list_a[state[0][1]];
	state[0][0] = new_top;
	state[0][1] = (state[0][1] -1 + state[0][3]) % state[0][3];
	if (silence == 0)
		write(1, "rra\n", 4);
	return (1);
}

int	reverse_rotate_b(int *list_b, int state[2][4], int silence)
{
	int	new_top;

	if (state[1][2] <= 1)
		return (0);
	new_top = (state[1][0] - 1 + state[1][3]) % state[1][3];
	list_b[new_top] = list_b[state[1][1]];
	state[1][0] = new_top;
	state[1][1] = (state[1][1] -1 + state[1][3]) % state[1][3];
	if (silence == 0)
		write(1, "rrb\n", 4);
	return (1);
}

int	revrot_double(int *list_a, int state[2][4], int *list_b)
{
	reverse_rotate_a(list_a, state, 1);
	reverse_rotate_b(list_b, state, 1);
	write(1, "rrr\n", 4);
	return (1);
}
