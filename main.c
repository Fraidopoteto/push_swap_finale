/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:34:27 by joschmun          #+#    #+#             */
/*   Updated: 2024/10/31 22:34:27 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*init_arguments(int argc, char **argv, int *arg_count)
{
	int	*arg_simple;

	*arg_count = argc - 1;
	arg_simple = NULL;
	if (argc == 2)
		arg_simple = ft_swap_str(argv);
	else if (argc > 2)
		arg_simple = ft_simplify(ft_convert(argv, *arg_count), *arg_count);
	if ((ft_sort_check(arg_simple) || ft_check_double(arg_simple)) \
	&& (ft_numlen(arg_simple) > 1))
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	return (arg_simple);
}

void	ft_sort_two(int *stack)
{
	if (stack[0] > stack[1])
		ft_swap(stack, 'a');
}

void	ft_sort(int *arg_simple, int *stack_b)
{
	if (ft_numlen(arg_simple) == 1)
		return ;
	if (ft_numlen(arg_simple) == 2)
		ft_sort_two(arg_simple);
	else if (ft_numlen(arg_simple) == 3)
		ft_sort_three(arg_simple);
	else if (ft_numlen(arg_simple) == 4)
		ft_sort_four(arg_simple, stack_b);
	else if (ft_numlen(arg_simple) == 5)
		ft_sort_five(arg_simple, stack_b);
	else if (ft_numlen(arg_simple) >= 6 && ft_numlen(arg_simple) <= 26)
		ft_jonas_sort(arg_simple, stack_b, ft_numlen(arg_simple));
	else
		ft_radix_sort(arg_simple, stack_b, ft_numlen(arg_simple));
}

int	main(int argc, char **argv)
{
	int	arg_count;
	int	*arg_simple;
	int	*stack_b;

	if (argc < 2)
		return (0);
	if (argv[1][0] == '\0')
		return (0);
	arg_simple = init_arguments(argc, argv, &arg_count);
	if (!arg_simple)
	{
		free (arg_simple);
		return (1);
	}
	stack_b = calloc((ft_numlen(arg_simple) + 1), sizeof(int));
	if (!stack_b)
	{
		free(arg_simple);
		return (1);
	}
	ft_sort(arg_simple, stack_b);
	free(arg_simple);
	free(stack_b);
	return (0);
}
