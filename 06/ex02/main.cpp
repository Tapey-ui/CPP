/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:45:15 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/15 11:21:15 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cmath>
#include <ctime>
#include <stdlib.h>

Base *generate()
{
    std::srand(std::time(0));
    int i = rand() % 3;
    switch (i)
    {
        case 0:
            return (new A);
        case 1:
            return (new B);
        case 2:
            return (new C);
    }
    return (NULL);
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
		std::cout << "Identified class: A" << std::endl;
    else if (dynamic_cast<B*>(p))
		std::cout << "Identified class: B" << std::endl;
    else if (dynamic_cast<C*>(p))
		std::cout << "Identified class: C" << std::endl;
    else
		std::cout << "Unknown class" << std::endl;
}

void identify(Base& p)
{
    try
    {
        if (dynamic_cast<A*>(&p))
            std::cout << "Identified class: A" << std::endl;
        else if (dynamic_cast<B*>(&p))
            std::cout << "Identified class: B" << std::endl;
        else if (dynamic_cast<C*>(&p))
            std::cout << "Identified class: C" << std::endl;
        else
            throw NullException();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Unknown class" << std::endl;
    }
}

const char *NullException::what(void) const throw() {
    return ("Unknown class");
};

int main()
{
	Base *b = generate();
    Base *a = NULL;
	identify(*b);
	identify(b);
    identify(*a);
    identify(a);
	delete b;
}