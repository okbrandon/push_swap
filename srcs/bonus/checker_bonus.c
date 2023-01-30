/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:40:09 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/30 17:29:21 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker_bonus.h"

/**
 * @brief Main program.
 */
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
	ft_init_checker(stack_a, stack_b);
	ft_free_all_stacks(stack_a, stack_b);
	return (0);
}
