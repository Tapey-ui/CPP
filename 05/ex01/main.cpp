/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:11:34 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/14 16:50:24 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat b("test", 2);
    try {
        Form f("ASD", 0, 150);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        Form g("QWE", 10, 151);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        Form h("UOI", 5, 8);
        b.signForm(h);
        std::cout << b;
        b.signForm(h);
        std::cout << b;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        Form j("ADSD", 1, 1);
        j.beSigned(b);
        std::cout << j;
        b.signForm(j);
        std::cout << b;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}