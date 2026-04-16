/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peculiar_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:52:24 by npawlak           #+#    #+#             */
/*   Updated: 2026/04/16 11:52:24 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *for_two(int *list_a, int state[2][4])
{
	if (list_a[state[0][0]] > list_a[(state[0][0] + 1) % state[0][3]])
		swap_a(list_a, state, 0);
	return(list_a);
}

int *for_three(int *list_a, int state[2][4])
{
	int i;
	int i_max;
	int j;

	i = state[0][0];
	i_max = state[0][0];
	j = -1;
	while (++j != 3)
	{
		if (list_a[i] > list_a[i_max])
			i_max = i;
		i = (i + 1) % state[0][3];
	}
	if (i_max == state[0][0])
		rotate_a(list_a, state, 0);
	else if(i_max == (state[0][0] + 1) % state[0][3])
		reverse_rotate_a(list_a, state, 0);
	for_two(list_a, state);
	return(list_a);
}

int	*for_four(int *list_a, int *list_b, int state[2][4])
{
	int	i;
	int	i_min;
	int	j;

	i = state[0][0];
	i_min = i;
	j = -1;
	while (++j != 4)
	{
		if (list_a[i] < list_a[i_min])
			i_min = i;
		i = (i + 1) % state[0][3];
	}
	j = (i_min - state[0][0] + state[0][3]) % state[0][3];
	while (j > 0 && j <= 1 && j--)
		rotate_a(list_a, state, 0);
	while (j > 1 && j++ < 4)
		reverse_rotate_a(list_a, state, 0);
	push_b(list_a, list_b, state);
	for_three(list_a, state);
	push_a(list_b, list_a, state);
	return (list_a);
}

int	*for_five(int *list_a, int *list_b, int state[2][4])
{
	int	i;
	int	i_min;
	int	j;

	i = state[0][0];
	i_min = i;
	j = -1;
	while (++j != 5)
	{
		if (list_a[i] < list_a[i_min])
			i_min = i;
		i = (i + 1) % state[0][3];
	}
	j = (i_min - state[0][0] + state[0][3]) % state[0][3];
	while (j > 0 && j <= 2 && j--)
		rotate_a(list_a, state, 0);
	while (j > 2 && j++ < 5)
		reverse_rotate_a(list_a, state, 0);
	push_b(list_a, list_b, state);
	for_four(list_a, list_b, state);
	push_a(list_b, list_a, state);
	return (list_a);
}
