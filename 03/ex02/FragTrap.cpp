/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 01:03:29 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/22 01:04:03 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
    this->name = "Anon";
    this->hp = 100;
    this->energy = 100;
    this->ad = 30;
    std::cout << "FragTrap " << this->name << " created!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->name = name;
    this->hp = 100;
    this->energy = 100;
    this->ad = 30;
    std::cout << "FragTrap " << this->name << " created!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy)
{
    *this = copy;
    std::cout << "FragTrap copied!" << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << this->name << " destroyed!" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &sc)
{
    this->name = sc.name;
    this->hp = sc.hp;
    this->energy = sc.energy;
    this->ad = sc.ad;
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << this->name << ": Here's your high five! :D" << std::endl;
}