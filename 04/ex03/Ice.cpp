/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:30:18 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/26 17:57:33 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
// comment to prevent order swap
#include "ICharacter.hpp"

Ice::Ice()
{
	this->type = "ice";
	std::cout << getType() << " has been created!" << std::endl;
}

Ice &Ice::operator=(const Ice &i)
{
	this->type = i.type;
	std::cout << getType() << " operator called!" << std::endl;
	return (*this);
}

Ice::Ice(const Ice &copy)
{
	*this = copy;
	std::cout << getType() << " copied!" << std::endl;
}

Ice::~Ice()
{
	std::cout << getType() << " destroyed!" << std::endl;
}

std::string const &Ice::getType() const
{
	return (this->type);
}

AMateria *Ice::clone() const
{
	AMateria *ice = new Ice();
	std::cout << "New " << getType() << " cloned!" << std::endl;
	return (ice);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}