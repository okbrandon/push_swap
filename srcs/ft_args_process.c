/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:47:39 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/05 19:28:10 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/***
 * a free and join function that takes two char * and returns a char *
 * it should strjoin the two strings and free the first one
 * and return the new string
*/
char	*ft_free_and_join(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free(s1);
	return (temp);
}

/***
 * a function that takes a char * and returns an int
 * it should iterate over the char *
 * if it finds a space it should iterate while it finds a space and 
 *  that it doesn't reach the end of the string
 * else if it finds something else, it should iterate while it doesn't
 *  find a space and that it doesn't reach the end of the string
 *  and increment a counter when it finds a space
 * it should return the counter
*/
int	ft_int_tab_size(char *s)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] == ' ')
		{
			while (s[i] == ' ' && s[i])
				i++;
		}
		else
		{
			while (s[i] != ' ' && s[i])
				i++;
			counter++;
		}
		i++;
	}
	return (counter);
}

/***
 * a function that will make a splitted array of strings 
 * it should take the number of arguments, the arguments, and a t_stack *
 * it should have an index i, a char * and a char **
 * i will increment from 1 to argc
 * the char * will be a copy of the argument at i using the free and join
 * 	function
 * also if i is not reaching argc - 1 we should add a space to the char *
 * the stack size should be the number of words in the char *
 * the stack max size should be the number of words in the char *
 * the char ** should be a splitted array of char * with ' ' using ft_split
 * we should free the char * and return the char **
*/
char	**ft_args_process(int argc, char **argv, t_stack *stack)
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
