/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:45:06 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/16 15:39:45 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
    std::vector<int> vec;
    

	for(int i = 0; i < 100; i++)
		vec.push_back(i);
	try
	{
		std::cout << *easyfind(vec, 0) << std::endl;
		std::cout << *easyfind(vec, 42) << std::endl;
		std::cout << *easyfind(vec, 'a') << std::endl;
		std::cout << *easyfind(vec, 100) << std::endl;
	}
	catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
