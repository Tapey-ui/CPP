/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:11:34 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/14 17:05:18 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat b("test", 1);
    try {
        PresidentialPardonForm f(b.getName());
        f.beSigned(b);
        std::cout << f;
        f.execute(b);
        std::cout << f;
        f.beSigned(b);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        RobotomyRequestForm g(b.getName());
        g.beSigned(b);
        g.execute(b);
        std::cout << g;
        g.beSigned(b);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        ShrubberyCreationForm h(b.getName());
        h.beSigned(b);
        h.execute(b);
        std::cout << h;
        // h.beSigned(b);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}