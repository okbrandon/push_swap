/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:30:59 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/16 19:13:40 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_in_chunk(t_stack *stack, int min, int max)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] >= min && stack->stack[i] <= max)
			return (i);
		i++;
	}
	return (-1);
}

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

void	ft_chunk_sort(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	int	from;
	int	to;
	int	index;
	int	middle;

	middle = ft_get_median(stack_a);
	from = middle - chunk_size;
	to = middle + chunk_size;
	while (stack_a->size)
	{
		index = 0;
		while (index != -1)
		{
			index = ft_is_in_chunk(stack_a, from, to);
			if (index == -1)
				break ;
			ft_insert_int_to_top(stack_a, index);
			ft_do_pb(stack_a, stack_b);
			if (stack_b->stack[0] < middle)
				ft_do_rotate(stack_b, 'b');
		}
		from -= chunk_size;
		to += chunk_size;
	}
	while (stack_b->size)
	{
		ft_insert_max_int_to_top(stack_b, 'b');
		ft_do_pa(stack_a, stack_b);
	}
}
