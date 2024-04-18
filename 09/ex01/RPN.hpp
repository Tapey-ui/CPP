/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:19:46 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/12 03:49:18 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

class RPN
{
	private:
		std::stack<int> stack;
		
	public:
		RPN();
		~RPN();
		RPN(const RPN &copy);
		RPN &operator=(const RPN &rpn);
		
		void calculate(std::string av);
		
		class InvalidEquationException : public std::exception
        {
            public:
                const char *what( void ) const throw();
        };

		class ValueTooLargeException : public std::exception
        {
            public:
                const char *what( void ) const throw();
        };
};

#endif