/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:52:33 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/19 19:02:37 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie* newZombie(std::string name);
void randomChump(std::string name);

int	main()
{
	Zombie *z;

	//stack
	std::cout << "Zombie (Stack): " << std::endl;
	randomChump("Stack");
	//heap
	std::cout << "Zombie (Heap): " << std::endl;
	z = newZombie("Heaps");
	z->announce();
	delete(z);
	return (0);
}