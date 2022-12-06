/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:27:44 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/06 10:58:42 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief A function used to check if there's a duplicated int in
 * the int array and in the stack array
 * 
 * @param array			an array of int
 * @param stack 		a pointer to a stack
 * @return int 			returns if there's a duplicate or not
 */
static int	ft_is_duplicates(int *array, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (array[i] == array[j] && j != i)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * @brief A function that will parse splitted arguments from a main
 * to a single int array
 * 
 * @param splitted			the splitted arguments that must contains integers
 * @param stack 			a pointer to a stack having a size set
 * @return int* 			the returned int array
 */
int	*ft_parse_args(char	**splitted, t_stack *stack)
{
	long	number;
	int		i;
	int		j;
	int		*array;

	array = malloc((stack->size + 1) * sizeof(int));
	if (!array)
		return (NULL);
	i = stack->size;
	while (i > 0)
	{
		number = ft_atol(splitted[i]);
		if (number > INT_MAX || number < INT_MIN)
			ft_error(splitted, stack, array);
		array[j++] = number;
		i--;
	}
	if (ft_is_duplicates(array, stack))
		ft_error(splitted, stack, array);
	free(splitted);
	return (array);
}
