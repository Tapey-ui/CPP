/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 00:24:59 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/15 20:48:02 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T>
// void    iter(T *arr, int len, void (*f)(const T &))
// {
//     if (arr == NULL || f == NULL)
//         return ;
//     for (int i = 0; i < len; i++)
//         f(arr[i]);
// }
void    iter(T *arr, int len, void (*f)(const T &))
{
    if (arr == NULL || f == NULL)
        return ;
    for (int i = 0; i < len; i++)
        f(arr[i]);
}

#endif