/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:56:46 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/13 19:48:00 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_print_stack(t_stack *stack)
{
	int	i;

	if (!stack || !stack->stack || stack->size == 0)
	{
		printf("stack is empty\n");
		return ;
	}
	i = -1;
	while (++i < stack->size)
		printf("%d\n", stack->stack[i]);
}

int	main(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		filled_array[2] = {90, 2};
	int		*empty_array = malloc(1);

	stack_a = (t_stack *) malloc(sizeof(stack_a));
	stack_b = (t_stack *) malloc(sizeof(stack_b));
	stack_a->stack = filled_array;
	stack_a->size = 2;
	stack_a->max_size = 2;
	stack_b->stack = empty_array;
	stack_b->size = 0;
	stack_b->size = 0;
	printf("-- stack_a --\n");
	ft_print_stack(stack_a);
	printf("-- stack_b --\n");
	ft_print_stack(stack_b);
	printf("-- instruction --\n");
	ft_init_sort(stack_a, stack_b);
	printf("-- stack_a --\n");
	ft_print_stack(stack_a);
	printf("-- stack_b --\n");
	ft_print_stack(stack_b);
}
