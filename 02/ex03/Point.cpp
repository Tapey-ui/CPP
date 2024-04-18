/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:07:19 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/21 01:08:21 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void) : x(0), y(0)
{
}

Point::Point(Fixed const _x, Fixed const _y) : x(_x), y(_y)
{
}

Point::Point(Point const &copy) : x(copy.getX()), y(copy.getY())
{
}

Point::~Point(void)
{
}

Point &Point::operator=(Point const &copy)
{
    if (this == &copy)
        return (*this);
    (Fixed)this->x = copy.getX();
    (Fixed)this->y = copy.getY();
    return (*this);
}

Fixed Point::getX(void) const
{
    return (this->x);
}

Fixed Point::getY(void) const
{
    return (this->y);
}