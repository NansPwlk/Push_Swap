/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:45:01 by npawlak           #+#    #+#             */
/*   Updated: 2026/04/14 14:07:21 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_string(char *str, int	*count)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putcharb_fd(str[i], 1, 0, count);
		(*count)++;
		i++;
	}
}
