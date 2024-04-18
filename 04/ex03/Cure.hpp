/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:04:30 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/25 17:41:19 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
  public:
	Cure();
	~Cure();
	Cure &operator=(const Cure &c);
	Cure(const Cure &copy);
	std::string const &getType() const; //Returns the materia type
	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif