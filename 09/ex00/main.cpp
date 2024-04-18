/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:04:47 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/11 18:15:06 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (0);
	}
	try
	{
		BitcoinExchange b = BitcoinExchange();
		b.readInput(av[1]);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}