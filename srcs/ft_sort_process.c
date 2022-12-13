/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:39:16 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/13 19:45:48 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	ft_small_sort(t_stack *stack_a)
{
	if (ft_is_sorted(stack_a))
		return ;
	if (stack_a->stack[0] > stack_a->stack[1])
		ft_do_rotate(stack_a, 'a');
	else
		ft_do_rotate(stack_a, 'b');
}

void	ft_init_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (stack_a->size == 2)
		ft_small_sort(stack_a);
}
