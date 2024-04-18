/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:35:53 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/26 18:51:37 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class	AMateria;

class Character : public ICharacter
{
  private:
	AMateria *inventory[4];
	AMateria *del[100];
	std::string name;

  public:
	Character();
	~Character();
	Character(const std::string name);
	Character(const Character &copy);
	Character &operator=(const Character &ch);
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif