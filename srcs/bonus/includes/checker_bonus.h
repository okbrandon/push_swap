/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:40:36 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/26 19:59:00 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../../libft/includes/libft.h"
# include "../../libft/includes/ft_printf.h"
# include "../../libft/includes/get_next_line.h"
# include <limits.h>

typedef struct s_stack
{
	int	*stack;
	int	size;
	int	max_size;
}				t_stack;

/*
 * Parser
 */
char	**ft_process_args(int argc, char **argv, t_stack *stack);
int		*ft_parse_args(char	**splitted, t_stack *stack);
void	ft_check_args(int argc, char **argv);

/*
 * Sort utils
 */
void	ft_do_pa(t_stack *stack_a, t_stack *stack_b);
void	ft_do_pb(t_stack *stack_a, t_stack *stack_b);
void	ft_do_rotate(t_stack *stack);
void	ft_do_reverse_rotate(t_stack *stack);
void	ft_do_swap(t_stack *stack);

/*
 * Checker handler
 */
void	ft_handle_action(char *action, t_stack *stack_a, t_stack *stack_b);
void	ft_init_checker(t_stack *stack_a, t_stack *stack_b);

/*
 * Other utils
 */
int		ft_is_sorted(t_stack *stack);
long	ft_atol(const char *str);
void	ft_free_all_stacks(t_stack *stack_a, t_stack *stack_b);
void	ft_error(char **splitted, t_stack *stack, int *array);
int		ft_strcmp(char *s1, char *s2);

#endif