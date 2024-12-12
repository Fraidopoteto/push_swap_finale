/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:43:43 by joschmun          #+#    #+#             */
/*   Updated: 2024/12/12 11:44:30 by Furaido          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_up(int *stack, int *temp, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		stack[i + 1] = temp[i];
		i++;
	}
	stack[i + 1] = 0;
}

int	ft_num_check(char **stack)
{
	int	j;
	int	i;

	j = 1;
	while (stack[j])
	{
		i = 0;
		while (stack[j][i] == ' ' || stack[j][i] == '+' || stack[j][i] == '-')
			i++;
		if (!ft_isdigit(stack[j][i]))
			return (1);
		while (ft_isdigit(stack[j][i]))
			i++;
		if (stack[j][i] != '\0')
			return (1);
		j++;
	}
	return (0);
}
int	ft_num_check_split(char **stack)
{
	int	j;
	int	i;

	j = 0;
	while (stack[j])
	{
		i = 0;
		while (stack[j][i] == ' ' || stack[j][i] == '+' || stack[j][i] == '-')
			i++;
		if (!ft_isdigit(stack[j][i]))
			return (1);
		while (ft_isdigit(stack[j][i]))
			i++;
		if (stack[j][i] != '\0')
			return (1);
		j++;
	}
	return (0);
}

int	ft_check_double(int *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stack[i])
	{
		while (stack[j])
		{
			if (j == i)
				j++;
			if (stack[j] == stack[i])
				return (1);
			if (stack[j] != '\0')
				j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_sort_check(int *stack)
{
	int	i;

	i = 1;
	while (stack[i - 1])
	{
		if (stack[i - 1] != i)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
