/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:29:56 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/28 17:37:06 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
  private:
	Brain *brain;

  public:
	Dog();
	Dog(const Dog &copy);
	Dog &operator=(const Dog &d);
	virtual ~Dog();
	void makeSound() const;
	Brain *getBrain();
};

#endif