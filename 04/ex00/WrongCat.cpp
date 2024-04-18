/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 00:26:55 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/22 00:30:35 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
	: WrongAnimal()
{
	setType("WrongCat");
	std::cout << "A " << getType() << " has been created!"
				<< std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
	: WrongAnimal(copy)
{
	*this = copy;
	std::cout << "WrongCat has been copied!" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat is down!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &c)
{
	this->type = c.type;
	std::cout << "WrongCat details has been assigned!" << std::endl;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "The " << getType() << " meows...?" << std::endl;
}