/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:58:12 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/26 17:57:39 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
	: AMateria("cure")
{
	std::cout << getType() << " has been created!" << std::endl;
}

Cure &Cure::operator=(const Cure &c)
{
	AMateria::operator=(c);
	std::cout << getType() << " operator called!" << std::endl;
	return (*this);
}

Cure::Cure(const Cure &copy)
{
	*this = copy;
	std::cout << getType() << " copied!" << std::endl;
}

Cure::~Cure()
{
	std::cout << getType() << " destroyed!" << std::endl;
}

std::string const &Cure::getType() const
{
	return (this->type);
}

AMateria *Cure::clone() const
{
	AMateria *cure = new Cure();
	std::cout << "New " << getType() << " cloned!" << std::endl;
	return (cure);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heal " << target.getName() << "'s wounds *" << std::endl;
}