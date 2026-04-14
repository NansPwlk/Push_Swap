/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:44:54 by npawlak           #+#    #+#             */
/*   Updated: 2026/02/02 18:50:42 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int_dec(int nbr, int *count, int size)
{
	char	nbr_print[11];

	size = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count = *count + 11;
		return ;
	}
	if (nbr < 0)
	{
		nbr = nbr * -1;
		ft_putchar_fd('-', 1, 1, count);
	}
	while (nbr >= 10)
	{
		nbr_print[size] = (nbr % 10) + 48;
		nbr = nbr / 10;
		size++;
	}
	nbr_print[size] = (nbr % 10) + 48;
	size++;
	while (size-- > 0)
		ft_putchar_fd(nbr_print[size], 1, 1, count);
}
