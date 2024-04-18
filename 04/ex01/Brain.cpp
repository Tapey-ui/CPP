/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 01:45:00 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/27 15:46:28 by nwai-kea        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain is created!" << std::endl;
}

Brain &Brain::operator=(const Brain &b)
{
	for (int i = 0; i < 100; i++)
	{
		// if (b.getIdeas(i).empty())
			// this->setIdeas(b.getIdeas(i), i);
		this->ideas[i] = b.ideas[i];
	}
	return (*this);
}

Brain::Brain(const Brain &copy)
{
	*this = copy;
	std::cout << "Brain has been copied" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Can't think. Brain empty." << std::endl;
}

std::string Brain::getIdeas(int n) const
{
	return (this->ideas[n]);
}

void Brain::setIdeas(std::string idea, int n)
{
	if (n < 0 || n > 100)
		return ;
	this->ideas[n] = idea;
}