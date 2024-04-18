/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:31:04 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/27 00:24:17 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("dog")
{
	std::cout << "A dog has been created." << std::endl;
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog has been copied!" << std::endl;
	*this = copy;
}

Dog &Dog::operator=(const Dog &d)
{
	this->type = d.type;
	std::cout << "Dog operator called." << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructed." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "The Dog barks." << std::endl;
}

std::string Dog::getType() const
{
	return (this->type);
}