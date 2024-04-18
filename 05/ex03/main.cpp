/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:11:34 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/13 22:03:58 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Intern		a;
	AForm		*form;
	Bureaucrat	b("b", 1);
	Bureaucrat	c("c", 50);

	try
	{
		Intern  someRandomIntern;
		AForm   *rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		form = a.makeForm("robotomy request", "a");
		delete form;
		form = a.makeForm("shrubbery creation", "c");
		delete form;
		form = a.makeForm("presidential pardon", "d");
		delete form;
		form = a.makeForm("random request", "e");
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		form = a.makeForm("shrubbery creation", "a");
		form->beSigned(b);
		b.executeForm(*form);
		delete form;
		form = a.makeForm("presidential pardon", "b");
		b.signForm(*form);
		b.executeForm(*form);
		delete form;
		form = a.makeForm("robotomy request", "c");
		b.signForm(*form);
		b.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error" << e.what() << '\n';
	}
	try
	{
		form = a.makeForm("robotomy request", "c");
		c.signForm(*form);
		c.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}