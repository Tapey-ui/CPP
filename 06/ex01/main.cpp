/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:00:38 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/15 13:52:15 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data d;

    d.str = "bla bla bla";
    d.c = 'e';
    d.d = 72.56;
    d.i = 69;

    uintptr_t u = Serializer::serialize(&d);
    Data *d2 = Serializer::deserialize(u);

    std::cout << "String (before): " << d.str << " " << u << " (after): " << d2->str << std::endl;
    std::cout << "Char (before): " << d.c << " " << u << " (after): " << d2->c << std::endl;
    std::cout << "Double (before): " << d.d << " (after): " << d2->d << std::endl;
    std::cout << "Int (before): " << d.i << " (after): " << d2->i << std::endl;

    return (0);
}