/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:51:33 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/03 14:59:10 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/***
 * A void function to check if the argv are valid
 * argv is a char array
 * we should have an index i to iterate over the array
 * and a counter to count the number of consecutive signs (+ or -)
 * we loop into the array and check if the char isn't \0
 * if the char is a sign and the previous char is a space and the index is not 0
 * we call ft_error to exit the program
 * if the char is a sign and the next char is not a digit
 * we call ft_error to exit the program
 * if the char is a digit or a space we set the sign counter to 0
 * if the char is a sign and the sign counter is less than 2
 * we increment the sign counter
 * if the char is not a digit or a space or a sign
 * we call ft_error to exit the program
 * we increment the index
*/

/***
 * A int function to check if the argv contains only spaces
 * argv is a char array
 * we should have an index i to iterate over the array
 * we loop into the array and check if the char isn't \0
 * if the char is not a space we return 0
 * we increment the index
 * if the char is \0 we return 1
*/

/***
 * A void function to check if the argc and argv are valid
 * argc is an int
 * argv is a char of char array
 * we should have an index i to iterate over the array
 * we loop into the array and check if the index is less than argc
 * if argv[i][0] is empty (== \0) we call ft_error to exit the program
 * we increment the index
 * once the first loop is done, we loop into the array again
 * and check if the index is less than argc
 * if argv[i] contains only spaces we call ft_error to exit the program
 * we call ft_verif_args to check if the argv are valid
 * we increment the index
*/