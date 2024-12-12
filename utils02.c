/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:44:58 by joschmun          #+#    #+#             */
/*   Updated: 2024/12/12 11:46:15 by Furaido          ###   ########.fr       */
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
	return (temp);
}

int	*ft_convert_split(char **argv, int size)
{
	int	*arg_value;
	int	i;

	if (ft_num_check_split(argv))
		return (NULL);
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
	size = ft_arraylen(temp);
	if (temp == NULL)
	{
		free (temp);
		return (NULL);
	}
	arg_simple = ft_simplify(ft_convert_split(temp, size), size);
	while (i < size)
	{
		free (temp[i]);
		i++;
	}
	free (temp);
	return (arg_simple);
}
