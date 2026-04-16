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

int	*count_op(int wich_one)
{
	static int	total_op[11];

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
	return (total_op);
}

void	benchmod(int *lst_a, int state[2][4], int who)
{
	float	disord;
	int		integer_part;
	int		fractional_part;
	int		*total_op;

	total_op = count_op(12);
	disord = compute_disorder(lst_a, state, 0);
	integer_part = (int)disord;
	fractional_part = (int)((disord - integer_part) * 100.0);
	if (fractional_part < 10)
		ft_printf("Disorder: %d.0%d\n", integer_part, fractional_part);
	else
		ft_printf("Disorder: %d.%d\n", integer_part, fractional_part);
	if (disord < 0.2 || who == 12)
		ft_printf("Strategy: Simple /  O(n²)\n");
	else if ((disord >= 0.2 && disord < 0.5) || who == 22)
		ft_printf("Strategy: Medium /  O(n√n)\n");
	else if (disord >= 0.5 || who == 32)
		ft_printf("Strategy: Complex /  O(n log n)\n");
	else if (disord == 0 || who == 42)
		ft_printf("Strategy: Adaptative\n");
	benchmod_op(total_op);
}

void	benchmod_op(int *tl_op)
{
	int	total;
	int	i;

	total = 0;
	i = -1;
	while (++i <= 10)
		total = total + tl_op[i];
	ft_printf("total_ops : %d\n", total);
	ft_printf("sa : %d, sb : %d, ss : %d\n", tl_op[0], tl_op[1], tl_op[2]);
	ft_printf("pa : %d, pb : %d\n", tl_op[3], tl_op[4]);
	ft_printf("ra : %d, rb : %d, rr : %d\n", tl_op[5], tl_op[6], tl_op[7]);
	ft_printf("rra : %d, rrb : %d, rrr : %d\n", tl_op[8], tl_op[9], tl_op[10]);
}
