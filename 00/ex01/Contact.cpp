/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:08:10 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/10 19:13:48 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::get_firstname(void) const
{
    return (this->firstname);
}

std::string Contact::get_lastname(void) const
{
    return (this->lastname);
}

std::string Contact::get_nickname(void) const
{
    return (this->nickname);
}

std::string Contact::get_phoneno(void) const
{
    return (this->phoneno);
}

std::string Contact::get_darksecret(void) const
{
    return (this->darksecret);
}

void Contact::set_firstname(std::string firstname)
{
    this->firstname = firstname;
}

void Contact::set_lastname(std::string lastname)
{
    this->lastname = lastname;
}

void Contact::set_nickname(std::string nickname)
{
    this->nickname = nickname;
}

void Contact::set_phoneno(std::string phoneno)
{
    this->phoneno = phoneno;
}

void Contact::set_darksecret(std::string darksecret)
{
    this->darksecret = darksecret;
}