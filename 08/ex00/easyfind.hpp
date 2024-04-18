/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:11:44 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/16 15:38:38 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>

class NotExistException : public std::exception
{
    virtual const char* what() const throw()
    {
        return ("Value does not exist in array");
    }
};

template <typename T>
std::vector<int>::iterator easyfind(T &a, int n)
{
    std::vector<int>::iterator it = std::find(a.begin(), a.end(), n);
    
    if (it == a.end())
        throw NotExistException();
    return (it);
}

#endif