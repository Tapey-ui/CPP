/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:46:28 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/24 01:33:23 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap a("Bob");
    a.takeDamage(3);
    ScavTrap b(a);
    b.takeDamage(3);
    ScavTrap c;
    c = b;
    c.takeDamage(3);
	c.takeDamage(999);
	c.beRepaired(1);
	c.beRepaired(100);
	c.guardGate();
	for (int i = 0; i < 50; i++)
		c.attack("noob");
    c.guardGate();
	return (0);
}