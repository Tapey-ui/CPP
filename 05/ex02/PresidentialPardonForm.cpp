/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 02:51:23 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/06 16:41:01 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), target(copy.target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &s)
{
    (void)s;
    return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() > this->getGradeExe())
        throw Bureaucrat::GradeTooLowException();
    else if (this->getSign() == false)
        throw AForm::NotSignedException();
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}