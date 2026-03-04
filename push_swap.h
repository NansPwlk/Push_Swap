/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 23:47:38 by npawlak           #+#    #+#             */
/*   Updated: 2026/03/03 23:47:38 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>

void		fill_stack_a(int *list_a, int argc, char **argv);
static void	exit_error(void);
static int	has_duplicate(int *list, int size, int value);
int			main(int argc, char **argv);
int			push_swap(int *list_a, int size);
int			push_a(int *list_b, int *list_a, int *top, int *bottom);
int			push_b(int *list_a, int *list_b, int *top, int *bottom);
int			init_state(int *state_a, int *state_b, int size);

#endif