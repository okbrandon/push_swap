/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:39:16 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/13 20:14:20 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	ft_small_sort(t_stack *stack, int type)
{
	if (ft_is_sorted(stack))
		return ;
	if (type == 2)
	{
		if (stack->stack[0] > stack->stack[1])
			ft_do_rotate(stack, 'a');
		else
			ft_do_rotate(stack, 'b');
	}
	else if (type == 3)
	{
		ft_do_swap(stack, 'a');
		if (stack->stack[0] > stack->stack[stack->size])
			ft_do_reverse_rotate(stack, 'a');
	}
}

void	ft_init_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (stack_a->size == 2)
		ft_small_sort(stack_a, 2);
	if (stack_a->size == 3)
		ft_small_sort(stack_a, 3);
}
