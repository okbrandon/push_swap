/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:30:59 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/27 20:59:21 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rearrange_stack(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int		i;
	int		size;

	i = 0;
	size = stack_a->size;
	while (i < size)
	{
		if (stack_a->stack[0] < pivot)
			ft_do_pb(stack_a, stack_b);
		else
			ft_do_rotate(stack_a, 'a');
		i++;
	}
	while (stack_b->size > 0)
		ft_do_pa(stack_a, stack_b);
}

void	ft_sort_big_stack(t_stack *stack_a, t_stack *stack_b)
{
	int		pivot;

	if (ft_is_sorted(stack_a))
		return ;
	pivot = 1;
	ft_rearrange_stack(stack_a, stack_b, pivot);
	ft_radix_sort(stack_a, stack_b);
}
