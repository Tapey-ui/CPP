/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:57:46 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/23 18:17:13 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	value;
		const static int bits = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float 	toFloat(void) const;
    	int 	toInt(void) const;
};

std::ostream &operator<<(std::ostream &str, Fixed const &n);

#endif