/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 00:24:52 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/22 00:31:04 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "A mistake";
	std::cout << getType() << " has been created." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	setType(type);
	std::cout << getType() << " has been created." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	*this = copy;
	std::cout << getType() << " has been copied!" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &a)
{
	setType(a.type);
	std::cout
		<< getType() << " operator has been called!" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << getType() << " has been destroyed." << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << getType() << " is making an unknown sound." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}

void WrongAnimal::setType(std::string t)
{
	this->type = t;
}