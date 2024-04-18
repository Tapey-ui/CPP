/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:41:48 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/08 14:51:40 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstring>
#include <cmath>
#include <limits.h>
#include <iomanip>

#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define INFNAN 4

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &s);
        static bool checkPrintable(const std::string str);

    public:
        static int getType(const std::string str);
        static void convert(const std::string par);
        class NonDisplayableException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
        class ExceedLimitException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
        class UnknownTypeException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif