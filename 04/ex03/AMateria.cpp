/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:07:26 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/25 17:53:30 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
	: type("unknown")
{
	std::cout << "AMateria type " << getType() << " has been created." << std::endl;
}

AMateria &AMateria::operator=(const AMateria &a)
{
	this->type = a.type;
	std::cout << "AMateria type " << getType() << " operator called." << std::endl;
	return (*this);
}

AMateria::AMateria(const AMateria &copy)
{
	*this = copy;
	std::cout << "AMateria type " << getType() << " has been copied." << std::endl;
}

AMateria::AMateria(std::string const &type)
	: type(type)
{
	std::cout << "AMateria type " << getType() << " has been created." << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria type " << getType() << " has been destroyed." << std::endl;
}

std::string const &AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* uses " << getType() << " on " << target.getName() << " which has no effect *" << std::endl;
}