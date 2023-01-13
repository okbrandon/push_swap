/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:40:57 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/13 20:24:37 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../srcs/libft/includes/libft.h"
# include "../srcs/libft/includes/ft_printf.h"
# include <limits.h>

typedef struct s_stack
{
	int	*stack;
	int	size;
	int	max_size;
}				t_stack;

void	ft_are_args_valid(char *argv);
void	ft_check_args(int argc, char **argv);
int		*ft_parse_args(char	**splitted, t_stack *stack);
char	*ft_free_and_join(char *s1, char *s2);
int		ft_int_tab_size(char *s);
char	**ft_process_args(int argc, char **argv, t_stack *stack);
void	ft_do_pa(t_stack *stack_a, t_stack *stack_b);
void	ft_do_pb(t_stack *stack_a, t_stack *stack_b);
void	ft_do_rotate(t_stack *stack, char c);
void	ft_do_reverse_rotate(t_stack *stack, char c);
void	ft_do_swap(t_stack *stack, char c);
long	ft_atol(const char *str);
void	ft_free_split(char **splitted);
void	ft_free_all_stacks(t_stack *stack_a, t_stack *stack_b);
void	ft_error(char **splitted, t_stack *stack, int *array);
int		ft_is_sorted(t_stack *stack);
int		ft_find_min_int(t_stack *stack);
int		ft_find_max_int(t_stack *stack);
void	ft_insert_min_int_to_top(t_stack *stack, char c);
void	ft_insert_max_int_to_top(t_stack *stack, char c);
void	ft_chunk_sort(t_stack *stack_a, t_stack *stack_b, int chunk_size);
void	ft_init_sort(t_stack *stack_a, t_stack *stack_b);

#endif