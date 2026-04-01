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

int	push_b(int *list_a, int *list_b, int *state_a, int *state_b)
{
	if (state_a[2] == 0)
		return (0);
	if (state_b[2] == 0)
		state_b[1] = state_b[0];
	else
		state_b[0] = (state_b[0] - 1 + state_b[3]) % state_b[3];
	list_b[state_b[0]] = list_a[state_a[0]];
	state_b[2]++;
	state_a[2]--;
	state_a[0] = (state_a[0] + 1) % state_a[3];
	write(1, "pb\n", 3);
	return (1);
}

int push_a(int *list_b, int *list_a, int *state_a, int *state_b)
{
	if (state_b[2] == 0)
		return(0);
	if (state_a[2] == 0)
		state_a[1] = state_a[0];
	else
		state_a[0] = (state_a[0] - 1 + state_a[3]) % state_a[3];
	list_a[state_a[0]] = list_b[state_b[0]];
	state_a[2]++;
	state_b[2]--;
	state_b[0] = (state_b[0] + 1) % state_b[3];
	write(1, "pa\n", 3);
	return(1); 
}
