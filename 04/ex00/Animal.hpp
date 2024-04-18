/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:54:01 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/28 17:22:28 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
  protected:
	std::string type;

  public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &copy);
	Animal &operator=(const Animal &a);
	virtual ~Animal();
	virtual void makeSound() const;
	std::string getType() const;
	void setType(std::string t);
};

#endif