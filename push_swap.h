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
int			push_a(int *list_b, int *list_a, int state[2][4]);
int			push_b(int *list_a, int *list_b, int state[2][4]);
void		init_state(int state[2][4], int size);
int			rotate_a(int *list_a, int state[2][4], int silence);
int			rotate_b(int *list_b, int state[2][4], int silence);
int			reverse_rotate_a(int *list_a, int state[2][4], int silence);
int			reverse_rotate_b(int *list_b, int state[2][4], int silence);
int			rotate_double(int *list_a, int state[2][4], int *list_b);
int			revrot_double(int *list_a, int state[2][4], int *list_b);
int			swap_a(int *list_a, int state[2][4], int silence);
int			swap_b(int *list_b, int state[2][4], int silence);
int			swap_double(int *list_a, int state[2][4], int *list_b);
void		print_list(int *list_a, int *list_b, int state[2][4]);
void		greed_sort(int *list_a, int *list_b, int state[2][4]);
int			free_error(int *scores, int *path, int *next_index);
int			init_tab(int state[2][4], int *scores, int *next_index, int *path);
int			fnd_pth(int *list_a, int state[2][4], int *scores, int *next_index);
int			*init_alg(int *list_a, int state[2][4]);
int			*calc_matrix(int *list_a, int *list_b, int state[2][4]);
int			*calc_matrix_bis(int *cm, int *bm);
int			*copy_matrix(int *cost_matrix, int *best_matrix, int bs, int first);
void		sort_path(int *list_a, int *list_b, int state[2][4], int *matr);
void		exec_rotates(int *list_a, int *list_b, int state[2][4], int *matr);
void		exec_rev_rot(int *list_a, int *list_b, int state[2][4], int *matr);
void		exec_mix_a_up(int *list_a, int *list_b, int state[2][4], int *matr);
void		exec_mix_b_up(int *list_a, int *list_b, int state[2][4], int *matr);
int			*mat_path(int *list_a, int *list_b, int state[2][4], int *matrix);
void		minus_one(int *matrix);
void		make_in_order(int *list_a, int state[2][4]);
int			get_targ(int b_val, int *list_a, int state[2][4], int i);
void		select_sort(int *list_a, int *list_b, int state[2][4]);
void		chunk_sort(int *list_a, int *list_b, int state[2][4]);
int			*index_chunk(int *list_a, int state[2][4]);
int			chunk_repart(int state[2][4]);
void		order_in_make(int *list_b, int state[2][4]);
int			*one_chunk(int state[2][4], int *cpy_lst);
void		push_chunk(int *list_a, int *list_b, int state[2][4], int *opt_chk);
void		do_i_rotate(int *list_b, int state[2][4], int *opt_chk);
int			*get_cpy_sort(int *lst, int state[2][4], int *cpy_lst, int is_ord);
int			is_in_chunk(int value, int *opt_chk);
float		compute_disorder(int *list_a, int state[2][4]);
void		adapt_choice(int *lst_a, int *lst_b, int state[2][4], float	disord);
#endif