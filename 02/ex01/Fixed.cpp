/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:40:37 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/23 18:19:51 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : value(0)
{
    std::cout << "Default constructor called." << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called." << std::endl;
}

Fixed::Fixed(const int val)
{
    // left shift in by num of frac bits
    this->value = val << this->bits;
    std::cout << "Int constructor called." << std::endl;
}

Fixed::Fixed(const float val)
{
    // multiple the float by scaling factor, where the scaling factor is defined as 1 «  bits
    // roundf: round the value after bit shifting (apparently post bit shifting value can also have decimals)
    this->value = std::roundf(val * (1 << this->bits));
    std::cout << "Float constructor called." << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called." << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called." << std::endl;
    this->value = copy.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called." << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const bits)
{
    this->value = bits;
}

float Fixed::toFloat(void) const
{
    return ((float)this->value / (float)(1 << this->bits));
}

int Fixed::toInt(void) const
{
    return ((int)this->value >> this->bits);
}

std::ostream &operator<<(std::ostream &str, Fixed const &n)
{
    return (str << n.toFloat());
}