/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:28:41 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/17 13:46:34 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <fstream>
#include <list>
#include <sstream>
#include <string>
#include <deque>

#define MAX_INT 2147483647

class PmergeMe
{
	private:
		std::deque<int> input;
		std::deque<int> resultDeq;
		std::list<int> resultList;
		PmergeMe();
		bool checkInput(char *av);
		int getListValue(std::list<int> list, int i);
		void setListValue(int i, int value);
		void verifyInput(std::string av);
		void sortDeq(int i, int j);
		void mergeDeq(int i, int j, int mid);
		void insertionSort(int l, int r);
		void sortList(int i, int j);
		void mergeList(int i, int j, int mid);
		void insertionSortList(int l, int r);
		
	public:
		PmergeMe(int ac, char **av);
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &rpn);

		class InvalidValueException : public std::exception
        {
            public:
                const char *what( void ) const throw();
        };
};

#endif