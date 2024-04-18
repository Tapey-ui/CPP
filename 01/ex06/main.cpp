/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:14:28 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/22 21:33:30 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int harl_translate(char *argv)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
        if (levels[i] == argv)
            return (i);
    return (-1);
}


int main(int argc, char **argv)
{
    Harl harl;

    if (argc != 2)
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    else
    {
        switch (harl_translate(argv[1]))
        {
        case 0:
            harl.complain("DEBUG");
        case 1:
            harl.complain("INFO");
        case 2:
            harl.complain("WARNING");
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        }
    }
    return (0);
}