/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:14:11 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/22 15:14:26 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int PhoneBook::getSize() const
{
	return (this->size);
}

int	strisspace(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (std::isspace(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

std::string cutLetters(const std::string str)
{
	std::string s;

	if (str.length() > 10)
		s = str.substr(0, 9) + ".";
	else
		s = str;
	return (s);
}

int PhoneBook::addContact()
{
	int	i;
	std::string input;
	std::string test;
    
	if (size == 8)
	{
		std::cout << "Phonebook is full! Remove oldest contact for new ones? (Y/N)" << std::endl;
        std::getline(std::cin, test);
        if (test.compare("Y") == 0 || test.compare("y") == 0)
        {
            for (int i = 1; i < size; i++)
                contacts[i - 1] = contacts[i];
            size--;
            std::cout << "Oldest contact deleted!" << std::endl;
        }
        else if (test.compare("N") == 0 || test.compare("n") == 0)
		    return (1);
        else
		{
            std::cout << "Invalid input!" << std::endl;
			return (1);
		}
	}
	i = size++;
	std::cout << std::endl;
	std::cout << "1. First Name : " << std::endl;
	std::getline(std::cin, input);
	if (input.empty() || strisspace(input) == 0)
	{
		size--;
		return (-1);
	}
	contacts[i].set_firstname(input);
	std::cout << "2. Last Name : " << std::endl;
	std::getline(std::cin, input);
	if (input.empty() || strisspace(input) == 0)
	{
		size--;
		return (-1);
	}
	contacts[i].set_lastname(input);
	std::cout << "3. Nickname : " << std::endl;
	std::getline(std::cin, input);
	if (input.empty() || strisspace(input) == 0)
	{
		size--;
		return (-1);
	}
	contacts[i].set_nickname(input);
	std::cout << "4. Phone Number : " << std::endl;
	std::getline(std::cin, input);
	if (input.empty() || strisspace(input) == 0)
	{
		size--;
		return (-1);
	}
	contacts[i].set_phoneno(input);
	std::cout << "5. Darkest Secret : " << std::endl;
	std::getline(std::cin, input);
	if (input.empty() || strisspace(input) == 0)
	{
		size--;
		return (-1);
	}
	contacts[i].set_darksecret(input);
	return (1);
}

int PhoneBook::printOne(int i) const
{
	if (getSize() == 0)
	{
		std::cout << "The PhoneBook is empty!" << std::endl;
		return (-1);
	}
	if (std::cin.eof())
		exit(1);
	if (std::cin.fail() || i <= 0 || i > 8)
	{
		std::cout << "Invalid input!" << std::endl;
		return (-1);
	}
	std::cout << std::endl;
	std::cout << "Contact Info: " << std::endl;
	std::cout << "First Name: " << this->contacts[i
		- 1].get_firstname() << std::endl;
	std::cout << "Last Name: " << this->contacts[i
		- 1].get_lastname() << std::endl;
	std::cout << "Nickname: " << this->contacts[i
		- 1].get_nickname() << std::endl;
	std::cout << "Number: " << this->contacts[i
		- 1].get_phoneno() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[i
		- 1].get_darksecret() << std::endl;
	std::cout << std::endl;
	return (1);
}

void PhoneBook::printAllContact() const
{
	int i;

	i = 1;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	while (i <= this->size)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		std::cout << std::setw(10) << cutLetters(contacts[i
			- 1].get_firstname()) << "|";
		std::cout << std::setw(10) << cutLetters(contacts[i
			- 1].get_lastname()) << "|";
		std::cout << std::setw(10) << cutLetters(contacts[i
			- 1].get_nickname()) << "|" << std::endl;
		std::cout << "+-------------------------------------------+" << std::endl;
		i++;
	}
}