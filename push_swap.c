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

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	fill_stack_a(int *list_a, int argc, char **argv)
{
	int		i;
	long	tmp;

	i = 0;
	while (i < argc - 1)
	{
		tmp = ft_atoi(argv[i + 1]);
		if (tmp < -2147483648 || tmp > 2147483647)
			exit_error();
		if (has_duplicate(list_a, i, (int)tmp))
			exit_error();
		list_a[i] = (int)tmp;
		i++;
	}
}

int	push_swap(int *list_a, int size)
{
	int	*list_b;
	int	state_a[4];
	int	state_b[4];

	list_b = malloc(sizeof(int) * size);
	if (!list_a)
		return (1);
	init_state(state_a, state_b, size);
	push_b(list_a, list_b, state_a, state_b);
	push_b(list_a, list_b, state_a, state_b);
	push_b(list_a, list_b, state_a, state_b);
	push_b(list_a, list_b, state_a, state_b);
	push_b(list_a, list_b, state_a, state_b);
	swap_double(list_a, state_a, list_b, state_b);
	print_list(list_a, list_b, state_a, state_b);
	free(list_b);
	return(1);
}

void	print_list(int *list_a, int *list_b, int *state_a, int *state_b)
{
	int i;
	i = 0;
	write(1, "list a\n", 7);
	if (state_a[2] == 0)
		write(1, "liste vide\n", 11);
	while ( i < state_a[2])
	{
		ft_putnbr_fd(list_a[(state_a[0] + i) % state_a[3]], 1);
		write(1, "-", 1);
		i++;
	}
	write(1, "\n", 1);
	write(1, "list b\n", 7);
	i = 0;
	if (state_b[2] == 0)
		write(1, "liste vide\n", 11);
	while ( i < state_b[2])
	{
		ft_putnbr_fd(list_b[(state_b[0] + i) % state_b[3]], 1);
		write(1, "-", 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	*list_a;
	int	size;

	if (argc < 2)
		return (0);
	size = argc - 1;
	list_a = malloc(sizeof(int) * size);
	if (!list_a)
		return (1);
	fill_stack_a(list_a, argc, argv);
	push_swap(list_a, size);
	free(list_a);
	return (0);
}
