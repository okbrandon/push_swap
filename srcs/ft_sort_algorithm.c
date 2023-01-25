/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:30:59 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/25 18:51:21 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_insert_int_to_top(t_stack *stack, char c, int number)
{
	int	index;

	index = 0;
	while (index < stack->size && stack->stack[index] != number)
		index++;
	if (index == 0)
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

static void	ft_insert_and_push(t_stack *stack_a, t_stack *stack_b, \
	int first, int second)
{
	ft_insert_int_to_top(stack_b, 'b', first);
	ft_do_pa(stack_a, stack_b);
	ft_insert_int_to_top(stack_b, 'b', second);
	ft_do_pa(stack_a, stack_b);
}

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
