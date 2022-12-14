/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:56:46 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/14 11:43:27 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	ft_print_stack(t_stack *stack)
{
	int	i;

	if (!stack || !stack->stack || stack->size == 0)
	{
		printf("stack is empty\n");
		return ;
	}
	i = 0;
	while (i < stack->size)
		printf("%d\n", stack->stack[i++]);
}

int	ft_get_random_int(int min, int max)
{
	return (min + rand() / (RAND_MAX / (max - min + 1) + 1));
}

/**
 * @brief This is a simple main just to test things manually
 * 
 * @return int 
 */
int	main(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		filled_array[4];
	int		*empty_array;
	int		i;

	i = 0;
	srand(time(NULL));
	while (i < 4)
	{
		filled_array[i] = ft_get_random_int(0, 100);
		i++;
	}
	empty_array = malloc(1);
	stack_a = (t_stack *) malloc(sizeof(stack_a));
	stack_b = (t_stack *) malloc(sizeof(stack_b));
	stack_a->stack = filled_array;
	stack_a->stack[4] = '\0';
	stack_a->size = 3;
	stack_a->max_size = 3;
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
