/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 16:27:06 by npawlak           #+#    #+#             */
/*   Updated: 2026/04/07 16:27:06 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	get_targ(int b_val, int *list_a, int state[2][4], int i)
{
	int		ret[2];
	long	val[2];

	i = -1;
	ret[0] = 0;
	ret[1] = 0;
	val[0] = 3000000000;
	val[1] = 3000000000;
	while (++i < state[0][2])
	{
		if (list_a[(state[0][0] + i) % state[0][3]] > b_val
			&& list_a[(state[0][0] + i) % state[0][3]] < val[0])
		{
			val[0] = list_a[(state[0][0] + i) % state[0][3]];
			ret[0] = i;
		}
		if (list_a[(state[0][0] + i) % state[0][3]] < val[1])
		{
			val[1] = list_a[(state[0][0] + i) % state[0][3]];
			ret[1] = i;
		}
	}
	if (val[0] == 3000000000)
		return (ret[1]);
	return (ret[0]);
}
