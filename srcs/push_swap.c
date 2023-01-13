/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:56:46 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/13 20:40:14 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void	ft_print_stack(t_stack *stack)
{
	int	i;

	if (!stack || !stack->stack || stack->size == 0)
	{
		printf("! empty !\n");
		return ;
	}
	i = 0;
	while (i < stack->size)
	{
		printf("%d\n", stack->stack[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**splitted;

	if (argc == 1)
		return (1);
	if (argc < 1)
		ft_error(NULL, NULL, NULL);
	ft_check_args(argc, argv);
	stack_a = ft_calloc(1, sizeof(t_stack));
	if (!stack_a)
		return (1);
	splitted = ft_process_args(argc, argv, stack_a);
	stack_a->stack = ft_parse_args(splitted, stack_a);
	write(1, "a", 1);
	stack_b = ft_calloc(1, sizeof(t_stack));
	if (!stack_b)
		ft_error(splitted, stack_a, stack_a->stack);
	stack_b->stack = ft_calloc(stack_a->size + 1, sizeof(int));
	if (!stack_b->stack)
		return (1);
	stack_b->size = 0;
	printf("---- displaying stacks ----\n");
	printf("  stack_a's content\n");
	ft_print_stack(stack_a);
	printf("  stack_b's content\n");
	ft_print_stack(stack_b);
	printf("-- displaying instructions --\n");
	if (!ft_is_sorted(stack_a))
		ft_init_sort(stack_a, stack_b);
	printf("  stack_a's content\n");
	ft_print_stack(stack_a);
	printf("  stack_b's content\n");
	ft_print_stack(stack_b);
	ft_free_all_stacks(stack_a, stack_b);
	return (0);
}
/* 
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**splitted;

	if (argc == 1)
		return (1);
	if (argc < 1)
		ft_error(NULL, NULL, NULL);
	ft_check_args(argc, argv);
	stack_a = ft_calloc(1, sizeof(t_stack));
	if (!stack_a)
		return (1);
	splitted = ft_process_args(argc, argv, stack_a);
	stack_a->stack = ft_parse_args(splitted, stack_a);
	stack_b = ft_calloc(1, sizeof(t_stack));
	if (!stack_b)
		ft_error(splitted, stack_a, stack_a->stack);
	stack_b->stack = ft_calloc(stack_a->size + 1, sizeof(int));
	if (!stack_b->stack)
		return (1);
	stack_b->size = 0;
	if (!ft_is_sorted(stack_a))
		ft_init_sort(stack_a, stack_b);
	ft_free_all_stacks(stack_a, stack_b);
	return (0);
} */
