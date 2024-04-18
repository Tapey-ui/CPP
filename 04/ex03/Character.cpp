/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 00:01:20 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/26 20:59:43 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"

Character::Character()
	: name("Anon")
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->del[i] = NULL;
	std::cout << getName() << " has been born!" << std::endl;
}

Character::Character(const std::string name)
	: name(name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->del[i] = NULL;
	std::cout << getName() << " has been born!" << std::endl;
}

Character &Character::operator=(const Character &ch)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = ch.inventory[i]->clone();
	for (int i = 0; i < 100; i++)
	{
		if (ch.del[i] != NULL)
			this->del[i] = ch.del[i]->clone();
	}
	this->name = ch.name;
	return (*this);
}

Character::Character(const Character &copy)
{
	*this = copy;
	std::cout << this->getName() << " has been copied!" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete (this->inventory[i]);
	}
	for (int i = 0; i < 100; i++)
	{
		if (this->del[i] != NULL)
			delete (this->del[i]);
	}
	std::cout << getName() << " is dead!" << std::endl;
}

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << "Can't equip if you have nothing!" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			inventory[i] = m;
			std::cout << m->getType() << " is equipped in slot " << i << std::endl;
			return ;
		}
	}
	delete (m);
	std::cout << "Inventory full!" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Please select a slot from 0 to 3!" << std::endl;	
		return ;
	}
	if (this->inventory[idx] != NULL)
	{
		for (int i = 0; i < 100; i++)
		{
			if (this->del[i] == NULL)
			{
				this->del[i] = this->inventory[idx];
				this->inventory[idx] = NULL;
				std::cout << "Item " << idx << " removed!" << std::endl;
				return ;
			}
		}
		std::cout << "Too much removed items!" << std::endl;
	}
	else
		std::cout << "Inventory does not exists!" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Please select a slot from 0 to 3!" << std::endl;
		return ;
	}
	if (&target == nullptr)
	{
		std::cout << "WHO ARE YOU AIMING AT!" << std::endl;
		return ;
	}
	if (this->inventory[idx] != NULL)
	{
		std::cout << this->name << " > ";
		this->inventory[idx]->use(target);
	}
	else
		std::cout << "Inventory does not exists!" << std::endl;
}