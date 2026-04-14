/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:30:38 by npawlak           #+#    #+#             */
/*   Updated: 2026/04/14 12:30:38 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *count_op(int wich_one)
{
	static int total_op[11];

	if (wich_one == 1)
		total_op[0] = total_op[0] + 1;
	if (wich_one == 2)
		total_op[1] = total_op[1] + 1;
	if (wich_one == 3)
		total_op[2] = total_op[2] + 1;
	if (wich_one == 4)
		total_op[3] = total_op[3] + 1;
	if (wich_one == 5)
		total_op[4] = total_op[4] + 1;
	if (wich_one == 6)
		total_op[5] = total_op[5] + 1;
	if (wich_one == 7)
		total_op[6] = total_op[6] + 1;
	if (wich_one == 8)
		total_op[7] = total_op[7] + 1;
	if (wich_one == 9)
		total_op[8] = total_op[8] + 1;
	if (wich_one == 10)
		total_op[9] = total_op[9] + 1;
	if (wich_one == 11)
		total_op[10] = total_op[10] + 1;
	return(total_op);
}

void benchmod(int *lst_a, int state[2][4])
{
	float disord;
	int integer_part;
    int fractional_part;

	disord = compute_disorder(lst_a, state, 0);
	integer_part = (int)disord;
	fractional_part = (int)((disord - integer_part) * 100.0 + 0.5);
	if (fractional_part >= 100)
    {
        integer_part++;
        fractional_part -= 100;
    }
	if (fractional_part < 10)
        ft_printf("Disorder: %d.0%d\n", integer_part, fractional_part);
    else
		ft_printf("Disorder: %d.%d\n", integer_part, fractional_part);
	if (disord < 0.2)
		ft_printf("Strategy: Simple /  O(n²)");
	else if (disord >= 0.2 && disord < 0.5)
		ft_printf("Strategy: Medium /  O(n√n)");
	else if (disord >= 0.5)
		ft_printf("Strategy: Complex /  O(n log n)");
	else if (disord == 0)
		ft_printf("Strategy: Adaptative");
	ft_printf("total_ops : %d", count_op(12));
}
