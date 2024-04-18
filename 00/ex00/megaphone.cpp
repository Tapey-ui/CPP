/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:34:32 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/10 18:16:48 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdio.h>

char *uppercase(char *av)
{
    for (int i = 0; av[i]; i++)
        av[i] = toupper(av[i]);
    return (av);
}

int main(int ac, char **av)
{
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < ac; i++)
        {
            std::cout << uppercase(av[i]);
            if (av[i + 1])
                std::cout << " "; 
        }
        std::cout << std::endl;
    }
    return (0);
}