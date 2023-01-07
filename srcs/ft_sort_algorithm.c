/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:30:59 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/07 11:01:42 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	ft_sort_big_stack(t_stack *stack_a, t_stack *stack_b)
{
	int		size;

	if (ft_is_sorted(stack_a))
		return ;
	size = stack_a->size;
	while (size > 0)
	{
		ft_insert_min_int_to_top(stack_a, 'a');
		ft_do_pb(stack_a, stack_b);
		size--;
	}
	while (stack_b->size > 0)
		ft_do_pa(stack_a, stack_b);
}
