/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npawlak <npawlak@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 11:23:23 by npawlak           #+#    #+#             */
/*   Updated: 2026/04/15 11:23:23 by npawlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_a_flag(int argc, char **argv, int who)
{
	static char	*flag = NULL;
	static char	*flagbis = NULL;
	static int	do_a_what = 0;

	if (who == 1)
		return (do_a_what);
	if (who == 2)
		return (read_flag(do_a_what));
	if (argc > 1 && argv != NULL)
		init_flag(&flag, &flagbis, argv, argc);
	if (flag == NULL || flag[0] != '-' || flag[1] != '-')
		return (0);
	do_a_what = wich_flag(flag, flagbis);
	if (who == 0 && (ft_strncmp(flag, "--bench", 7) == 0
			|| (flagbis && ft_strncmp(flagbis, "--bench", 7) == 0)))
		return (1);
	return (0);
}

int	wich_flag(char *flag, char *flagbis)
{
	if (ft_strncmp(flag, "--simple", 8) == 0
		|| ft_strncmp(flagbis, "--simple", 8) == 0)
		return (2);
	if (ft_strncmp(flag, "--medium", 8) == 0
		|| ft_strncmp(flagbis, "--medium", 8) == 0)
		return (3);
	if (ft_strncmp(flag, "--complex", 9) == 0
		|| ft_strncmp(flagbis, "--complex", 9) == 0)
		return (4);
	if (ft_strncmp(flag, "--adaptative", 12) == 0
		|| ft_strncmp(flagbis, "--adaptative", 12) == 0)
		return (5);
	else
		return (0);
}

int	read_flag(int who)
{
	if (who == 2)
		return (12);
	if (who == 3)
		return (22);
	if (who == 4)
		return (32);
	if (who == 5)
		return (42);
	return (0);
}

void	init_flag(char **flag, char **flagbis, char **argv, int argc)
{
	*flag = argv[1];
    if (argc > 2)
    	*flagbis = argv[2];
}
