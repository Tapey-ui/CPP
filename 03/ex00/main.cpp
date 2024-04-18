/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:46:28 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/24 01:18:58 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("why");
    a.takeDamage(3);
    ClapTrap b(a);
    b.takeDamage(3);
    ClapTrap c;
    c = b;
    c.takeDamage(3);
	c.takeDamage(999);
	c.beRepaired(1);
	c.beRepaired(100);
	for (int i = 0; i < 10; i++)
		c.attack("noob");
    ClapTrap d("derp");
    d.takeDamage(3);
    d.takeDamage(999);
	d.beRepaired(1);
	d.beRepaired(100);
	for (int i = 0; i < 10; i++)
		d.attack("noob");
	return (0);
}