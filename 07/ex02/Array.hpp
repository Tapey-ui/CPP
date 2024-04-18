/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 02:13:43 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/15 20:20:24 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T *array;
        unsigned int _size;

    public:
        Array();
        ~Array();
        Array(unsigned int n);
        Array(const Array &copy);
        Array &operator=(const Array &a);

        unsigned int size(void) const;
        T &operator[](unsigned int i);
        class ExceedLimitException : public std::exception {
			public :
				virtual const char*what( void ) const throw();
		};
};

template <typename T>
Array<T>::Array() : _size(0)
{
    this->array = new T[_size];
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->array;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    this->array = new T[_size];
}

template <typename T>
Array<T>::Array(const Array &copy)
{
    *this = copy;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &a)
{
    if (this->array != NULL)
        delete[] this->array;
    if (a._size != 0)
    {
        this->_size = a._size;
        this->array = new T[a._size];
        for (unsigned int i; i < a._size; i++)
            this->array[i] = a.array[i];
    }
    return (*this);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return this->_size;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= this->_size || this->array == NULL)
        throw ExceedLimitException();
    return (this->array[i]);
}

template <typename T>
const char *Array<T>::ExceedLimitException::what() const throw()
{
	return "Index exceeded array size";
}

#endif