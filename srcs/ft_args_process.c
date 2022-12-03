/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:47:39 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/03 18:17:19 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/***
 * a free and join function that takes two char * and returns a char *
 * it should strjoin the two strings and free the first one
 * and return the new string
*/

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