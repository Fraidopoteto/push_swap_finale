/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun <joschmun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:22:21 by joschmun          #+#    #+#             */
/*   Updated: 2024/12/04 14:17:49 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *stack, char a_or_b)
{
	int	*temp;

	temp = malloc(2 * sizeof(int));
	temp[0] = stack[0];
	temp[1] = stack[1];
	stack[0] = temp[1];
	stack[1] = temp[0];
	free (temp);
	write(1, "s", 1);
	write(1, &a_or_b, 1);
	write(1, "\n", 1);
}

void	ft_rotate(int *stack, char a_or_b)
{
	int	*temp;
	int	len;
	int	i;

	i = 0;
	len = ft_numlen(stack);
	temp = ft_intdup(stack);
	stack[len - 1] = temp[0];
	while (i < len - 1)
	{
		stack[i] = temp[i + 1];
		i++;
	}
	free(temp);
	write(1, "r", 1);
	write(1, &a_or_b, 1);
	write(1, "\n", 1);
}

void	ft_reverse_rotate(int *stack, char a_or_b)
{
	int	*temp;
	int	len;
	int	i;

	i = 0;
	len = ft_numlen(stack);
	temp = ft_intdup(stack);
	stack[0] = temp[len - 1];
	while (i < len - 1)
	{
		stack[i + 1] = temp[i];
		i++;
	}
	free(temp);
	write(1, "rr", 2);
	write(1, &a_or_b, 1);
	write(1, "\n", 1);
}

void	ft_push_1_to_2(int *stack_1, int *stack_2, char a_or_b)
{
	int	*temp_1;
	int	*temp_2;
	int	len_1;
	int	len_2;

	if (stack_1[0] == 0)
		return ;
	len_1 = ft_numlen(stack_1);
	len_2 = ft_numlen(stack_2);
	temp_1 = ft_intdup(stack_1);
	temp_2 = ft_intdup(stack_2);
	stack_2[0] = temp_1[0];
	ft_push_up(stack_2, temp_2, len_2);
	ft_push_down(stack_1, temp_1, len_1);
	free(temp_1);
	free(temp_2);
	write(1, "p", 1);
	write(1, &a_or_b, 1);
	write(1, "\n", 1);
}
