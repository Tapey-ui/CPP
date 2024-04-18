/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:45:36 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/14 16:46:54 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    try {
        Bureaucrat a("OHHH", 17);
        std::cout << a;
        a.decrement();
        std::cout << a;
        a.increment();
        std::cout << a;
    }
    catch(std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        Bureaucrat b("You", 150);
        std::cout << b;
        b.decrement();
        std::cout << b;
        b.increment();
        std::cout << b;
    }
    catch(std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        Bureaucrat c("Me", -1);
        std::cout << c;
    }
    catch(std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        Bureaucrat d("Test", 1);
        std::cout << d;
        d.decrement();
        std::cout << d;
        d.increment();
        std::cout << d;
        d.increment();
        std::cout << d;
    }
    catch(std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        Bureaucrat e = Bureaucrat();
        std::cout << e;
        e.increment();
        std::cout << e;
        e.decrement();
        std::cout << e;
        e.decrement();
        std::cout << e;
    }
    catch(std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
