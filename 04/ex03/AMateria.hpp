/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:55:16 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/25 17:42:42 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class	ICharacter;

class AMateria
{
  protected:
	std::string type;

  public:
	AMateria();
	virtual ~AMateria();
	AMateria &operator=(const AMateria &a);
	AMateria(const AMateria &copy);
	AMateria(std::string const &type);
	std::string const &getType() const; //Returns the materia type
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif