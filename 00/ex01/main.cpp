/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 01:43:01 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/22 15:18:34 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
    std::string cmd;
    PhoneBook p;
    int index;

    while (1)
    {
        std::cout << "Please enter a command : " << std::endl;
        std::cout << "ADD[A]: Add Contact" << std::endl;
        std::cout << "SEARCH[S]: Search Contact" << std::endl;
        std::cout << "Exit[E]: Exit" << std::endl;

        std::getline(std::cin, cmd);
        if (std::cin.eof())
            exit(1);
        std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::toupper);
        if (cmd.compare("ADD") == 0 || cmd.compare("A") == 0 || cmd.compare("a") == 0)
        {
            if (p.addContact() == -1)
            {
                std::cout << "Value cannot be empty!" << std::endl;
                std::cin.clear();
                continue ;
            }
        }
        else if (cmd.compare("SEARCH") == 0 || cmd.compare("S") == 0 || cmd.compare("s") == 0)
		{
			p.printAllContact();
			std::cout << "Insert index: ";
			std::cin >> index;
			if (std::cin.fail() || index <= 0 || index > p.getSize())
			{
				std::cout << "Invalid Index!" << std::endl;
				std::cin.clear();
				std::getline(std::cin, cmd);
				continue ;
			}
			p.printOne(index);
			std::cin.clear();
			std::getline(std::cin, cmd);
			continue ;
		}
        else if (cmd.compare("EXIT") == 0 || cmd.compare("E") == 0)
            break ;
        else
			std::cout << "Invalid Input!" << std::endl;
    }
    return (0);
}