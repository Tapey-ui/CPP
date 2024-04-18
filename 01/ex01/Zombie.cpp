/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:30:40 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/22 17:40:44 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "A horde of zombies are coming!" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Zombie " << name << " is alive again!" <<std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << getName() << " has perished..." << std::endl;
}

void	Zombie::announce()
{
	std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName()
{
	return (this->name);
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}