/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:45:04 by npawlak           #+#    #+#             */
/*   Updated: 2026/04/14 14:07:26 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		ft_putcharb_fd(nbr_print[size], 1, 1, count);
}
