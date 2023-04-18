/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_handler_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:12:49 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/04/18 10:59:09 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker_bonus.h"

/**
 * @brief Function used to handle the pushes. (pa or pb)
 * 
 * @param action 			instruction received
 * @param stack_a 			pointer to the stack a
 * @param stack_b 			pointer to the stack b
 * @return int 				result of comparison (1 if action was found, 0 if not)
 */
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

/**
 * @brief Function used to handle the rotates. (rb, ra or rr)
 * 
 * @param action 			instruction received
 * @param stack_a 			pointer to the stack a
 * @param stack_b 			pointer to the stack b
 * @return int 				result of comparison (1 if action was found, 0 if not)
 */
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

/**
 * @brief Function used to handle the reverse rotates. (rra, rrb or rrr)
 * 
 * @param action 			instruction received
 * @param stack_a 			pointer to the stack a
 * @param stack_b 			pointer to the stack b
 * @return int 				result of comparison (1 if action was found, 0 if not)
 */
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

/**
 * @brief Function used to handle swaps. (sa, sb or ss)
 * 
 * @param action 			instruction received
 * @param stack_a 			pointer to the stack a
 * @param stack_b 			pointer to the stack b
 * @return int 				result of comparison (1 if action was found, 0 if not)
 */
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

/**
 * @brief Function used to catch instructions and apply them.
 * It'll throw an error if the action received is unknown.
 * 
 * @param action 			instruction received
 * @param stack_a 			pointer to the stack a
 * @param stack_b 			pointer to the stack b
 */
void	ft_handle_action(char *action, t_stack *stack_a, t_stack *stack_b)
{
	int	result;

	result = 0;
	result += ft_handle_pushes(action, stack_a, stack_b);
	result += ft_handle_rotates(action, stack_a, stack_b);
	result += ft_handle_reverse_rotates(action, stack_a, stack_b);
	result += ft_handle_swaps(action, stack_a, stack_b);
	free(action);
	if (!result)
	{
		ft_free_all_stacks(stack_a, stack_b);
		ft_error(NULL, NULL, NULL);
	}
}
