/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:13:28 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/05 19:34:44 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief A function to verify if the stack is sorted
 * 
 * @param stack 		pointer to the stack
 * @return int 			1 if the stack is sorted, 0 if it isn't
 */
int	ft_is_sorted(t_stack *stack)
{
	int	i;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->stack[i] < stack->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}
