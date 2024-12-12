/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:33:16 by mfrenzel          #+#    #+#             */
/*   Updated: 2024/12/12 12:38:15 by Furaido          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int				i;
	int				norp;
	long long int	res;

	i = 0;
	norp = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		norp = -norp;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if ((res * norp) > INT_MAX || (res * norp) < INT_MIN)
		return (0);
	return ((int)res * norp);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char *string = "-19";
// 	printf("String: %s\n", string);
// 	printf("ft_atoi: %i\n", ft_atoi(string));
// 	printf("atoi: %i\n", atoi(string));
// }
