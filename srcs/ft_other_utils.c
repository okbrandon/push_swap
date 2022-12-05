/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:23:48 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/05 14:56:47 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/***
 * A atol function
*/
long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

void	ft_free_stack(t_stack *stack)
{
	free(stack->stack);
	free(stack);
}

/***
 * a function to free all stacks
 * it should take two pointers to t_stack
 * and free their stack and the t_stack itself
*/
void	ft_free_all_stacks(t_stack *stack_a, t_stack *stack_b)
{
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
}

/***
 * a ft_error function that takes a char **, a t_stack *, and an int *
 * it should free all the pointers it receives if they are not NULL
 * and then write "Error" to the standard error
 * and exit the program with EXIT_FAILURE
*/
void	ft_error(char **splitted, t_stack *stack, int *array)
{
	int	i;

	i = 0;
	if (array)
		free(array);
	if (splitted)
	{
		while (splitted[i])
			free(splitted[i++]);
		free(splitted);
	}
	if (stack)
		ft_free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
