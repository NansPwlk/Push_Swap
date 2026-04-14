/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xuplo_16.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:45:06 by npawlak           #+#    #+#             */
/*   Updated: 2026/04/14 14:07:30 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	base_16x(unsigned int adr, int	*count, char *base16)
{
	char	buffer[20];
	int		i;

	i = 0;
	if (adr == 0)
	{
		ft_putcharb_fd('0', 1, 0, count);
		(*count)++;
	}
	while (adr > 0)
	{
		buffer[i] = base16[adr % 16];
		adr = adr / 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		(*count)++;
		ft_putcharb_fd(buffer[i], 1, 0, count);
	}
}
