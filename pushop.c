/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 23:47:44 by npawlak           #+#    #+#             */
/*   Updated: 2026/03/03 23:47:44 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_b(int *list_a, int *list_b, int state[2][4])
{
	if (state[0][2] == 0)
		return (0);
	if (state[1][2] == 0)
		state[1][1] = state[1][0];
	else
		state[1][0] = (state[1][0] - 1 + state[1][3]) % state[1][3];
	list_b[state[1][0]] = list_a[state[0][0]];
	state[1][2]++;
	state[0][2]--;
	state[0][0] = (state[0][0] + 1) % state[0][3];
	write(1, "pb\n", 3);
	return (1);
}

int	push_a(int *list_b, int *list_a, int state[2][4])
{
	if (state[1][2] == 0)
		return (0);
	if (state[0][2] == 0)
		state[0][1] = state[0][0];
	else
		state[0][0] = (state[0][0] - 1 + state[0][3]) % state[0][3];
	list_a[state[0][0]] = list_b[state[1][0]];
	state[0][2]++;
	state[1][2]--;
	state[1][0] = (state[1][0] + 1) % state[1][3];
	write(1, "pa\n", 3);
	return (1);
}
