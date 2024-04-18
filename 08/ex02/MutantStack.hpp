/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:36:48 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/16 15:51:01 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack(){};
        ~MutantStack(){};
        MutantStack(const MutantStack &copy)
        {
            *this = copy;
        }
        MutantStack &operator=(const MutantStack &s)
        {
            if (*this != s)
                std::stack<T>::operator=(s);
            return *this;
        }
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin()
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
        
};

#endif