/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 00:46:16 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/24 14:18:30 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
  public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &copy);
	MateriaSource &operator=(const MateriaSource &m);
	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);
	void displayKnownRecipes(void);

  private:
	static int const maxRecipe = 4;
	AMateria *recipe[maxRecipe];
};

#endif