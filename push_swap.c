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

static void	exit_error(void)
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

int	push_swap(int *list_a, size)
{
	int	*list_b;
	int	**;
	int	*state_a[4];
	int	*state_b[4];

	list_b = malloc(sizeof(int) * size);
	if (!list_a)
		return (1);
	push_a(list_b, list_a, &top, &bottom);
	free(list_b);
	return(list_a);
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
