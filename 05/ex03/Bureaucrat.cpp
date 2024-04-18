/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 03:03:46 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/13 21:26:21 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Anon") { setGrade(150); }

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
    setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
    : name(copy.name), grade(copy.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &op)
{
    if (this != &op)
        this->grade = op.getGrade();
    return (*this);
}

std::string Bureaucrat::getName() const { return (this->name); }

int Bureaucrat::getGrade() const { return (this->grade); }

void Bureaucrat::setGrade(int grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade = grade;
}

void Bureaucrat::decrement() {
    int tmp = this->grade;
    if (tmp + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade += 1;
}

void Bureaucrat::increment() {
    int tmp = getGrade();
    if (tmp - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade -= 1;
}

void Bureaucrat::signForm(AForm &f)
{
    try {
        f.beSigned(*this);
        std::cout << this->getName() << " signed " << f.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executes " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " cannot execute " << form.getName() << " because of " << e.what() << '\n';
    }
    
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
    return ("Grade is too low!");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
    return ("Grade is too high!");
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b) {
    o << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
    return (o);
}