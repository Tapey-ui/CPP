/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:54:57 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/15 11:23:53 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

typedef struct Data{
    std::string str;
    int i;
    char c;
    double d;
}              Data;


class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer &copy);
        Serializer &operator=(const Serializer &s);

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif