/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 00:40:37 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/27 15:22:34 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
  protected:
	std::string ideas[100];

  public:
	Brain();
	Brain(const Brain &copy);
	Brain &operator=(const Brain &b);
	~Brain();
	std::string getIdeas(int n) const;
	void setIdeas(std::string idea, int n);
};

#endif