/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 23:36:55 by npawlak           #+#    #+#             */
/*   Updated: 2025/12/13 23:36:55 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str, int *list_a);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t	ft_strlen(const char *s);
int		ft_printf(const char *str, ...);
void	ft_putcharb_fd(char c, int fd, int isopti, int *count);
void	print_char(char c, int *count);
void	print_string(char *str, int *count);
void	print_pointer(void *ptr, int *count);
void	base_16(unsigned long adr, int *count, char *base16);
void	ft_printf_bis(const char *str, int *i, va_list *args, int *count);
void	print_int_dec(int nbr, int *count, int size);
void	print_unsigned(unsigned int nbr, int *count, int size);
void	base_16x(unsigned int adr, int	*count, char *base16);
void	print_percent(int *count);
void	exit_error_lib(int *to_free);

#endif