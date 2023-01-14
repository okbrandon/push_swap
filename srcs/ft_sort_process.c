/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:39:16 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/14 17:59:16 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_sort_two(t_stack *stack)
{
	if (ft_is_sorted(stack))
		return ;
	if (stack->stack[0] > stack->stack[1])
		ft_do_rotate(stack, 'a');
}

void	ft_sort_three(t_stack *stack)
{
	if (ft_is_sorted(stack))
		return ;
	if (stack->stack[0] > stack->stack[1])
	{
		if (stack->stack[1] < stack->stack[stack->size - 1]
			&& stack->stack[stack->size - 1] < stack->stack[0])
			ft_do_rotate(stack, 'a');
		else
			ft_do_swap(stack, 'a');
	}
	if (stack->stack[stack->size - 1] < stack->stack[0]
		&& stack->stack[0] < stack->stack[1])
		ft_do_reverse_rotate(stack, 'a');
	if (stack->stack[0] < stack->stack[stack->size - 1]
		&& stack->stack[stack->size - 1] < stack->stack[1])
	{
		ft_do_swap(stack, 'a');
		ft_sort_three(stack);
	}
}

static void	ft_sort_four_and_five(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_is_sorted(stack_a))
		return ;
	if (stack_a->size == 4)
	{
		ft_insert_min_int_to_top(stack_a, 'a');
		ft_do_pb(stack_a, stack_b);
		if (!ft_is_sorted(stack_a))
			ft_sort_three(stack_a);
		ft_do_pa(stack_a, stack_b);
	}
	else
	{
		ft_insert_min_int_to_top(stack_a, 'a');
		ft_do_pb(stack_a, stack_b);
		ft_insert_min_int_to_top(stack_a, 'a');
		ft_do_pb(stack_a, stack_b);
		if (!ft_is_sorted(stack_a))
			ft_sort_three(stack_a);
		ft_do_pa(stack_a, stack_b);
		ft_do_pa(stack_a, stack_b);
	}
}

void	ft_init_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	else if (stack_a->size == 2)
		ft_sort_two(stack_a);
	else if (stack_a->size == 3)
		ft_sort_three(stack_a);
	else if (stack_a->size <= 5)
		ft_sort_four_and_five(stack_a, stack_b);
	else if (stack_a->size <= 10)
		ft_chunk_sort(stack_a, stack_b, 2);
	else if (stack_a->size <= 100)
		ft_chunk_sort(stack_a, stack_b, 18);
	else
		ft_chunk_sort(stack_a, stack_b, 35);
}
