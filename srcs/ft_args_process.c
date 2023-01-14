/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:47:39 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/14 09:49:48 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief A function to re-alloc a string
 * 
 * @param s1 			pointer to the string to be re-allocated
 * @param s2 			pointer to the string to be added to s1
 * @return char* 		pointer to the new string
 */
char	*ft_free_and_join(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free(s1);
	return (temp);
}

/**
 * @brief A function to determine the size to be allocated for the stack
 * 
 * @param s 			pointer to the string to be processed
 * @return int 			the size to be allocated 
 */
int	ft_int_tab_size(char *s)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (s[i] != ' ')
		counter++;
	while (s[i])
	{
		if (s[i] == ' ')
			i++;
		else
		{
			if (s[i + 1] && s[i + 1] == ' ')
				counter++;
			i++;
		}
	}
	return (counter);
}

/**
 * @brief A function to process the arguments
 * 
 * @param argc 			the number of arguments
 * @param argv 			pointer to the arguments
 * @param stack 		pointer to the stack to be filled
 * @return char** 		pointer to the array of strings
 */
char	**ft_process_args(int argc, char **argv, t_stack *stack)
{
	int		i;
	char	*s;
	char	**splitted;

	i = 1;
	s = ft_calloc(1, sizeof(char));
	if (!s)
		return (NULL);
	while (i < argc)
	{
		s = ft_free_and_join(s, argv[i]);
		if (i < argc - 1)
			s = ft_strjoin(s, " ");
		i++;
	}
	stack->size = ft_int_tab_size(s);
	stack->max_size = ft_int_tab_size(s);
	splitted = ft_split(s, ' ');
	free(s);
	return (splitted);
}
