/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:28:56 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/16 15:10:59 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0) {}

Span::~Span(){}

Span::Span(const Span &copy)
{
    *this = copy;
}

Span &Span::operator=(const Span &s)
{
    this->N = s.N;
    this->vec = s.vec;
    return (*this);
}

Span::Span(unsigned int N) : N(N) {}

void Span::addNumber(int i)
{
    if (this->vec.size() == this->N)
        throw VecFullException();
    else
        vec.push_back(i);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    while (begin < end)
    {
        if (this->vec.size() == this->N)
            throw VecFullException();
        else
        {
            this->vec.push_back(*begin);
            *begin++;
        }
    }
}

// void mySort(std::vector<int>::iterator begin, std::vector<int>::iterator end)
// {
    
// }

int Span::shortestSpan()
{
    if (this->vec.size() < 2)
        throw InsufficientValuesException();
    std::sort(this->vec.begin(), this->vec.end());
    int min = this->vec[1] - this->vec[0];
    for (size_t i = 1; i < this->vec.size() - 1; i++)
    {
        if (this->vec[i + 1] - this->vec[i] < min)
            min = (this->vec[i + 1] - this->vec[i]);
    }
    return (min);
}

int Span::longestSpan()
{   
    if (this->vec.size() < 2)
        throw InsufficientValuesException();
    std::sort(this->vec.begin(), this->vec.end());
    int max = abs(this->vec[this->vec.size() - 1] - this->vec[0]);
    return (max);
}

const char *Span::VecFullException::what(void) const throw()
{
	return ("Vector full");
}

const char *Span::InsufficientValuesException::what(void) const throw()
{
	return ("Not enough values");
}