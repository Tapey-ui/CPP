/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:31:04 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/28 17:44:39 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("dog")
{
	this->brain = new Brain;
	std::cout << "A dog has been created." << std::endl;
}

Dog::Dog(const Dog &copy) : brain()
{
	*this = copy;
	std::cout << "Dog has been copied!" << std::endl;
}
// Dog::Dog(const Dog &copy) : brain(NULL)
// {
// 	std::cout << "Dog has been copied!" << std::endl;
// 	*this = copy;
// }

Dog &Dog::operator=(const Dog &d)
{
	if (this == &d)
		return (*this);
	this->type = d.type;
	if (this->brain != NULL)
		delete (this->brain);
	this->brain = new Brain(*d.brain);
	std::cout << "Dog operator called." << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete (this->brain);
	std::cout << "Dog destructed." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "The Dog barks." << std::endl;
}

Brain *Dog::getBrain()
{
	return (this->brain);
}