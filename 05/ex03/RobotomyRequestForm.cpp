/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 02:27:52 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/06 16:40:52 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), target(copy.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &s)
{
    (void)s;
    return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() > this->getGradeExe())
        throw Bureaucrat::GradeTooLowException();
    else if (this->getSign() == false)
        throw AForm::NotSignedException();
    std::cout << "* insert drilling noises here *" << std::endl;
    std::srand(std::time(0));
    if (rand() % 2 == 0)
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << this->target << "'s robotomization has failed!" << std::endl;
}
