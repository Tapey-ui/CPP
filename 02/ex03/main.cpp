/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:25:19 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/24 23:20:31 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main(void)
{
    {
        const Point a(0, 0);
        const Point b(0, 0);
        const Point c(0, 0);
        const Point point(1, 1);

        std::cout << "The point( x= " << point.getX() << "\t\ty= " << point.getY() << "\t) is inside the triangle\n"
                  << "\ta( x= " << a.getX() << "\t\ty= " << a.getY() << "\t)\n"
                  << "\tb( x= " << b.getX() << "\ty= " << b.getY() << "\t)\n"
                  << "\tc( x= " << c.getX() << "\t\ty= " << c.getY() << "\t)\n"
                  << std::endl;
        if (bsp(a, b, c, point) == true)
            std::cout << "\033[32mTRUE\033[0m" << std::endl;
        else
            std::cout << "\033[31mFALSE\033[0m" << std::endl;
    }
    std::cout << "\n---------------------------------------------------------------------\n"
              << std::endl;
    {
        Point a(-1.5f, -1.5f);
        Point b(2.5f, 2.5f);
        Point c(-1, -2);
        Point point(0, -0.5f);

        std::cout << "The point( x= " << point.getX() << "\ty= " << point.getY() << "\t) is inside the triangle\n"
                  << "\ta( x= " << a.getX() << "\ty= " << a.getY() << "\t)\n"
                  << "\tb( x= " << b.getX() << "\ty= " << b.getY() << "\t)\n"
                  << "\tc( x= " << c.getX() << "\ty= " << c.getY() << "\t)\n"
                  << std::endl;
        if (bsp(a, b, c, point) == true)
            std::cout << "\033[32mTRUE\033[0m" << std::endl;
        else
            std::cout << "\033[31mFALSE\033[0m" << std::endl;
    }
    return (0);
}