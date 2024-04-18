/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:27:30 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/17 17:45:56 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(int ac, char **av)
{
	std::string original;
	
	for (int i = 1; i < ac; i++)
	{
		if ((int)strlen(av[i]) < 1)
			continue;
		if (checkInput(av[i]) == false)
			throw InvalidValueException();
		if ((int)strlen(av[i]) > 10 || (((int)strlen(av[i]) == 10) && atol(av[i]) > MAX_INT))
			throw InvalidValueException();
		std::stringstream ss(av[i]);
		int value;
		ss >> value;
		if (value < 0 || value > MAX_INT)
			throw InvalidValueException();
		this->resultDeq.push_back(value);
		this->resultList.push_back(value);
	}
	
	std::cout << "Before: ";
	for (int i = 0; i < (int)this->resultDeq.size(); i++)
		std::cout << this->resultDeq[i] << " ";
	std::cout << std::endl;
	
	clock_t start = clock();
	sortDeq(0, (int)(this->resultDeq.size() - 1));
	clock_t end = clock();
	std::cout << "After: ";
	for (int i = 0; i < (int)this->resultDeq.size(); i++)
		std::cout << this->resultDeq[i] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << this->resultDeq.size() << " elements with std::deque : " << end - start << "ms" << std::endl;
	
	clock_t start2 = clock();
	sortList(0, (int)(this->resultList.size() - 1));
	clock_t end2 = clock();
	std::cout << "Time to process a range of " << this->resultList.size() << " elements with std::list : " << end2 - start2 << "ms" << std::endl;
}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &pm)
{
	this->input = pm.input;
	this->resultDeq = pm.resultDeq;
	this->resultList = pm.resultList;
	return *this;
}

bool PmergeMe::checkInput(char *av)
{
	for (int i = 0; i < (int)strlen(av); i++)
	{
		if (isdigit(av[i]) == 0)
			return false;
	}
	return true;
}

void PmergeMe::mergeDeq(int i, int j, int mid)
{
	int n1 = mid - i + 1;
	int n2 = j - mid;
	std::deque<int> l(n1);
	std::deque<int> r(n2);	

	for (int a = 0; a < n1; a++)
		l[a] = this->resultDeq[a + i];
	for (int b = 0; b < n2; b++)
		r[b] = this->resultDeq[mid + b + 1];
	int a = 0;
	int b = 0;
	int c = i;
	while (a < n1 && b < n2)
	{
		if (l[a] <= r[b])
		{
			this->resultDeq[c] = l[a];
			a++;
		}
		else
		{
			this->resultDeq[c] = r[b];
			b++;
		}
		c++;
	}
	
	while (a < n1)
	{
		this->resultDeq[c] = l[a];
		a++;
		c++;
	}

	while (b < n2)
	{
		this->resultDeq[c] = r[b];
		b++;
		c++;
	}
}

void PmergeMe::insertionSort(int l, int r)
{
	for (int i = l; i < r; i++)
	{
		int tmp = this->resultDeq[i + 1];
		int j = i + 1;
		while (j > l && this->resultDeq[j - 1] > tmp)
		{
			this->resultDeq[j] = this->resultDeq[j - 1];
			j--;
		}
		this->resultDeq[j] = tmp;
	}
}

void PmergeMe::sortDeq(int i, int j)
{	
	if (j - i > 6)
	{
		int mid = (i + j) / 2;
		sortDeq(i, mid);
		sortDeq(mid + 1, j);
		mergeDeq(i, j, mid);
	}
	else
		insertionSort(i, j);
}

int PmergeMe::getListValue(std::list<int> list, int i)
{
	std::list<int> tmp;
	
	tmp.assign(list.begin(), list.end());
	std::list<int>::iterator it = tmp.begin();
	while (i--)
		++it;
	return *it;
}

void PmergeMe::setListValue(int i, int value)
{
	std::list<int>::iterator it = this->resultList.begin();
	while (i--)
		++it;
	*it = value;
}

void PmergeMe::mergeList(int i, int j, int mid)
{
	int n1 = mid - i + 1;
	int n2 = j - mid;
	std::deque<int> l(n1);
	std::deque<int> r(n2);	

	for (int a = 0; a < n1; a++)
		l[a] = getListValue(this->resultList, a + i);
	for (int b = 0; b < n2; b++)
		r[b] = getListValue(this->resultList, mid + b + 1);
	int a = 0;
	int b = 0;
	int c = i;
	while (a < n1 && b < n2)
	{
		if (l[a] <= r[b])
		{
			setListValue(c, l[a]);
			a++;
		}
		else
		{
			setListValue(c, r[b]);
			b++;
		}
		c++;
	}
	
	while (a < n1)
	{
		setListValue(c, l[a]);
		a++;
		c++;
	}

	while (b < n2)
	{
		setListValue(c, r[b]);
		b++;
		c++;
	}
}

void PmergeMe::insertionSortList(int l, int r)
{
	for (int i = l; i < r; i++)
	{
		int tmp = getListValue(this->resultList, i + 1);
		int j = i + 1;
		while (j > l && getListValue(this->resultList, j - 1) > tmp)
		{
			setListValue(j, getListValue(this->resultList, j - 1));
			j--;
		}
		setListValue(j, tmp);
	}
}

void PmergeMe::sortList(int i, int j)
{	
	if (j - i > 6)
	{
		int mid = (i + j) / 2;
		sortList(i, mid);
		sortList(mid + 1, j);
		mergeList(i, j, mid);
	}
	else
		insertionSortList(i, j);
}

const char *PmergeMe::InvalidValueException::what(void) const throw() {
    return ("Error: invalid value.");
};