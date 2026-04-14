/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:44:59 by npawlak           #+#    #+#             */
/*   Updated: 2026/02/02 18:51:24 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(void *ptr, int	*count)
{
	if (!ptr)
	{
		write(1, "(nil)", 5);
		*count = *count + 5;
	}
	else
	{
		write(1, "0x", 2);
		base_16((unsigned long) ptr, count, "0123456789abcdef");
		*count = *count + 2;
	}
}

void	base_16(unsigned long adr, int	*count, char *base16)
{
	char	buffer[20];
	int		i;

	i = 0;
	if (adr == 0)
	{
		ft_putchar_fd('0', 1, 0, count);
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
		ft_putchar_fd(buffer[i], 1, 0, count);
	}
}
