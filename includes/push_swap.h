/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:40:57 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/26 19:58:58 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <limits.h>

typedef struct s_stack
{
	int	*stack;
	int	size;
	int	max_size;
	int	middle;
}				t_stack;

/**
 * Parser
 */
void	ft_check_args(int argc, char **argv);
int		*ft_parse_args(char	**splitted, t_stack *stack);
char	**ft_process_args(int argc, char **argv, t_stack *stack);

/*
 * Instructions
 */
void	ft_print_instruction(char *action);
void	ft_do_pa(t_stack *stack_a, t_stack *stack_b);
void	ft_do_pb(t_stack *stack_a, t_stack *stack_b);
void	ft_do_rotate(t_stack *stack, char c);
void	ft_do_reverse_rotate(t_stack *stack, char c);
void	ft_do_swap(t_stack *stack, char c);

/*
 * Sort utils
 */
int		ft_find_min_int(t_stack *stack);
int		ft_find_max_int(t_stack *stack);
void	ft_insert_min_int_to_top(t_stack *stack, char c);
void	ft_insert_max_int_to_top(t_stack *stack, char c);
void	ft_chunk_sort(t_stack *stack_a, t_stack *stack_b, int chunk_size);
void	ft_init_sort(t_stack *stack_a, t_stack *stack_b);
int		ft_get_index_of_int(t_stack *stack, int number);
int		ft_find_next_max_int(t_stack *stack, int max);
int		ft_find_next_min_int(t_stack *stack, int min);
int		ft_get_min_int_index(t_stack *stack, int min);

/*
 * Other utils
 */
long	ft_atol(const char *str);
void	ft_free_all_stacks(t_stack *stack_a, t_stack *stack_b);
void	ft_error(char **splitted, t_stack *stack, int *array);
int		ft_is_sorted(t_stack *stack);

#endif