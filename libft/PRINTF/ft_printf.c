/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:28:04 by npawlak           #+#    #+#             */
/*   Updated: 2026/04/14 13:46:44 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_bis(const char *str, int *i, va_list *args, int *count)
{
	if (str[*i] == 'c')
		print_char(va_arg(*args, int), count);
	else if (str[*i] == 's')
		print_string(va_arg(*args, char *), count);
	else if (str[*i] == 'p')
		print_pointer(va_arg(*args, void *), count);
	else if (str[*i] == 'd' || str[*i] == 'i')
		print_int_dec(va_arg(*args, int), count, 0);
	else if (str[*i] == 'u')
		print_unsigned(va_arg(*args, unsigned int), count, 0);
	else if (str[*i] == 'x')
		base_16x(va_arg(*args, int), count, "0123456789abcdef");
	else if (str[*i] == 'X')
		base_16x(va_arg(*args, int), count, "0123456789ABCDEF");
	else if (str[*i] == '%')
		print_pe+rcent(count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	if (!str)
		return (0);
	va_start(args, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_printf_bis(str, &i, &args, &count);
		}
		else
			ft_putchar_fd(str[i], 1, 1, &count);
		i++;
	}
	va_end(args);
	return (count);
}
