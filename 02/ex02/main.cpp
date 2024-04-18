/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:25:19 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/24 23:16:28 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << "\t\tis a at start\n"
              << std::endl;
    std::cout << ++a << "\tis a at ++a\n"
              << std::endl;
    std::cout << a.getRawBits() << "\tis a at ++a\n"
              << std::endl;
    std::cout << a << "\tis a after ++a\n"
              << std::endl;
    std::cout << a++ << "\tis a at a++\n"
              << std::endl;
    std::cout << a << "\tis a after a++\n"
              << std::endl;

    std::cout << b << "\t\tvalue of b\n"
              << std::endl;

    std::cout << Fixed::max(a, b) << "\t\tthe max of a and b\n"
              << std::endl;
    std::cout << Fixed::min(a, b) << "\tthe min of a and b\n"
              << std::endl;

    return 0;
}