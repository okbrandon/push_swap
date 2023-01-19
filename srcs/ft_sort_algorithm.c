/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:30:59 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/19 11:32:21 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_insert_int_to_top(t_stack *stack, int index)
{
	int	number;

	if (index == 0)
		return ;
	number = stack->stack[index];
	if (index <= stack->size / 2)
	{
		while (stack->stack[0] != number)
			ft_do_rotate(stack, 'a');
	}
	else
	{
		while (stack->stack[0] != number)
			ft_do_reverse_rotate(stack, 'a');
	}
}

static int	ft_find_next_min_int(t_stack *stack, int min)
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

static int	ft_get_min_int_index(t_stack *stack, int min)
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

static void	ft_push_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size)
	{
		ft_insert_max_int_to_top(stack_b, 'b');
		ft_do_pa(stack_a, stack_b);
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
			ft_insert_int_to_top(stack_a, index);
			ft_do_pb(stack_a, stack_b);
			if (stack_b->stack[0] < stack_a->middle)
				ft_do_rotate(stack_b, 'b');
		}
	}
	ft_push_b_to_a(stack_a, stack_b);
}
