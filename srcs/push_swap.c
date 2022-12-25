/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:56:46 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/25 12:33:41 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void	ft_print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		printf("%d\n", stack->stack[i]);
		i++;
	}
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
// int	main(void)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;
// 	int		filled_array[4];
// 	int		*empty_array;
// 	int		i;

// 	i = 0;
// 	srand(time(NULL));
// 	while (i < 4)
// 	{
// 		filled_array[i] = ft_get_random_int(0, 100);
// 		i++;
// 	}
// 	empty_array = malloc(1);
// 	stack_a = (t_stack *) malloc(sizeof(stack_a));
// 	stack_b = (t_stack *) malloc(sizeof(stack_b));
// 	stack_a->stack = filled_array;
// 	stack_a->stack[4] = '\0';
// 	stack_a->size = 3;
// 	stack_a->max_size = 3;
// 	stack_b->stack = empty_array;
// 	stack_b->size = 0;
// 	stack_b->size = 0;
// 	printf("-- stack_a --\n");
// 	ft_print_stack(stack_a);
// 	printf("-- stack_b --\n");
// 	ft_print_stack(stack_b);
// 	printf("-- instruction --\n");
// 	ft_init_sort(stack_a, stack_b);
// 	printf("-- stack_a --\n");
// 	ft_print_stack(stack_a);
// 	printf("-- stack_b --\n");
// 	ft_print_stack(stack_b);
// }
int	*ft_get_int_array(int argc, char **argv)
{
	int	*array;
	int	i;

	i = 0;
	array = malloc(sizeof(int) * argc);
	while (i < argc - 1)
	{
		array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (array);
}
/*
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*empty_array;

	empty_array = malloc(1);
	stack_a = (t_stack *) malloc(sizeof(stack_a));
	stack_b = (t_stack *) malloc(sizeof(stack_b));
	stack_a->stack = ft_get_int_array(argc, argv);
	stack_a->size = argc - 1;
	stack_a->max_size = argc - 1;
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
}*/

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**splitted;

	if (argc <= 1)
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
	ft_free_all_stacks(stack_a, stack_b);
	return (0);
}
