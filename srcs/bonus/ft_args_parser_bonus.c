/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_parser_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:27:44 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/26 15:15:28 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker_bonus.h"

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

static void	ft_reverse_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		i++;
		j--;
	}
}

int	*ft_parse_args(char	**splitted, t_stack *stack)
{
	long	number;
	int		i;
	int		j;
	int		*array;

	array = ft_calloc((stack->size + 1), sizeof(int));
	if (!array)
		return (NULL);
	i = stack->size - 1;
	j = 0;
	while (i >= 0)
	{
		number = ft_atol(splitted[j++]);
		if (number > INT_MAX || number < INT_MIN)
			ft_error(splitted, stack, array);
		array[i--] = (int) number;
	}
	if (ft_is_duplicates(array, stack))
		ft_error(splitted, stack, array);
	free(splitted);
	ft_reverse_array(array, stack->size);
	return (array);
}
