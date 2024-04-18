/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 00:06:01 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/13 16:52:38 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Anon"), sign(false), gradeSign(150), gradeExe(150) {}

Form::~Form(){};

Form::Form(const std::string name, const int gradeSign, const int gradeExe) : name(name), sign(false), gradeSign(gradeSign), gradeExe(gradeExe) 
{
    if (gradeSign > 150 || gradeExe > 150)
        throw Form::GradeTooLowException();
    else if (gradeSign < 1 || gradeExe < 1)
        throw Form::GradeTooHighException();
}

Form::Form(const Form &copy) : name(copy.name), gradeSign(copy.gradeSign), gradeExe(copy.gradeExe) {}

Form &Form::operator=(const Form &op)
{
    (void)op;
    return (*this);
}

std::string Form::getName() const
{
    return this->name;
}

bool Form::getSign() const
{
    return this->sign;
}

int Form::getGradeSign() const
{
    return this->gradeSign;
}

int Form::getGradeExe() const
{
    return this->gradeExe;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > this->getGradeSign())
        throw Form::GradeTooLowException();
    if (this->getSign() == true)
        throw Form::AlreadySignedException();
    else
        this->sign = true;
}

const char *Form::GradeTooLowException::what(void) const throw() {
    return ("Grade is too low!");
};

const char *Form::GradeTooHighException::what(void) const throw() {
    return ("Grade is too high!");
};

const char *Form::AlreadySignedException::what(void) const throw() {
    return ("Form was already signed!");
};

std::ostream &operator<<(std::ostream &o, const Form &f) {
    o << f.getName() << ", bureaucrat grade " << f.getGradeSign() << ". Signed status: " << f.getSign() << std::endl;
    return (o);
}