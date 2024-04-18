/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:10:11 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/27 00:24:22 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("cat")
{
	std::cout << "A cat has been created." << std::endl;
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat has been copied!" << std::endl;
	*this = copy;
}

Cat &Cat::operator=(const Cat &c)
{
	this->type = c.type;
	std::cout << "Cat operator called." << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructed." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "The cat meows." << std::endl;
}

std::string Cat::getType() const
{
	return (this->type);
}