/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 23:00:41 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/15 20:41:20 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void swap(T &x, T &y)
{
    T tmp;

    tmp = x;
    x = y;
    y= tmp;
}

template <typename T>
const T &min(T &x, T &y)
{
    if (x < y)
        return x;
    else 
        return y;
}

template <typename T>
const T &max(T &x, T &y)
{
    if (x > y)
        return x;
    else 
        return y;
}

#endif