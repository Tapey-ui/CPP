/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 00:29:49 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/28 17:58:21 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int test(void)
{
	std::string str;
	std::string str2;
	Animal *meta[10];

	for (size_t i = 0; i < 10; i++)
	{
		if (i % 2)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
		std::cout << "Created " << meta[i]->getType() << " no. " << i << std::endl;
	}
	std::cout << std::endl;

	for (size_t i = 0; i < 10; i++)
	{
		delete meta[i];
	}
	std::cout << std::endl;

	Dog *d = new Dog();
	Dog *d2 = new Dog();
	Dog *d3 = new Dog();
	std::cout << std::endl;
	str = d->getBrain()->getIdeas(0);
	std::cout << "Dog1's first idea is " << str << std::endl;

	d->getBrain()->setIdeas("something", 0);
	str = d->getBrain()->getIdeas(0);
	std::cout << "Dog1's first idea is " << str << std::endl;

	*d2 = *d;
	str = d2->getBrain()->getIdeas(0);
	std::cout << "Dog2's first idea is " << str << std::endl;

	*d3 = *d;
	for (size_t i = 0; i < 10; i++)
	{
		d3->getBrain()->setIdeas(std::to_string(i), i);
		str = d3->getBrain()->getIdeas(i);
		str2 = d->getBrain()->getIdeas(i);
		std::cout << "Dog3's idea no. " << i << " is " << str << std::endl;
		std::cout << "Dog1's idea no. " << i << " is " << str2 << std::endl;
	}

	std::cout << std::endl;
	delete d;
	d = NULL;
	delete d2;
	d2 = NULL;
	delete d3;
	d3 = NULL;

	Dog basic;
	std::cout << basic.getBrain()->getIdeas(0) << std::endl;
	{
		Dog tmp = basic;
	}
	return (0);
}

int main(void)
{
	test();
	system("leaks Brain");
	return (0);
}