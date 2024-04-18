/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:14:28 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/22 21:14:51 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;

    if (ac != 2)
        return 1;
    harl.complain(av[1]);
    // harl.complain("DEBUG");
    // harl.complain("INFO");
    // harl.complain("ERROR");
    // harl.complain("WARNING");
    // harl.complain("");
    // harl.complain("ERROR");
    return (0);
}