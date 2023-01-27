/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:10:12 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/27 10:58:16 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker_bonus.h"

/**
 * @brief Function used to check if a stack is sorted.
 * 
 * @param stack 			pointer to the stack
 * @return int 				sorted (1) or not (0)
 */
int	ft_is_sorted(t_stack *stack)
{
	int	i;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->stack[i] > stack->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

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
 * @brief A function to free two stacks
 * 
 * @param stack_a 		the first stack to be freed
 * @param stack_b 		the second stack to be freed
 */
void	ft_free_all_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->stack);
	free(stack_a);
	free(stack_b->stack);
	free(stack_b);
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
	{
		free(stack->stack);
		free(stack);
	}
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

/**
 * @brief Basic implementation of ft_strcmp from piscine.
 * 
 * @param s1		The first string 
 * @param s2 		The second string
 * @return int 		The first difference found
 */
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
