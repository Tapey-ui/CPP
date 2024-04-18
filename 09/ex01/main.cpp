/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:29:39 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/16 23:42:44 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: Incorrect input. Please enter input in between quotations" << std::endl;
		return 0;
	}
	RPN rpn;
	try
	{
		rpn.calculate(av[1]);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}