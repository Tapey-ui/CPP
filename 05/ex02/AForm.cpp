/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 00:06:01 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/13 16:54:08 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Anon"), sign(false), gradeSign(150), gradeExe(150) {}

AForm::~AForm(){};

AForm::AForm(const std::string name, const int gradeSign, const int gradeExe) : name(name), sign(false), gradeSign(gradeSign), gradeExe(gradeExe) 
{
    if (gradeSign > 150 || gradeExe > 150)
        throw AForm::GradeTooLowException();
    else if (gradeSign < 1 || gradeExe < 1)
        throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &copy) : name(copy.name), sign(copy.sign), gradeSign(copy.gradeSign), gradeExe(copy.gradeExe) {}

AForm &AForm::operator=(const AForm &op)
{
    (void)op;
    return (*this);
}

std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getSign() const
{
    return this->sign;
}

int AForm::getGradeSign() const
{
    return this->gradeSign;
}

int AForm::getGradeExe() const
{
    return this->gradeExe;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > this->getGradeSign())
        throw AForm::GradeTooLowException();
    if (this->getSign() == true)
        throw AForm::AlreadySignedException();
    else
        this->sign = true;
}

const char *AForm::GradeTooLowException::what(void) const throw() {
    return ("Grade is too low!");
};

const char *AForm::GradeTooHighException::what(void) const throw() {
    return ("Grade is too high!");
};

const char *AForm::AlreadySignedException::what(void) const throw() {
    return ("Form was already signed!");
};

const char *AForm::NotSignedException::what(void) const throw() {
    return ("Form was not signed yet!");
};

std::ostream &operator<<(std::ostream &o, const AForm &f) {
    o << f.getName() << ", bureaucrat grade " << f.getGradeSign() << ". Signed status: " << f.getSign() << std::endl;
    return (o);
}