/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:03:33 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/25 17:41:17 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
  public:
	Ice();
	~Ice();
	Ice &operator=(const Ice &i);
	Ice(const Ice &copy);
	std::string const &getType() const; //Returns the materia type
	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif