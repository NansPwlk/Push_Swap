/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharb_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 03:35:29 by npawlak           #+#    #+#             */
/*   Updated: 2025/12/14 03:35:29 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putcharb_fd(char c, int fd, int isopti, int *count)
{
	fd = 2;
	if (isopti == 1)
	{
		write(fd, &c, 1);
		(*count)++;
	}
	else
		write(fd, &c, 1);
}
