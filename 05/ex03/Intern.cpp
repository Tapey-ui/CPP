/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 03:16:31 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/13 21:11:04 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern &copy)
{
    *this = copy;
}

Intern &Intern::operator=(const Intern &i)
{
    (void)i;
    return (*this);
}

AForm *Intern::makeForm(const std::string formName, const std::string target)
{
    std::string formList[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *form[] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};

    for (int i = 0; i < 3; i++)
    {
        if (formName == formList[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (form[i]);
        }
    }
    throw std::invalid_argument("Unable to create form " + formName);
}