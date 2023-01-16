/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:37:02 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/16 11:45:07 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_count_in_chunk(t_stack *stack, int min, int max)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] >= min && stack->stack[i] <= max)
			count++;
		i++;
	}
	return (count);
}

static void	ft_swap(int	*a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	modifications;

	i = 0;
	modifications = 1;
	while (modifications > 0)
	{
		i = 0;
		modifications = 0;
		while (i < size)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
				modifications++;
			}
			i++;
		}
	}
}

int	ft_get_median(t_stack *stack, int min, int max)
{
	int	*array;
	int	to_return;
	int	size;
	int	i;
	int	j;

	size = ft_count_in_chunk(stack, min, max);
	array = malloc(sizeof(int) * size);
	i = 0;
	j = 0;
	if (array)
	{
		while (i < stack->size)
		{
			if (stack->stack[i] >= min && stack->stack[i] <= max)
				array[j++] = stack->stack[i];
			i++;
		}
		ft_sort_int_tab(array, size);
		to_return = array[size / 2];
		free(array);
		return (to_return);
	}
	return (-1);
}
