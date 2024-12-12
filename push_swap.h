/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:01:52 by joschmun          #+#    #+#             */
/*   Updated: 2024/12/12 13:48:12 by Furaido          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_indices_simplify
{
	int	value;
	int	position;
	int	checker;
}	t_indices;

//utils.c
int		*ft_simplify(int *arg_value, int arg_count);
int		*ft_convert(char **argv, int arg_count);
int		ft_numlen(int *num);
int		*ft_intdup(int *stack);
void	ft_push_back(int *stack_1, int *stack_2, int arg_count, char a_or_b);
void	ft_push_down(int *stack, int *temp, int len);
void	ft_push_up(int *stack, int *temp, int len);
int		ft_num_check(char **stack);
int		ft_num_check_split(char **stack);
int		ft_check_double(int *stack);
int		ft_sort_check(int *stack);
char	**ft_split_swap(char **argv);
int		ft_arraylen(char **array);
int		*ft_swap_str(char **argv);
int		ft_check_double_space(char **argv);
void	ft_init_simplify(t_indices *indices);
void	ft_move_to_stack_b(int *stack_a, int *stack_b, int j, int pivet);

//operation.c
void	ft_swap(int *stack, char a_or_b);
void	ft_reverse_rotate(int *stack, char a_or_b);
void	ft_rotate(int *stack, char a_or_b);
void	ft_push_1_to_2(int *stack_1, int *stack_2, char a_or_b);

//push_swap.c
void	ft_sort_three(int *stack);
void	ft_sort_four(int *stack_a, int *stack_b);
void	ft_sort_five(int *stack_a, int *stack_b);
void	ft_jonas_sort(int *stack_a, int *stack_b, int arg_count);
void	ft_radix_sort(int *stack_a, int *stack_b, int arg_count);

//main.c
void	ft_sort_two(int *stack);
int		*init_arguments(int argc, char **argv, int *arg_count);
void	ft_sort(int *arg_simple, int *stack_b);
int		ft_check_space(char **argv);

void	ft_move_to_top(int *stack_a, int i, int pivot);

#endif
