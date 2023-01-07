/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:57:19 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/07 11:01:46 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief pa instruction to push the top element of the stack b
 * to the top of the stack a
 * 
 * @param stack_a 		pointer to the stack a
 * @param stack_b 		pointer to the stack b
 */
void	ft_do_pa(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (stack_b->size == 0)
		return ;
	stack_a->size += 1;
	stack_b->size -= 1;
	temp = stack_b->stack[0];
	ft_memmove(stack_b->stack, stack_b->stack + 1, stack_b->size * sizeof(int));
	ft_memmove(stack_a->stack + 1, stack_a->stack, stack_a->size * sizeof(int));
	stack_a->stack[0] = temp;
	ft_printf("pa\n");
}

/**
 * @brief pb instruction to push the top element of the stack a
 * to the top of the stack b
 * 
 * @param stack_a 		pointer to the stack a
 * @param stack_b 		pointer to the stack b
 */
void	ft_do_pb(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (stack_a->size == 0)
		return ;
	stack_b->size += 1;
	stack_a->size -= 1;
	temp = stack_a->stack[0];
	ft_memmove(stack_b->stack + 1, stack_b->stack, stack_b->size * sizeof(int));
	ft_memmove(stack_a->stack, stack_a->stack + 1, stack_a->size * sizeof(int));
	stack_b->stack[0] = temp;
	ft_printf("pb\n");
}

/**
 * @brief ra and rb instructions to move all elements of the stack
 * up by one. The first element becomes the last one.
 * 
 * @param stack 		pointer to the stack
 * @param c 			letter of instruction (a or b)
 */
void	ft_do_rotate(t_stack *stack, char c)
{
	int	temp;

	if (stack->size == 0)
		return ;
	temp = stack->stack[0];
	ft_memmove(stack->stack, stack->stack + 1, stack->size * sizeof(int));
	stack->stack[stack->size - 1] = temp;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}

/**
 * @brief rra and rrb instructions to move all elements from the stack
 * down by one. The last element becomes the first one.
 * 
 * @param stack 		pointer to the stack
 * @param c 			letter of instruction (a or b)
 */
void	ft_do_reverse_rotate(t_stack *stack, char c)
{
	int	temp;

	if (stack->size == 0)
		return ;
	temp = stack->stack[stack->size - 1];
	ft_memmove(stack->stack + 1, stack->stack, stack->size * sizeof(int));
	stack->stack[0] = temp;
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}

void	ft_do_swap(t_stack *stack, char c)
{
	int	temp;

	if (stack->size == 0)
		return ;
	temp = stack->stack[0];
	stack->stack[0] = stack->stack[1];
	stack->stack[1] = temp;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}
