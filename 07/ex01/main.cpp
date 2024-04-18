/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 01:32:23 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/15 20:48:00 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// void ft_tolower(char &arr)
// {
// 	arr = tolower(arr);
// }

// int main(void)
// {
//     char a[] = {'A', 'B', 'C', 'X', 'Y', 'Z'};

// 	::iter(a, 3, ft_tolower);
// 	for (int i = 0; i < (int)sizeof(a); i++)
// 		std::cout << a[i] << std::endl;
// }

class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
	
template< typename T >
void print(T const & x) { std::cout << x << std::endl; return; }

int main() {
	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
	Awesome tab2[5];
	iter(tab, 5, print);
	iter(tab2, 5, print);
	return 0;
}
