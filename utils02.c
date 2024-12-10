/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun <joschmun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:44:58 by joschmun          #+#    #+#             */
/*   Updated: 2024/12/10 16:06:00 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_down(int *stack, int *temp, int len)
{
	int	i;

	i = 0;
	while (i < (len - 1))
	{
		stack[i] = temp[i + 1];
		i++;
	}
	stack[i] = 0;
}

char	**ft_split_swap(char **argv)
{
	char	**temp;

	temp = ft_split(argv[1], ' ');
	if (ft_num_check(temp) == 1)
		return (NULL);
	return (temp);
}

int	*ft_convert_split(char **argv, int size)
{
	int	*arg_value;
	int	i;

	arg_value = malloc(size * sizeof(int));
	if (!arg_value)
		return (NULL);
	i = 0;
	while (size > i)
	{
		arg_value[i] = ft_atoi(argv[i]);
		i++;
	}
	return (arg_value);
}

int	ft_arraylen(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	*ft_swap_str(char **argv)
{
	char	**temp;
	int		size;
	int		*arg_simple;
	int		i;

	i = 0;
	temp = ft_split_swap(argv);
	if (temp == NULL)
	{
		free (temp);
		return (NULL);
	}
	size = ft_arraylen(temp);
	arg_simple = ft_simplify(ft_convert_split(temp, size), size);
	free (temp);
	return (arg_simple);
}
