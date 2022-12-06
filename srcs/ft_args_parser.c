/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:27:44 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/06 10:42:22 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/***
 * a function that check if an array of int contains duplicates from a stack
 * it should take an int *, and a t_stack *
 * there should be a loop inside a loop
 * one that itereates to stack->size
 * and the other that itereates to stack->size
 * and compares if the int * at i is equal to the int * at j and that i != j
 * if it finds a duplicate it should return 1
 * else it should return 0
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

/***
 * a function that creates a int array from a splitted array of
 * 	strings and a stack
 * we should have two indexes i and j
 * i will iterate into the returned array
 * j will iterate into the splitted array
 * it should take a char **, and a t_stack *
 * it should malloc an int array of size stack->size + 1
 * it should iterate from stack->size to 0
 * and convert the char * to an int using ft_atol
 * and put it in the int array
 * this int should not be bigger than INT_MAX or smaller than INT_MIN
 * if it is we should use ft_error and exit the program
 * after that we should check if there are duplicates in the int array
 * if there are we should use ft_error and exit the program
 * else we should free the splitted array and return the int array
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
