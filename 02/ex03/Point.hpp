/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:49:22 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/21 01:01:25 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    Fixed const x;
    Fixed const y;

public:
    Point(void);
    Point(const Fixed x, const Fixed y);
    Point(const Point &copy);
    ~Point(void);

    Point &operator=(const Point &copy);

    Fixed getX(void) const;
    Fixed getY(void) const;
};

#endif