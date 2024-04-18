/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:35:35 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/16 15:46:28 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(2);
        // sp.addNumber(-3);
        // sp.addNumber(17);
        // sp.addNumber(9);
        // sp.addNumber(31);
        // sp.addNumber(31);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    // try
    // {
    //     Span sp = Span(1000);
    //     std::vector<int> arr;
    //     for (int i = 0; i < 1000; i++)
    //         arr.push_back(i);
    //     sp.addNumber(arr.begin(), arr.end());
    //     std::cout << sp.shortestSpan() << std::endl;
    //     std::cout << sp.longestSpan() << std::endl;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << "Error: " << e.what() << '\n';
    // }
    return (0);
}