/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:46:28 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/24 23:49:32 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    FragTrap a("Bob");
    a.takeDamage(3);
    FragTrap b(a);
    b.takeDamage(3);
    FragTrap c;
    c = b;
    c.takeDamage(3);
	c.takeDamage(999);
	c.beRepaired(1);
	c.beRepaired(100);
	c.highFivesGuys();
	for (int i = 0; i < 100; i++)
		c.attack("noob");
	c.highFivesGuys();
	return (0);
}