/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:26:18 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/12 20:24:35 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Error: Incorrect input. Please enter some numbers as input" << std::endl;
		return 0;
	}
	try
	{
		PmergeMe(ac, av);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}