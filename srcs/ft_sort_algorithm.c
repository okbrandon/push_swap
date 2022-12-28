/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:30:59 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/28 16:32:39 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	ft_swap(int	*a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	ft_rearrange_stack(t_stack *stack_a, int pi)
{
	int		i;
	int		j;
	int		temp;

	i = -1;
	temp = INT_MIN;
	while (++i < pi)
	{
		if (temp == INT_MIN && stack_a->stack[i] > stack_a->stack[pi])
			temp = i;
		if (temp != INT_MIN)
		{
			j = i - 1;
			while (++j < pi)
			{
				if (stack_a->stack[j] < stack_a->stack[pi])
				{
					ft_swap(&stack_a->stack[temp], &stack_a->stack[j]);
					temp = INT_MIN;
					break ;
				}
			}
		}
	}
	ft_swap(&stack_a->stack[temp], &stack_a->stack[pi]);
}

void	ft_sort_big_stack(t_stack *stack_a, t_stack *stack_b)
{
	int		pivot_index;
	int		size;

	if (ft_is_sorted(stack_a))
		return ;
	size = stack_a->size;
	pivot_index = size - 1;
	ft_rearrange_stack(stack_a, pivot_index);
	while (size > 0)
	{
		ft_insert_min_int_to_top(stack_a, 'a');
		ft_do_pb(stack_a, stack_b);
		size--;
	}
	while (stack_b->size > 0)
		ft_do_pa(stack_a, stack_b);
}
