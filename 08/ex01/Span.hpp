/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 02:09:29 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/16 13:55:43 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <stdlib.h>

class Span
{
    private:
        unsigned int N;
        std::vector<int> vec;

    public:
        Span();
        Span(unsigned int N);
        ~Span();
        Span(const Span &copy);
        Span &operator=(const Span &s);

        void addNumber(int i);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        int shortestSpan();
        int longestSpan();

        class VecFullException: public std::exception
        {
            virtual const char	*what( void ) const throw();
        };

        class InsufficientValuesException: public std::exception
        {
            virtual const char	*what( void ) const throw();
        };
};

#endif