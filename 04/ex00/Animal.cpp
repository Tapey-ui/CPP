/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:06:08 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/27 00:16:10 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "unknown";
	std::cout << "An " << getType() << " animal has been created." << std::endl;
}

Animal::Animal(std::string type)
{
	setType(type);
	std::cout << "A/An " << getType() << " has been created." << std::endl;
}

Animal::Animal(const Animal &copy)
{
	*this = copy;
	std::cout << getType() << " has been copied!" << std::endl;
}

Animal &Animal::operator=(const Animal &a)
{
	setType(a.type);
	std::cout
		<< getType() << " operator has been called!" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << getType() << " has been destroyed." << std::endl;
}

void Animal::makeSound() const
{
	std::cout << getType() << " is making an unknown sound." << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::setType(std::string t)
{
	this->type = t;
}
