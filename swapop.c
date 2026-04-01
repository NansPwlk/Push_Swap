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

int	swap_a(int *list_a, int *state_a, int silence)
{
	int	temp;
	if (state_a[2] <= 1)
		return (0);
	temp = list_a[(state_a[0] + 1) % state_a[3]];
	list_a[(state_a[0] + 1) % state_a[3]] = list_a[state_a[0]];
	list_a[state_a[0]] = temp;
	if (silence == 0)
		write(1, "sa\n", 3);
	return(1);
}	

int	swap_b(int *list_b, int *state_b, int silence)
{
	int	temp;
	if (state_b[2] <= 1)
		return (0);
	temp = list_b[(state_b[0] + 1) % state_b[3]];
	list_b[(state_b[0] + 1) % state_b[3]] = list_b[state_b[0]];
	list_b[state_b[0]] = temp;
	if (silence == 0)
		write(1, "sb\n", 3);
	return(1);
}
int	swap_double(int *list_a, int *state_a, int *list_b, int *state_b)
{
	swap_a(list_a, state_a, 1);
	swap_b(list_b, state_b, 1);
	write(1, "ss\n", 3);
	return(1);
}