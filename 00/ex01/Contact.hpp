/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:01:13 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/10/10 19:13:34 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <string>

class Contact
{
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phoneno;
        std::string darksecret;

    public:
        std::string get_firstname(void) const;
	    std::string get_lastname(void) const;
	    std::string get_nickname(void) const;
	    std::string get_phoneno(void) const;
	    std::string get_darksecret(void) const;
	    void set_firstname(std::string firstname);
	    void set_lastname(std::string lastname);
	    void set_nickname(std::string nickname);
	    void set_phoneno(std::string phoneno);
	    void set_darksecret(std::string darksecret);
};

#endif