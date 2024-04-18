/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:16:52 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/26 01:18:43 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < this->maxRecipe; i++)
		this->recipe[i] = NULL;
	std::cout << "Recipe created!" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	MateriaSource::operator=(copy);
	std::cout << "Recipe copied!" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &m)
{
	for (int i = 0; i < this->maxRecipe; i++)
	{
		if (m.recipe[i] != NULL)
			this->recipe[i] = m.recipe[i];
		else
			this->recipe[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < this->maxRecipe; i++)
	{
		if (this->recipe[i] != NULL)
			delete (this->recipe[i]);
	}
	std::cout << "Recipe destructed!" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < this->maxRecipe; i++)
	{
		if (!m)
		{
			std::cout << "Materia not detected. Learning failed!" << std::endl;
			return ;
		}
		else
		{
			if (this->recipe[i] == NULL)
			{
				this->recipe[i] = m;
				std::cout << m->getType() << " has been learned on slot " << i << std::endl;
				return ;
			}
		}
	}
	std::cout << "Inventory full, please unequip to learn!" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < this->maxRecipe; i++)
	{
		if (this->recipe[i] && this->recipe[i]->getType().compare(type) == 0)
		{
			std::cout << "Creating Materia Source " << type << " !" << std::endl;
			return (this->recipe[i]->clone());
		}
	}
	std::cout << "Materia Source unknown!" << std::endl;
	// for (int i = 0; i < this->maxRecipe; i++)
	// {
	// 	if (this->recipe[i] != NULL)
	// 	{
	// 		delete(this->recipe[i]);
	// 		this->recipe[i] = NULL;
	// 	}
	// }
	return (NULL);
}

void MateriaSource::displayKnownRecipes(void)
{
	std::cout << "LIST OF RECIPES : " << std::endl;
	for (int i = 0; i < this->maxRecipe; i++)
	{
		if (this->recipe[i] != NULL)
			std::cout << i << ". " << this->recipe[i] << std::endl;
		else
			std::cout << i << ". Nothing" << std::endl;
	}
}