/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:57:59 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/15 20:55:25 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
    try
    {
        Array<int> a(6);
        for (int i(0); i < 3; i++)
            a[i] = i;
        std::cout << "String: ";
        for (unsigned int i = 0; i < a.size(); i++)
        {
            if (i != a.size() - 1)
                std::cout << a[i] << ", ";
            else
                std::cout << a[i];
        }
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
}
