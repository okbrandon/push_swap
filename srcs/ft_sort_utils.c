/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:13:28 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/27 10:50:33 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
 * @brief Function used to find the minimal number in a stack
 * 
 * @param stack 			pointer to the stack
 * @return int 				the minimal number found
 */
int	ft_find_min_int(t_stack *stack)
{
	int	i;
	int	min;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	min = stack->stack[0];
	while (i < stack->size)
	{
		if (stack->stack[i] < min)
			min = stack->stack[i];
		i++;
	}
	return (min);
}

/**
 * @brief Function used to find the maximal number in a stack
 * 
 * @param stack 			pointer to the stack
 * @return int 				the maximal number found
 */
int	ft_find_max_int(t_stack *stack)
{
	int	i;
	int	max;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	max = stack->stack[0];
	while (i < stack->size)
	{
		if (stack->stack[i] > max)
			max = stack->stack[i];
		i++;
	}
	return (max);
}

/**
 * @brief Function used to move the minimal number to the top
 * of its stack.
 * 
 * @param stack 			pointer to the stack
 * @param c 				name of the stack (a or b)
 */
void	ft_insert_min_int_to_top(t_stack *stack, char c)
{
	int	i;
	int	min;

	if (!stack || !stack->stack)
		return ;
	i = 0;
	min = ft_find_min_int(stack);
	while (stack->stack[i] != min)
		i++;
	if (i <= stack->size / 2)
	{
		while (stack->stack[0] != min)
			ft_do_rotate(stack, c);
	}
	else
	{
		while (stack->stack[0] != min)
			ft_do_reverse_rotate(stack, c);
	}
}

/**
 * @brief Function used to move the maximal number to the top
 * of its stack.
 * 
 * @param stack 			pointer to the stack
 * @param c 				name of the stack (a or b)
 */
void	ft_insert_max_int_to_top(t_stack *stack, char c)
{
	int	i;
	int	max;

	if (!stack || !stack->stack)
		return ;
	i = 0;
	max = ft_find_max_int(stack);
	while (stack->stack[i] != max)
		i++;
	if (i <= stack->size / 2)
	{
		while (stack->stack[0] != max)
			ft_do_rotate(stack, c);
	}
	else
	{
		while (stack->stack[0] != max)
			ft_do_reverse_rotate(stack, c);
	}
}
