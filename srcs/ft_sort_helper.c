/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:43:49 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/27 10:45:35 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Function used to get the index of a number
 * from a stack.
 * 
 * @param stack 		pointer to the stack
 * @param number 		the number that we want its index
 * @return int 			the index found, if not found -1
 */
int	ft_get_index_of_int(t_stack *stack, int number)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] == number)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * @brief Function used to find the next max int in a stack.
 * 
 * @param stack 		pointer to the stack
 * @param max 			the current max int in the stack
 * @return int 			the next max int found
 */
int	ft_find_next_max_int(t_stack *stack, int max)
{
	int	i;
	int	next_max;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	next_max = INT_MIN;
	while (i < stack->size)
	{
		if (stack->stack[i] > next_max && stack->stack[i] < max)
			next_max = stack->stack[i];
		i++;
	}
	return (next_max);
}

/**
 * @brief Function used to find the next min int in a stack.
 * 
 * @param stack 		pointer to the stack
 * @param min 			the current min int in the stack
 * @return int 			the next min int found
 */
int	ft_find_next_min_int(t_stack *stack, int min)
{
	int	i;
	int	next_min;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	next_min = INT_MAX;
	while (i < stack->size)
	{
		if (stack->stack[i] > min && stack->stack[i] < next_min)
			next_min = stack->stack[i];
		i++;
	}
	return (next_min);
}

/**
 * @brief Function used to found the first number's index that
 * is smaller than the min int in a stack.
 * 
 * @param stack 		pointer to the stack
 * @param min 			the current min int in the stack
 * @return int 			the index of the first number smaller than min
 */
int	ft_get_min_int_index(t_stack *stack, int min)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] <= min)
			break ;
		i++;
	}
	return (i);
}
