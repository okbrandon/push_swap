/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_checker_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:51:33 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/27 10:55:13 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker_bonus.h"

/**
 * @brief A simple function to check if a character is a sign 
 * 
 * @param c			the character to check
 * @return int 		returns if its a sign or not
 */
static int	ft_is_sign(char c)
{
	return (c == '+' || c == '-');
}

/**
 * @brief Compute the arguments and check if they're valid.
 * If they're not, it makes the program exit.
 * 
 * @param argv 		the arguments to check
 */
void	ft_are_args_valid(char *argv)
{
	int	i;
	int	consecutive_signs;

	i = 0;
	consecutive_signs = 1;
	while (argv[i])
	{
		if (ft_is_sign(argv[i]) && argv[i - 1] != ' ' && i != 0)
			ft_error(NULL, NULL, NULL);
		if (ft_is_sign(argv[i]) && !ft_isdigit(argv[i + 1]))
			ft_error(NULL, NULL, NULL);
		if (ft_isdigit(argv[i]) || argv[i] == ' ')
			consecutive_signs = 0;
		if (ft_is_sign(argv[i]) && consecutive_signs < 2)
			consecutive_signs++;
		if (!ft_isdigit(argv[i]) && !ft_is_sign(argv[i]) && argv[i] != ' ')
			ft_error(NULL, NULL, NULL);
		i++;
	}
}

/**
 * @brief A function to check if a char array only contains spaces
 * 
 * @param argv			the char array to check
 * @return int 			returns if the char array only contains spaces
 */
static int	ft_is_only_spaces(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief A function to check if the arguments count is right and
 * if the arguments are valid. If they're somehow not valid,
 * the program will exit it.
 * 
 * @param argc			the argument count
 * @param argv 			the arguments to check
 */
void	ft_check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			ft_error(NULL, NULL, NULL);
		i++;
	}
	i = 1;
	while (i < argc)
	{
		if (ft_is_only_spaces(argv[i]))
			ft_error(NULL, NULL, NULL);
		ft_are_args_valid(argv[i]);
		i++;
	}
}
