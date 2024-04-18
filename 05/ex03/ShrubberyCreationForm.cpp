/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 01:10:15 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/06 16:40:43 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), target(copy.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &s)
{
    (void)s;
    return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() > this->getGradeExe())
        throw Bureaucrat::GradeTooLowException();
    else if (this->getSign() == false)
        throw AForm::NotSignedException();
    try
    {
        std::ofstream file((this->target + "_shrubbery").c_str());
        if (!file.is_open())
            throw std::runtime_error("Error: Unable to open file!");
        file << "          &&& &&  & &&" << std::endl;
        file << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
        file << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
        file << "   &() &\\/&|()|/&\\/ '%' & ()" << std::endl;
        file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
        file << "&&   && & &| &| /& & % ()& /&&" << std::endl;
        file << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
        file << "     &&     \\|||" << std::endl;
        file << "             |||" << std::endl;
        file << "             |||" << std::endl;
        file << "             |||" << std::endl;
        file << "       , -=-~  .-^- _" << std::endl;
        file.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
