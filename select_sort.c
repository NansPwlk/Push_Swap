/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 17:27:13 by npawlak           #+#    #+#             */
/*   Updated: 2026/04/07 17:27:13 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_sort(int *list_a, int *list_b, int state[2][4])
{
	while (state[0][2] != 0)
	{
		make_in_order(list_a, state);
		push_b(list_a, list_b, state);
	}
	while (state[1][2] != 0)
		push_a(list_b, list_a, state);
}
