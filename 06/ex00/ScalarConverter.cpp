/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:03:46 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/08 14:52:25 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    *this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &s)
{
    if (this != &s)
        *this = s;
    return *this;
}

const char* ScalarConverter::NonDisplayableException::what() const throw()
{
	return("Undisplayable character detected!\n");
}

const char* ScalarConverter::ExceedLimitException::what() const throw()
{
	return("Value has exceeded the int limit!\n");
}

const char* ScalarConverter::UnknownTypeException::what() const throw()
{
	return("Value type is unknown!\n");
}

bool ScalarConverter::checkPrintable(const std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] < 32 || str[i] > 126)
            return false;
    }
    return true;
}

int ScalarConverter::getType(const std::string par)
{
    int dec = 0;
    int ch = 0;
    int i = 0;
    if (par == "+inf" || par == "+inff" || par == "-inf" || par == "-inff" || par == "nan")
        return INFNAN;
    if (par[i] == '+' || par[i] == '-')
        i++;
    while (par[i] != '\0')
    {
        if (par[i] == '.')
            dec++;
        else if ((par[i] < '0' || par[i] > '9') && par[i] != '.')
            ch++;
        i++;
    }
    if (dec == 1 && ch == 0)
        return DOUBLE;
    else if (dec <= 1 && ch == 1 && par[par.length() - 1] == 'f')
        return FLOAT;
    else if (dec == 0 && ch == 0)
        return INT;
    else
        return CHAR;
}

void ScalarConverter::convert(const std::string par)
{
    char c;
    int i;
    float f;
    double d;

    try
    {
        if (checkPrintable(par) == false)
            throw NonDisplayableException();
        int type = getType(par);
        switch (type)
        {
            case CHAR:
            {
                c = par[0];
                i = static_cast<int>(c);
                f = static_cast<float>(c);
                d = static_cast<double>(c);
                break;
            }
            case INT:
            {
                long l = strtol(par.c_str(), NULL, 10);
                if (l > INT_MAX || l < INT_MIN)
                    throw ExceedLimitException();
                i = static_cast<int>(l);
                c = static_cast<char>(i);
                f = static_cast<float>(i);
                d = static_cast<double>(i);
                break;
            }
            case FLOAT:
            {
                f = strtof(par.c_str(), NULL);
                if (f == HUGE_VAL)
                    throw ExceedLimitException();
                c = static_cast<char>(f);
                i = static_cast<int>(f);
                d = static_cast<double>(f);
                break;
            }
            case DOUBLE:
            {
                d = strtod(par.c_str(), NULL);
                if (d == HUGE_VAL)
                    throw ExceedLimitException();
                c = static_cast<char>(d);
                i = static_cast<int>(d);
                f = static_cast<float>(d);
                break;
            }
            case INFNAN:
            {
                if (par == "+inf" || par == "+inff")
                {
                    std::cout << "char: impossible" << std::endl;
                    std::cout << "int: impossible" << std::endl;
                    std::cout << "float: +inff" << std::endl;
                    std::cout << "double: +inf" << std::endl;
                    return ;
                }
                else if (par == "-inf" || par == "-inff")
                {
                    std::cout << "char: impossible" << std::endl;
                    std::cout << "int: impossible" << std::endl;
                    std::cout << "float: -inff" << std::endl;
                    std::cout << "double: -inf" << std::endl;
                    return ;
                }
                else if (par == "nan")
                {
                    std::cout << "char: impossible" << std::endl;
                    std::cout << "int: impossible" << std::endl;
                    std::cout << "float: nanf" << std::endl;
                    std::cout << "double: nan" << std::endl;
                    return ;
                }
            }
            default:
                throw UnknownTypeException();
        }
        if (i > 32 && i < 126)
            std::cout << "char: " << c << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
}