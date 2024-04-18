/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 01:29:05 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/28 18:08:56 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>
#include <string>

int run(void)
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("sahdce"));
	me->equip(src->createMateria("cure"));
	me->unequip(-2);
	me->unequip(3);
	me->unequip(5);
	me->unequip(3);
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Slot " << i << ": ";
		me->use(i, *me);
	}

	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;
	std::cout << std::endl;
	Character *pog = new Character("pog");
	pog->equip(src->createMateria("ice"));
	pog->equip(src->createMateria("ice"));
	pog->equip(src->createMateria("ice"));
	pog->equip(src->createMateria("cure"));
	Character *pogchamp = new Character(*pog);
	pogchamp->equip(src->createMateria("cure"));
	pogchamp->use(1, *pog);
	pogchamp->unequip(1);
	pogchamp->use(1, *pog);
	tmp = src->createMateria("ice");
	pogchamp->equip(tmp);
	pogchamp->use(1, *pog);
	pogchamp->unequip(1);
	pogchamp->use(1, *pog);
	Character *no = NULL;
	pogchamp->use(2, *no);

	std::cout << std::endl;
	std::cout << std::endl;
	delete (pog);
	delete (pogchamp);
	delete (bob);
	delete (me);
	delete (src);

	return (0);
}

int main(void)
{
	run();
	system("leaks AMateria");
	return (0);
}
