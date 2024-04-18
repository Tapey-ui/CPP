/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:29:34 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/01/22 13:34:11 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <iostream>
# include <stdlib.h>

class PhoneBook
{
  private:
	Contact contacts[8];
	int size;

  public:
	int addContact();
	int getSize() const;
	int printOne(int i) const;
	void printAllContact() const;
};

#endif