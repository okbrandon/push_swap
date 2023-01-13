/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:30:59 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/13 19:38:17 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

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

void	ft_insert_int_to_top(t_stack *stack, int index)
{
	int	i;

	i = 0;
	if (index == 0)
		return ;
	if (index <= stack->size / 2)
	{
		while (stack->stack[0] != stack->stack[index])
		{
			ft_do_rotate(stack, 'a');
			i++;
		}
	}
	else
	{
		while (stack->stack[0] != stack->stack[index])
		{
			ft_do_reverse_rotate(stack, 'a');
			i++;
		}
	}
}

void	ft_hundred_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	from;
	int	to;

	from = 0;
	to = 19;
	while (stack_a->size)
	{
		while (ft_is_in_chunk(stack_a, from, to) != -1)
		{
			
		}
		from += 20;
		to += 20;
	}
}
