/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:40:37 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/21 01:11:24 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed(void) : value(0)
{
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(const int val)
{
    // left shift in by num of frac bits
    this->value = val << this->bits;
}

Fixed::Fixed(const float val)
{
    // multiple the float by scaling factor, where the scaling factor is defined as 1 «  bits
    this->value = (val * (1 << this->bits));
}

Fixed::Fixed(const Fixed &copy)
{
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    this->value = copy.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
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
    return (this->value >> this->bits);
}

std::ostream &operator<<(std::ostream &str, Fixed const &n)
{
    return (str << n.toFloat());
}

bool Fixed::operator>(Fixed val) const
{
    return (this->toFloat() > val.toFloat());
}

bool Fixed::operator<(Fixed val) const
{
    return (this->toFloat() < val.toFloat());
}

bool Fixed::operator>=(Fixed val) const
{
    return (this->toFloat() >= val.toFloat());
}

bool Fixed::operator<=(Fixed val) const
{
    return (this->toFloat() <= val.toFloat());
}

bool Fixed::operator==(Fixed val) const
{
    return (this->toFloat() == val.toFloat());
}

bool Fixed::operator!=(Fixed val) const
{
    return (this->toFloat() != val.toFloat());
}

Fixed Fixed::operator+(Fixed val) const
{
    return (this->toFloat() + val.toFloat());
}

Fixed Fixed::operator-(Fixed val) const
{
    return (this->toFloat() - val.toFloat());
}

Fixed Fixed::operator*(Fixed val) const
{
    return (this->toFloat() * val.toFloat());
}

Fixed Fixed::operator/(Fixed val) const
{
    return (this->toFloat() / val.toFloat());
}

Fixed Fixed::operator++(void)
{
    this->value++;
    return (*this);
}

Fixed Fixed::operator--(void)
{
    this->value--;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;

    ++this->value;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;

    --this->value;
    return (*this);
}

const Fixed &Fixed::min(const Fixed &val1, const Fixed &val2)
{
    if (val1 < val2)
        return (val1);
    else
        return (val2);
}

const Fixed &Fixed::max(const Fixed &val1, const Fixed &val2)
{
    if (val1 >= val2)
        return (val1);
    else
        return (val2);
}