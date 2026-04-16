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

void		fill_stack_a(int *list_a, int argc, char **argv, int i);
void		exit_error(void);
int			main(int argc, char **argv);
int			push_swap(int *list_a, int size, int do_a_bench, int who);
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
void		order_in_make(int *list_b, int state[2][4], int *debt);
int			*one_chunk(int state[2][4], int *cpy_lst);
void		push_chunk(int *list_a, int *list_b, int state[2][4], int *opt_chk);
int			do_i_rotate(int *list_b, int state[2][4], int *opt_chk);
int			*get_cpy_sort(int *lst, int state[2][4], int *cpy_lst, int is_ord);
int			is_in_chunk(int value, int *opt_chk);
void		get_podium(int *list_b, int state[2][4], int *i_max, int *i_max2);
void		repatriate_to_a(int *list_a, int *list_b, int state[2][4]);
float		compute_disorder(int *list_a, int state[2][4], int who);
void		adapt_choice(int *lst_a, int *lst_b, int state[2][4], float disord);
int			handle_miss(int *list_a, int *list_b, int state[2][4], int need_rb);
int			*count_op(int wich_one);
void		benchmod(int *lst_a, int state[2][4], int who);
void		benchmod_op(int *tl_op);
int			read_flag(int who);
int			wich_flag(char *flag, char *flagbis);
int			do_a_flag(int argc, char **argv, int who);
void		init_flag(char **flag, char **flagbis, char **argv, int argc);
int			is_number(char *do_he);
int			*for_two(int *list_a, int state[2][4]);
int			*for_three(int *list_a, int state[2][4]);
int			*for_four(int *list_a, int *list_b, int state[2][4]);
int			*for_five(int *list_a, int *list_b, int state[2][4]);
#endif