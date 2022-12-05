/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:13:28 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/05 12:14:53 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/***
 * a function to verify if the stack is sorted
 * it should take a pointer to t_stack
 * it will iterate over the stack's size - 1
 *  and check if the current element is smaller than the next one
 *  if it is, it will return 1
 * if it isn't, it will return 0
*/