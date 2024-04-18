/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:56:44 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/24 23:48:33 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    this->name = "Anon";
    this->hp = 100;
    this->energy = 50;
    this->ad = 20;
    std::cout << "ScavTrap " << this->name << " created!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->name = name;
    this->hp = 100;
    this->energy = 50;
    this->ad = 20;
    std::cout << "ScavTrap " << this->name << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
    *this = copy;
    std::cout << "ScavTrap copied!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << this->name << " destroyed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &sc)
{
    this->name = sc.name;
    this->hp = sc.hp;
    this->energy = sc.energy;
    this->ad = sc.ad;
    return (*this);
}

void ScavTrap::attack(const std::string &target)
{
    if (this->energy == 0 || this->hp == 0)
        std::cout << "ScavTrap " << this->name << " is exhausted! Rebooting..." << std::endl;
    else
    {
        this->energy -= 1;
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", dealing " << this->ad << " points of damage!" << std::endl;
    }
}

void ScavTrap::guardGate(void)
{
    if (this->energy == 0 || this->hp == 0)
        std::cout << "ScavTrap " << this->name << " is exhausted and cannot switch to guard mode!" << std::endl;
    else
    {
        this->energy -= 1;
        std::cout << "ScavTrap " << this->name << " is now in gatekeeper mode." << std::endl;
    }
}