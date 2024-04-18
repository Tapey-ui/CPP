/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:41:14 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/22 17:15:01 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	replace(char *str1, char *str2, std::ifstream *input, std::ofstream *output)
{
	std::string line;
	std::string replaceLine;
	std::string s1 = std::string(str1);
	std::string s2 = std::string(str2);

	if (s1.length() == 0)
	{
		std::cout << "Please enter a value to check." << std::endl;
		return (1);
	}
	while (std::getline(*input, line))
	{
		size_t i = 0;
		replaceLine.clear();
		size_t pos = line.find(s1);
		if (pos != std::string::npos)
		{
			while (pos != std::string::npos)
			{
				replaceLine.append(line, i, pos - i);
				replaceLine += s2;
				i = pos + (s1.length());
				pos = line.find(s1, i);
				if (pos == std::string::npos)
					replaceLine.append(line, i, line.length());
			}
		}
		else
			replaceLine = line;
		if (!(*input).eof())
			*output << replaceLine << "\n";
		else
			*output << replaceLine;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 4)
    {
        std::cout << "Please enter as follow: <file> <word1> <word2>." << std::endl;
        return (1);
    }
	if (strlen(av[2]) == 0)
	{
		std::cout << "Please enter a value to replace!" << std::endl;
		return (1);
	}
	std::string filename = av[1];
	std::string ofname;
	ofname = ofname + av[1] + ".replace";
	std::ifstream input(filename);
	std::ofstream output(ofname);
	if (!input.is_open() || !output.is_open())
	{
		std::cout << "Error reading file." << std::endl;
		return (1);
	}
	int i = replace(av[2], av[3], &input, &output);
	input.close();
	output.close();
	return (i);
}