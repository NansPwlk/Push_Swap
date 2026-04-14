/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:45:04 by npawlak           #+#    #+#             */
/*   Updated: 2026/02/02 18:52:19 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsigned(unsigned int nbr, int *count, int size)
{
	char	nbr_print[10];

	size = 0;
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
