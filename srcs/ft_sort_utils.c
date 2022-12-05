/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:13:28 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/05 15:07:37 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/***
 * a function to verify if the stack is sorted
 * it should take a pointer to t_stack
 * it will iterate over the stack's size - 1
 *  and check if the current element is smaller than the next one
 *  if it is, it will return 1
 * if it isn't, it will return 0
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
