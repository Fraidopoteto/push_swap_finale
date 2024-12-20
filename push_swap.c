/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:52:02 by joschmun          #+#    #+#             */
/*   Updated: 2024/12/12 13:48:26 by Furaido          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(int *stack)
{
	if (stack[0] > stack[1])
		ft_swap(stack, 'a');
}

void	ft_sort_three(int *stack)
{
	if (stack[0] < stack[1] && stack[1] > stack[2] )
		ft_reverse_rotate(stack, 'a');
	if (stack[0] > stack[1] && stack[1] > stack[2] )
	{
		ft_swap(stack, 'a');
		ft_reverse_rotate(stack, 'a');
	}
	while (1)
	{
		if ((stack[0] < stack[1]) && (stack[1] < stack[2]))
			break ;
		else if (stack[0] < stack[1])
			ft_swap(stack, 'a');
		else
			ft_rotate(stack, 'a');
	}
}

void	ft_sort_four(int *stack_a, int *stack_b)
{
	while (stack_a[0] != 1)
		ft_rotate(stack_a, 'a');
	ft_push_1_to_2(stack_a, stack_b, 'b');
	ft_sort_three(stack_a);
	ft_push_1_to_2(stack_b, stack_a, 'a');
}

void	ft_radix_sort(int *stack_a, int *stack_b, int arg_count)
{
	int	max_bits;
	int	max_num;
	int	i;
	int	j;

	max_bits = 0;
	max_num = arg_count - 1;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < arg_count)
		{
			if (((stack_a[0] >> i) & 1) == 1)
				ft_rotate(stack_a, 'a');
			else
				ft_push_1_to_2(stack_a, stack_b, 'b');
			j++;
		}
		while (ft_numlen(stack_b) > 0)
			ft_push_1_to_2(stack_b, stack_a, 'a');
		i++;
	}
}

void ft_sort_five(int *stack_a, int *stack_b)
{
	int	j;
	int	pivet;

	j = 1;
	pivet = ft_numlen(stack_a) / 2;
	while (j != 3)
	{
		ft_move_to_stack_b(stack_a, stack_b, j, pivet);
		j++;
	}
	ft_sort_three(stack_a);
	if (stack_b[0] < stack_b[1])
		ft_swap(stack_b, 'b');
	ft_push_1_to_2(stack_b, stack_a, 'a');
	ft_push_1_to_2(stack_b, stack_a, 'a');
}
