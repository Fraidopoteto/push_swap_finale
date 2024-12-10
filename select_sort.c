/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun <joschmun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:27:17 by joschmun          #+#    #+#             */
/*   Updated: 2024/12/10 13:09:05 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_to_top(int *stack_a, int i, int pivot)
{
	int	j;

	j = 1;
	while (stack_a[j - 1] != i && stack_a[j - 1])
		j++;
	if (j > pivot)
	{
		while (stack_a[0] != i)
			ft_reverse_rotate(stack_a, 'a');
	}
	else
	{
		while (stack_a[0] != i)
			ft_rotate(stack_a, 'a');
	}
}

void	ft_jonas_sort(int *stack_a, int *stack_b, int arg_count)
{
	int	i;
	int	pivot;

	i = 1;
	pivot = (arg_count / 2);
	while (i < arg_count)
	{
		ft_move_to_top(stack_a, i, pivot);
		pivot--;
		ft_push_1_to_2(stack_a, stack_b, 'b');
		i++;
	}
	ft_push_back(stack_b, stack_a, arg_count, 'a');
}
