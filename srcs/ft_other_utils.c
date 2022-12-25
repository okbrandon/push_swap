/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:23:48 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/25 12:15:31 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief A function to convert a string to a long int
 * 
 * @param str 			a long number as a string
 * @return long			the converted string
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

/**
 * @brief A function to free a string array
 * 
 * @param splitted 		the array of strings to be freed
 */
void	ft_free_split(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}

/**
 * @brief A function to free a stack
 * 
 * @param stack 		the stack to be freed 
 */
void	ft_free_stack(t_stack *stack)
{
	free(stack->stack);
	free(stack);
}

/**
 * @brief A function to free two stacks
 * 
 * @param stack_a 		the first stack to be freed
 * @param stack_b 		the second stack to be freed
 */
void	ft_free_all_stacks(t_stack *stack_a, t_stack *stack_b)
{
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
}

/**
 * @brief A function to exit the program safely
 * 
 * @param splitted 		the array of strings to be freed
 * @param stack 		the stack to be freed
 * @param array			the array to be freed
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
