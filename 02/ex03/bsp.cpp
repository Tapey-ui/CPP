/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:08:58 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/22 23:18:37 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

static float ft_abs(float num)
{
    if (num < 0)
        return (-num);
    else
        return (num);
}

static float triArea(Point const a, Point const b, Point const c)
{
    return (0.5 * ft_abs((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())) +
                         (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())) +
                         (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float area = triArea(a, b, c);
    float minArea1 = triArea(a, b, point);
    float minArea2 = triArea(b, c, point);
    float minArea3 = triArea(c, a, point);

    std::cout << minArea1 + minArea2 + minArea3 << " " << area << std::endl;
    if ((minArea1 + minArea2 + minArea3 == area) && (minArea1 != 0 && minArea2 != 0 && minArea3 != 0))
        return (true);
    return (false);
}