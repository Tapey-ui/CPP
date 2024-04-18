/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:21:12 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/21 19:46:06 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Anon"), hp(10), energy(10), ad(0)
{
	std::cout << "ClapTrap " << this->name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), energy(10), ad(0)
{
	std::cout << "ClapTrap " << this->name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	*this = copy;
	std::cout << "ClapTrap copied!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->name << " destroyed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &cl)
{
	this->name = cl.name;
	this->hp = cl.hp;
	this->energy = cl.energy;
	this->ad = cl.ad;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->energy == 0 || this->hp == 0)
		std::cout << "ClapTrap " << this->name << " is exhausted! Rebooting..." << std::endl;
	else
	{
		this->energy -= 1;
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", dealing " << this->ad << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	if (amount > this->hp)
		this->hp -= amount;
	if (this->hp <= 0)
		std::cout << "Claptrap " << this->name << " exploded into smithereens!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy == 0)
		std::cout << "ClapTrap " << this->name << " is too tired to heal itself!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " heals " << amount << " points of health!" << std::endl;
		this->hp++;
		this->energy--;
	}
}