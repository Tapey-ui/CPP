/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:09:00 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/13 16:46:36 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
    private:
        const std::string name;
        bool sign;
        const int gradeSign;
        const int gradeExe;
    
    public:
        Form();
        ~Form();
        Form(const std::string name, const int gradeSign, const int gradeExe);
        Form(const Form &copy);
        Form &operator=(const Form &op);
        std::string getName() const;
        bool getSign() const;
        int getGradeSign() const;
        int getGradeExe() const;
        void beSigned(const Bureaucrat &b);
        void signForm(const Bureaucrat &b);
        class GradeTooLowException: public std::exception {
            public:
			    virtual const char*	what() const throw();
		};
		class GradeTooHighException: public std::exception {
            public:
			    virtual const char*	what() const throw();
		};
		class AlreadySignedException: public std::exception {
            public:
			    virtual const char*	what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, const Form &f);

#endif