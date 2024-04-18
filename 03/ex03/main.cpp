/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:46:28 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/25 14:25:56 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap a("Bob");
    a.attack("Fake Bob");
    DiamondTrap b(a);
    b.attack("Fake Bob 2");
    DiamondTrap c;
    c = b;
	c.attack("Bob?");
	// for (int i = 0; i < 50; i++)
	// 	c.attack("noob");
    b.whoAmI();
    c.guardGate();
    c.highFivesGuys();
	return (0);
}