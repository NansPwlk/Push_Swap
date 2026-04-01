/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:48:29 by npawlak           #+#    #+#             */
/*   Updated: 2026/03/04 12:48:29 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_state(int *state_a, int *state_b, int size)
{
	state_a[0] = 0;
	state_a[1] = size - 1;
	state_a[2] = size;
	state_a[3] = size;
	state_b[0] = 0;
	state_b[1] = 0;
	state_b[2] = 0;
	state_b[3] = size;
}
