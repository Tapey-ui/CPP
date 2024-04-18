/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:43:16 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/02/06 21:43:16 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &op);
        std::string getName() const;
        int getGrade() const;
        // void setName(const std::string name);
        void setGrade(const int grade);
        void increment();
        void decrement();
        void signForm(Form &f);
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);

#endif