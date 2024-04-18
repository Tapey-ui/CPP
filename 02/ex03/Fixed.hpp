/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:57:46 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/21 00:18:19 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int	value;
		const static int bits;

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

		bool operator>(Fixed val) const;
		bool operator<(Fixed val) const;
		bool operator>=(Fixed val) const;
		bool operator<=(Fixed val) const;
		bool operator==(Fixed val) const;
		bool operator!=(Fixed val) const;
		Fixed operator+(Fixed val) const;
		Fixed operator-(Fixed val) const;
		Fixed operator*(Fixed val) const;
		Fixed operator/(Fixed val) const;
		Fixed operator++(void);
		Fixed operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);
		static const Fixed &min(const Fixed &val1, const Fixed &val2);
		static const Fixed &max(const Fixed &val1, const Fixed &val2);
};

std::ostream &operator<<(std::ostream &str, Fixed const &n);

#endif