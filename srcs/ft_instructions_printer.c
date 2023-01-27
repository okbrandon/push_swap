/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions_printer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:18:25 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/27 10:58:24 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Basic implementation of ft_strcmp from piscine.
 * 
 * @param s1		The first string 
 * @param s2 		The second string
 * @return int 		The first difference found
 */
static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

/**
 * @brief Function used to delay printed actions to compare the
 * last one with the new one and combine them if possible.
 * 
 * @param action 		The action to print
 */
void	ft_print_instruction(char *action)
{
	static char	*last_action;

	if (!last_action)
		last_action = ft_strdup(action);
	else
	{
		if ((!ft_strcmp(last_action, "sa") && !ft_strcmp(action, "sb"))
			|| (!ft_strcmp(last_action, "sb") && !ft_strcmp(action, "sa")))
			ft_printf("ss\n");
		else if ((!ft_strcmp(last_action, "ra") && !ft_strcmp(action, "rb"))
			|| (!ft_strcmp(last_action, "rb") && !ft_strcmp(action, "ra")))
			ft_printf("rr\n");
		else if ((!ft_strcmp(last_action, "rra") && !ft_strcmp(action, "rrb"))
			|| (!ft_strcmp(last_action, "rrb") && !ft_strcmp(action, "rra")))
			ft_printf("rrr\n");
		else
		{
			ft_printf("%s\n", last_action);
			if (ft_strcmp(action, ""))
				ft_printf("%s\n", action);
		}
		if (last_action)
			free(last_action);
		last_action = NULL;
	}
}
