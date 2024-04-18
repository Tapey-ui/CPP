/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:37:52 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/17 18:15:00 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    readDb();
}

BitcoinExchange::~BitcoinExchange()
{    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bc)
{
    this->data = bc.data;
    return *this;
}

bool BitcoinExchange::checkDay(const int day, const int month, const int year)
{
    if (day < 1 || day > 31)
        return false;
    if (month == 2)
    {
        if (((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0)))
        {
            if (day > 29)
                return false;
        }
        else
        {
            if (day > 28)
                return false;
        }
    }
    else
    {
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
            return false;
    }
    return true;
}

bool BitcoinExchange::checkDate(const std::string date)
{
    std::stringstream d(date);
    std::string token;
    std::vector <std::string> dateSplit;
    int year, month, day;

    if (date.length() != 10)
        return false;
    while (getline(d, token, '-'))
        dateSplit.push_back(token);
    if (dateSplit.size() != 3)
        return false;
    std::stringstream(dateSplit[0]) >> year;
    if (year < 1000 || year > 9999)
        return false;
    std::stringstream(dateSplit[1]) >> month;
    if ((month < 1 || month > 12) || dateSplit[1].size() != 2)
        return false;
    std::stringstream(dateSplit[2]) >> day;
    if (checkDay(day, month, year) == false || dateSplit[2].size() != 2)
        return false;
    return true;
}

void BitcoinExchange::readDb()
{
    std::ifstream dbFile("./data.csv");
    std::string line;
    double val;
    
    if (!dbFile || getline(dbFile, line).eof())
        throw OpenFileFailureException();
    while (getline(dbFile, line))
    {
        std::stringstream ss(line);
        std::string token;
        std::vector <std::string> tmp;
        while (getline(ss, token, ','))
            tmp.push_back(token);
        if (tmp.size() != 2)
            throw FileFormatFailureException();
        if (checkDate(tmp[0]) == false)
            throw DateFormatErrorException();
        std::stringstream(tmp[1]) >> val;
        if (val < 0)
            throw ValueTooLowException();
        else if (val > MAX_INT)
            throw ValueTooHighException();
        this->data[tmp[0]] = val;  
    }
    dbFile.close();
}

bool BitcoinExchange::checkValue(const std::string val)
{
    float value;
    bool dec = false;
    std::string::const_iterator it = val.begin();
    
    if (val.length() == 0 || (val.length() == 1 && val[0] == '-'))
    {
        std::cout << "Error: not a valid value." << std::endl;
        return false;
    }
    if (val[0] == '-' && val.length() > 1)
        it++;
    while (it != val.end())
    {
        if (*it == '.')
        {
            if (dec == false)
                dec = true;
            else
            {
                std::cout << "Error: not a valid value." << std::endl;
                return false;
            }
        }
        else if (!std::isdigit(*it))
        {
            std::cout << "Error: not a valid value." << std::endl;
            return false;
        }
        ++it;
    }
    std::stringstream(val) >> value;
    if (val[0] == '-' && val.length() > 1)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    else if (val.length() > 10 || value > 1000)
    {
        std::cout << "Error: too large of a number." << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::readInput(const std::string path)
{
    std::ifstream inputFile(path);
    std::string line;
    float value;
    
    if (!inputFile || getline(inputFile, line).eof())
        throw OpenFileFailureException();
    // getline(inputFile, line);
    if (line.compare("date | value") != 0)
        throw FileFormatFailureException();
    while (getline(inputFile, line))
    {
        std::stringstream ss(line);
        std::string token;
        std::vector <std::string> tmp;
        while (getline(ss, token, ' '))
            tmp.push_back(token);
        std::vector<std::string>::iterator it;
        if (tmp.size() != 3)
        {
            std::cout << "Error: bad line format." << std::endl;
            continue;
        }
        if (checkDate(tmp[0]) == false)
        {
            std::cout << "Error: bad input => " << tmp[0] << std::endl;
            continue;
        }
        if (tmp[1] != "|")
        {
            std::cout << "Error: incorrect format: missing |" << std::endl;
            continue;
        }
        if (checkValue(tmp[2]) == false)
            continue;
        std::stringstream(tmp[2]) >> value;
        try
        {
            std::map<std::string, float>::const_iterator it;
            float res;

            it = this->data.find(tmp[0]);
            if (it != this->data.end())
                res = it->second * value;
            else
            {
                it = this->data.lower_bound(tmp[0]);
                if (it == this->data.begin())
                {
                    std::cout << "Error: Date not recorded in database." << std::endl;
                    continue;
                }
                --it;
                res = (it->second) * value;
            }
            if (value == static_cast<int>(value))
                std::cout << tmp[0] << " => " << static_cast<int>(value) << " = " << res << std::endl;
            else
                std::cout << tmp[0] << " => " << value << " = " << res << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: Value not found." << std::endl;
            continue;
        }
    }
}

const char *BitcoinExchange::OpenFileFailureException::what(void) const throw() {
    return ("Error: could not open file!");
};

const char *BitcoinExchange::FileFormatFailureException::what(void) const throw() {
    return ("Error: File format incorrect!");
};

const char *BitcoinExchange::DateFormatErrorException::what(void) const throw() {
    return ("Error: Date must be in the correct format (YYYY-MM-DD)!");
};

const char *BitcoinExchange::ValueTooLowException::what(void) const throw() {
    return ("Error: not a positive number (database).");
};

const char *BitcoinExchange::ValueTooHighException::what(void) const throw() {
    return ("Error: too large of a number (database).");
};