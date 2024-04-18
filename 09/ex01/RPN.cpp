/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:40:30 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/17 18:30:27 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){};

RPN::~RPN(){};

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &rpn)
{
	this->stack = rpn.stack;
	return *this;
}

void	RPN::calculate(std::string av)
{
	std::stringstream num(av);
    std::string token;
    std::vector <std::string> numSplit;
	std::string op = "+-*/";

	if (av.length() < 1)
		throw InvalidEquationException();
	while (getline(num, token, ' '))
		numSplit.push_back(token);
	if (numSplit.size() < 2 && op.find(numSplit[0]))
		throw InvalidEquationException();
	for (int i = 0; i < (int)numSplit.size(); i++)
	{
		if (numSplit[i].size() > 1)
			throw ValueTooLargeException();
		char c = numSplit[i][0];
		if (!isdigit(c) && !((c == '+' || c == '-' || c == '*' || c == '/')))
			throw InvalidEquationException();
		if (isdigit(c))
		{
			int n = static_cast<int>(c - '0');
			this->stack.push(n);
		}
		else
		{
			if (this->stack.empty())
				throw InvalidEquationException();
			int b = this->stack.top();
			this->stack.pop();
			if (this->stack.empty())
				throw InvalidEquationException();
			int a = this->stack.top();
			this->stack.pop();
			switch (c)
			{
				case '+':
					this->stack.push(a + b);
					break;
				case '-':
					this->stack.push(a - b);
					break;
				case '*':
					this->stack.push(a * b);
					break;
				case '/':
					if (b == 0)
						throw InvalidEquationException();
					this->stack.push(a / b);
					break;
			}
		}
	}
	if (this->stack.size() != 1)
		throw InvalidEquationException();
	std::cout << this->stack.top() << std::endl;
	this->stack.pop();
}

const char *RPN::InvalidEquationException::what(void) const throw() {
    return ("Error: equation invalid.");
};

const char *RPN::ValueTooLargeException::what(void) const throw() {
    return ("Error: too large of a number (must be between 0-9).");
};
