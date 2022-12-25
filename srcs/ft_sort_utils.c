/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:13:28 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/25 12:02:53 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief A function to verify if the stack is sorted
 * 
 * @param stack 		pointer to the stack
 * @return int 			1 if the stack is sorted, 0 if it isn't
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
 * @brief A function to find the max int in a stack
 * 
 * @param stack 		pointer to the stack
 * @return int 			the minimal int in the stack
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
 * @brief A function to move the minimal int to the top of the stack
 * 
 * @param stack 		pointer to the stack to modify
 * @param c 			the char representing the stack id
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
