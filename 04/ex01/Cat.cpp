/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:10:11 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/28 17:44:55 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("cat")
{
	this->brain = new Brain;
	std::cout << "A cat has been created." << std::endl;
}

Cat::Cat(const Cat &copy) : brain()
{
	*this = copy;
	std::cout << "Cat has been copied!" << std::endl;
}

Cat &Cat::operator=(const Cat &c)
{
	if (this == &c)
		return (*this);
	this->type = c.type;
	if (this->brain)
		delete (this->brain);
	this->brain = new Brain(*c.brain);
	std::cout << "Cat operator called." << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete (this->brain);
	std::cout << "Cat destructed." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "The cat meows." << std::endl;
}

Brain *Cat::getBrain()
{
	return (this->brain);
}