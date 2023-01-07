/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:30:59 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/07 17:51:26 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	ft_is_in_chunk_from_top(t_stack *stack, int min, int max)
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

void	ft_rearrange_stack(t_stack *stack_a, int i)
{
	int	hold;

	hold = stack_a->stack[i];
	if (i <= stack_a->size / 2)
	{
		while (stack_a->stack[0] != hold)
			ft_do_rotate(stack_a, 'a');
	}
	else
	{
		while (stack_a->stack[0] != hold)
			ft_do_reverse_rotate(stack_a, 'a');
	}
}

void	ft_sort_big_stack(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	int		size;
	int		chunk;
	int		i;
	int		j;

	if (ft_is_sorted(stack_a))
		return ;
	size = stack_a->size;
	chunk = size / chunk_size;
	i = ft_is_in_chunk_from_top(stack_a, 0, 19);
	while (i != -1)
	{
		ft_rearrange_stack(stack_a, i);
		ft_do_pb(stack_a, stack_b);
		i = ft_is_in_chunk_from_top(stack_a, 0, 19);
	}
	j = 0;
	while (j < stack_b->size)
	{
		ft_insert_max_int_to_top(stack_b, 'b');
		j++;
	}
}
