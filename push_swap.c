/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 23:47:41 by npawlak           #+#    #+#             */
/*   Updated: 2026/03/03 23:47:41 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_duplicate(int *list, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (list[i] == value)
			return (1);
		i++;
	}
	return (0);
}

void	fill_stack_a(int *list_a, int argc, char **argv, int i)
{
	long	tmp;
	int j;

	j = 0;
	while (j < argc - 1 - i)
	{
		if (!is_number(argv[j + 1 + i]))
		{
			free(list_a);
			exit_error();
		}
		tmp = ft_atoi(argv[j + 1 + i], list_a);
		if (has_duplicate(list_a, j, (int)tmp))
		{
			free(list_a);
			exit_error();
		}
		list_a[j] = (int)tmp;
		j++;
	}
}

int	push_swap(int *list_a, int size, int do_a_bench, int who)
{
	int		*list_b;
	int		state[2][4];
	float	disorder;

	list_b = malloc(sizeof(int) * size);
	if (!list_b)
		return (1);
	init_state(state, size);
	disorder = compute_disorder(list_a, state, 1);
	who = do_a_flag(1, NULL, 2);
	if (do_a_bench == 1)
	{
		if (who == 0)
			adapt_choice(list_a, list_b, state, disorder);
		else
			adapt_choice(list_a, list_b, state, who);
		benchmod(list_a, state, who);
	}
	else if (who == 0)
		adapt_choice(list_a, list_b, state, disorder);
	else
		adapt_choice(list_a, list_b, state, who);
	free(list_b);
	return (1);
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	size;
	int do_a_bench;
	int i;

	i = 0;
	if (argc < 2)
		return (0);
	if (ft_strncmp(argv[1], "--", 2) == 0)
	{
		i = 1;
		if(argc > 2 && ft_strncmp(argv[2], "--", 2) == 0)
			i = 2;
	}
	size = argc - 1 - i;
	stack_a = malloc(sizeof(int) * size);
	if (!stack_a)
		return (1);
	do_a_bench = do_a_flag(argc, argv, 0);
	fill_stack_a(stack_a, argc, argv, i);
	if (argc > 3 && argv[3][1] == '-')
		exit_error();
	push_swap(stack_a, size, do_a_bench, 0);
	free(stack_a);
	return (0);
}
