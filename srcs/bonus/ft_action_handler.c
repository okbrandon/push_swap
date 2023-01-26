/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:12:49 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/26 18:25:38 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker_bonus.h"

static int	ft_handle_pushes(char *action, t_stack *stack_a, t_stack *stack_b)
{
	int	result;

	result = 0;
	if (!ft_strcmp(action, "pa\n"))
	{
		ft_do_pa(stack_a, stack_b);
		result = 1;
	}
	else if (!ft_strcmp(action, "pb\n"))
	{
		ft_do_pb(stack_a, stack_b);
		result = 1;
	}
	return (result);
}

static int	ft_handle_rotates(char *action, t_stack *stack_a, t_stack *stack_b)
{
	int	result;

	result = 0;
	if (!ft_strcmp(action, "ra\n"))
	{
		ft_do_rotate(stack_a);
		result = 1;
	}
	else if (!ft_strcmp(action, "rb\n"))
	{
		ft_do_rotate(stack_b);
		result = 1;
	}
	else if (!ft_strcmp(action, "rr\n"))
	{
		ft_do_rotate(stack_a);
		ft_do_rotate(stack_b);
		result = 1;
	}
	return (result);
}

static int	ft_handle_reverse_rotates(char *action, t_stack *stack_a, \
	t_stack *stack_b)
{
	int	result;

	result = 0;
	if (!ft_strcmp(action, "rra\n"))
	{
		ft_do_reverse_rotate(stack_a);
		result = 1;
	}
	else if (!ft_strcmp(action, "rrb\n"))
	{
		ft_do_reverse_rotate(stack_b);
		result = 1;
	}
	else if (!ft_strcmp(action, "rrr\n"))
	{
		ft_do_reverse_rotate(stack_a);
		ft_do_reverse_rotate(stack_b);
		result = 1;
	}
	return (result);
}

static int	ft_handle_swaps(char *action, t_stack *stack_a, t_stack *stack_b)
{
	int	result;

	result = 0;
	if (!ft_strcmp(action, "sa\n"))
	{
		ft_do_swap(stack_a);
		result = 1;
	}
	else if (!ft_strcmp(action, "sb\n"))
	{
		ft_do_swap(stack_b);
		result = 1;
	}
	else if (!ft_strcmp(action, "ss\n"))
	{
		ft_do_swap(stack_a);
		ft_do_swap(stack_b);
		result = 1;
	}
	return (result);
}

void	ft_handle_action(char *action, t_stack *stack_a, t_stack *stack_b)
{
	int	result;

	result = 0;
	result += ft_handle_pushes(action, stack_a, stack_b);
	result += ft_handle_rotates(action, stack_a, stack_b);
	result += ft_handle_reverse_rotates(action, stack_a, stack_b);
	result += ft_handle_swaps(action, stack_a, stack_b);
	if (!result)
	{
		ft_free_all_stacks(stack_a, stack_b);
		ft_error(NULL, NULL, NULL);
	}
}
