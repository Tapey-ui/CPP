/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 23:29:24 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/11 21:40:18 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#define MAX_INT 2147483647.0

class BitcoinExchange
{
    private:
        std::map<std::string, float> data;
        bool checkDay(const int day, const int month, const int year);
        bool checkDate(const std::string date);
        bool checkValue(const std::string val);
        void readDb();

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &bc);
        void readInput(const std::string path);

        class OpenFileFailureException : public std::exception
        {
            public:
                const char *what( void ) const throw();
        };

        class FileFormatFailureException : public std::exception
        {
            public:
                const char *what( void ) const throw();
        };

        class DateFormatErrorException : public std::exception
        {
            public:
                const char *what( void ) const throw();
        };

        class ValueTooLowException : public std::exception
        {
            public:
                const char *what( void ) const throw();
        };

        class ValueTooHighException : public std::exception
        {
            public:
                const char *what( void ) const throw();
        };
};

#endif