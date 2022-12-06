/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:40:57 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/06 10:40:20 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int	*stack;
	int	size;
	int	max_size;
}				t_stack;

long	ft_atol(const char *str);
void	ft_error(char **splitted, t_stack *stack, int *array);

#endif