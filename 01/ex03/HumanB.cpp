/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:14:22 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/22 20:55:14 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), w(NULL)
{
	std::cout << name << " is created" << std::endl;
}

HumanB::~HumanB()
{
}

void HumanB::attack(void)
{
	if (this->w == NULL)
		std::cout << "Human " << this->name << " attacks with deez hands" << std::endl;
	else
    	std::cout << "Human " << this->name << " attacks with " << this->w->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &w)
{
	this->w = &w;
}