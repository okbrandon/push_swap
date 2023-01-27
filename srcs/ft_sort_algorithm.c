/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:30:59 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/27 11:22:33 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Function used to move to the top of the stack a number.
 * 
 * @param stack			pointer to the stack 
 * @param c 			the pointed stack name (a or b)
 * @param number 		the number in the stack to move
 */
static void	ft_insert_int_to_top(t_stack *stack, char c, int number)
{
	int	index;

	index = ft_get_index_of_int(stack, number);
	if (index == -1)
		return ;
	if (index <= stack->size / 2)
	{
		while (stack->stack[0] != number)
			ft_do_rotate(stack, c);
	}
	else
	{
		while (stack->stack[0] != number)
			ft_do_reverse_rotate(stack, c);
	}
}

/**
 * @brief Function used to complete the algorithm.
 * Inserts to top the two numbers in parameters and pushing them to a.
 * 
 * @param stack_a		pointer to the stack a
 * @param stack_b		pointer to the stack b
 * @param first			the first number to push
 * @param second		the second number to push
 */
static void	ft_insert_and_push(t_stack *stack_a, t_stack *stack_b, \
	int first, int second)
{
	ft_insert_int_to_top(stack_b, 'b', first);
	ft_do_pa(stack_a, stack_b);
	ft_insert_int_to_top(stack_b, 'b', second);
	ft_do_pa(stack_a, stack_b);
}

/**
 * @brief Function used to push everything from the stack b, to
 * the stack a.
 * It'll get the two biggest numbers and will push the one that
 * is the closest to the top of stack b first then the second one.
 * 
 * @param stack_a 		pointer to the stack a
 * @param stack_b 		pointer to the stack b
 */
static void	ft_push_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	first;
	int	second;
	int	first_index;
	int	second_index;

	while (stack_b->size)
	{
		first = ft_find_max_int(stack_b);
		second = ft_find_next_max_int(stack_b, first);
		first_index = ft_get_index_of_int(stack_b, first);
		second_index = ft_get_index_of_int(stack_b, second);
		if (first_index > stack_b->size / 2)
			first_index = stack_b->size - first_index;
		if (second_index > stack_b->size / 2)
			second_index = stack_b->size - second_index;
		if (first_index < second_index)
			ft_insert_and_push(stack_a, stack_b, first, second);
		else
			ft_insert_and_push(stack_a, stack_b, second, first);
		if (stack_a->stack[0] > stack_a->stack[1])
			ft_do_swap(stack_a, 'a');
	}
}

/**
 * @brief Quick sort algorithm based function, called chunk sort here.
 * It'll creates small stacks of chunk_size integers.
 * 
 * @param stack_a 		pointer to the stack a
 * @param stack_b 		pointer to the stack b
 * @param chunk_size 	the size of a chunk
 */
void	ft_chunk_sort(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	int	index;
	int	min_int;
	int	times;

	while (stack_a->size)
	{
		times = 0;
		min_int = ft_find_min_int(stack_a);
		while (times++ < chunk_size)
		{
			min_int = ft_find_next_min_int(stack_a, min_int);
			if (times == chunk_size / 2)
				stack_a->middle = min_int;
		}
		times = 0;
		while (times++ < chunk_size)
		{
			index = ft_get_min_int_index(stack_a, min_int);
			ft_insert_int_to_top(stack_a, 'a', stack_a->stack[index]);
			ft_do_pb(stack_a, stack_b);
			if (stack_b->stack[0] < stack_a->middle)
				ft_do_rotate(stack_b, 'b');
		}
	}
	ft_push_b_to_a(stack_a, stack_b);
}
