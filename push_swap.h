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
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void		fill_stack_a(int *list_a, int argc, char **argv);
void		exit_error(void);
int			main(int argc, char **argv);
int			push_swap(int *list_a, int size);
int			push_a(int *list_b, int *list_a, int *state_a, int *state_b);
int			push_b(int *list_a, int *list_b, int *state_a, int *state_b);
void		init_state(int *state_a, int *state_b, int size);
int			rotate_a(int *list_a, int *state_a, int silence);
int			rotate_b(int *list_b, int *state_b, int silence);
int			reverse_rotate_a(int *list_a, int *state_a, int silence);
int			reverse_rotate_b(int *list_b, int *state_b, int silence);
int			rotate_double(int *list_a, int *state_a, int *list_b, int *state_b);
int			revrot_double(int *list_a, int *state_a, int *list_b, int *state_b);
int			swap_a(int *list_a, int *state_a, int silence);
int			swap_b(int *list_b, int *state_b, int silence);
int			swap_double(int *list_a, int *state_a, int *list_b, int *state_b);
void		print_list(int *list_a, int *list_b, int *state_a, int *state_b);

#endif