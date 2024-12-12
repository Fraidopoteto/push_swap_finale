/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:15:29 by Furaido           #+#    #+#             */
/*   Updated: 2024/12/12 14:31:28 by Furaido          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_space(char **argv)
{
	int		i;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_double_space(char **argv)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (argv[1][0] == ' ' && ft_strlen(argv[1]) == 1)
		return (0);
	while (argv[1][i])
	{
		if (argv[1][i] == ' ')
			j++;
		i++;
		if (j && argv[1][i] == ' ')
			return (0);
		j = 0;
	}
	return (1);
}

void ft_move_to_stack_b(int *stack_a, int *stack_b, int j, int pivet)
{
	int	i;

	i = 0;
	while (stack_a[i] != j)
		i++;
	if (i > pivet)
	{
		while (stack_a[0] != j)
			ft_reverse_rotate(stack_a, 'a');
	}
	else
	{
		while (stack_a[0] != j)
			ft_rotate(stack_a, 'a');
	}
	ft_push_1_to_2(stack_a, stack_b, 'b');
}

void	ft_init_simplify(t_indices *indices)
{
	indices->value = 1;
	indices->position = 0;
	indices->checker = 0;
}
