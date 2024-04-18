/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:52:33 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/22 17:22:52 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie* zombieHorde(int N, std::string name);

int	main()
{
	std::string name;
    int amount;
    // stack
    std::cout << "Zombie : ";
    std::cin >> name;
    if (name.length() == 0 || std::cin.fail())
    {
        std::cout << "Error: Please enter a name." << std::endl;
		return (0);
    }
    std::cout << "Amount : ";
    std::cin >> amount;
	if (amount <= 0 || std::cin.fail())
	{
		std::cout << "Error: Please fill in a positive number." << std::endl;
		return (0);
	}
    Zombie *h = zombieHorde(amount, name);
    for (int i = 0; i < amount; i++)
	{
		std::cout << i << ": ";
        h->announce();
	}
    delete[] h;
    return (0);
}