/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 01:12:43 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/24 02:00:11 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Anon_clap_name")
{
    this->name = "Anon";
    this->hp = FragTrap::hp;
    this->energy = ScavTrap::energy;
    this->ad = FragTrap::ad;
    std::cout << "DiamondTrap " << this->name << " created!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
    this->name = name;
    this->hp = FragTrap::hp;
    this->energy = ScavTrap::energy;
    this->ad = FragTrap::ad;
    std::cout << "DiamondTrap " << this->name << " created!" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
    *this = copy;
    std::cout << "DiamondTrap copied!" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap " << this->name << " destroyed!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &dt)
{
    this->name = dt.name + "_clap_name";
    this->hp = dt.hp;
    this->energy = dt.energy;
    this->ad = dt.ad;
    return (*this);
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "I am a DiamondTrap named " << this->name
              << " derived from the ClapTrap named " << ClapTrap::name
              << std::endl;
}