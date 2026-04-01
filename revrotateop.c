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

int	reverse_rotate_a(int *list_a, int *state_a, int silence)
{
	int	new_top;

	if (state_a[2] <= 1)
		return (0);
	new_top = (state_a[0] - 1 + state_a[3]) % state_a[3];
	list_a[new_top] = list_a[state_a[1]];
	state_a[0] = new_top;
	state_a[1] = (state_a[1] -1 + state_a[3]) % state_a[3];
	if (silence == 0)
		write(1, "rra\n", 4);
	return (1);
}

int	reverse_rotate_b(int *list_b, int *state_b, int silence)
{
	int	new_top;

	if (state_b[2] <= 1)
		return (0);
	new_top = (state_b[0] - 1 + state_b[3]) % state_b[3];
	list_b[new_top] = list_b[state_b[1]];
	state_b[0] = new_top;
	state_b[1] = (state_b[1] -1 + state_b[3]) % state_b[3];
	if (silence == 0)
		write(1, "rrb\n", 4);
	return (1);
}

int	revrot_double(int *list_a, int *state_a, int *list_b, int *state_b)
{
	reverse_rotate_a(list_a, state_a, 1);
	reverse_rotate_b(list_b, state_b, 1);
	write(1,"rrr\n", 4);
	return(1);
}