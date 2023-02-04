/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_process_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:40:34 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/02/04 20:39:43 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker_bonus.h"

/**
 * @brief Function used to initialize the checker and listen
 * to the instructions received from the standard input.
 * 
 * @param stack_a 			pointer to the stack a
 * @param stack_b 			pointer to the stack b
 */
void	ft_init_checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		ft_handle_action(str, stack_a, stack_b);
	}
	if (!ft_is_sorted(stack_a) || stack_b->size)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}
