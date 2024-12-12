/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:52:20 by joschmun          #+#    #+#             */
/*   Updated: 2024/10/31 21:52:20 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_convert(char **argv, int arg_count)
{
	int	*arg_value;
	int	i;

	i = 0;
	if (ft_num_check(argv))
		return (NULL);
	arg_value = malloc(arg_count * sizeof(int));
	if (!arg_value)
		return (NULL);
	while (arg_count > i)
	{
		arg_value[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (arg_value);
}

int	*ft_simplify(int *arg_value, int arg_count)
{
	int			*arg_simple;
	t_indices	indices;

	ft_init_simplify(&indices);
	if (arg_value == NULL)
		return (NULL);
	arg_simple = malloc((arg_count + 1) * sizeof(int));
	arg_simple[arg_count] = 0;
	if (!arg_simple)
		return (NULL);
	while (indices.position < arg_count)
	{
		while (indices.checker < arg_count)
		{
			if (arg_value[indices.position] > arg_value[indices.checker])
				indices.value++;
			indices.checker++;
		}
		arg_simple[indices.position] = indices.value;
		indices.position++;
		indices.checker = 0;
		indices.value = 1;
	}
	free (arg_value);
	return (arg_simple);
}

int	ft_numlen(int *num)
{
	int	i;

	i = 0;
	while (num[i])
		i++;
	return (i);
}

int	*ft_intdup(int *stack)
{
	int	*cpy;
	int	len;
	int	i;

	len = ft_numlen(stack);
	cpy = malloc((len + 1) * sizeof(int));
	i = 0;
	if (cpy == NULL)
		return (NULL);
	else
	{
		while (i < (len + 1))
		{
			cpy[i] = stack[i];
			i++;
		}
	}
	return (cpy);
}

void	ft_push_back(int *stack_1, int *stack_2, int arg_count, char a_or_b)
{
	int	i;

	i = 0;
	while (i < arg_count)
	{
		ft_push_1_to_2(stack_1, stack_2, a_or_b);
		i++;
	}
}
