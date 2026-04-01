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

int	rotate_a(int *list_a, int *state_a, int silence)
{
	int	new_bottom;

	if (state_a[2] <= 1)
		return (0);
	new_bottom = (state_a[1] + 1) % state_a[3];
	list_a[new_bottom] = list_a[state_a[0]];
	state_a[1] = new_bottom;
	state_a[0] = (state_a[0] +1 ) % state_a[3];
	if (silence == 0)
		write(1, "ra\n", 3);
	return (1);
}

int	rotate_b(int *list_b, int *state_b, int silence)
{
	int	new_bottom;

	if (state_b[2] <= 1)
		return (0);
	new_bottom = (state_b[1] + 1) % state_b[3];
	list_b[new_bottom] = list_b[state_b[0]];
	state_b[1] = new_bottom;
	state_b[0] = (state_b[0] + 1) % state_b[3];
	if (silence == 0)
		write(1, "ra\n", 3);
	return (1);
}

int	rotate_double(int *list_a, int *state_a, int *list_b, int *state_b)
{
	rotate_a(list_a, state_a, 1);
	rotate_b(list_b, state_b, 1);
	write(1,"rr\n", 3);
	return(1);
}