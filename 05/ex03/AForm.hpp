/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:09:00 by nwai-kea          #+#    #+#             */
/*   Updated: 2024/04/06 16:38:15 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool sign;
        const int gradeSign;
        const int gradeExe;
    
    public:
        AForm();
        virtual ~AForm();
        AForm(const std::string name, const int gradeSign, const int gradeExe);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &op);
        std::string getName() const;
        bool getSign() const;
        int getGradeSign() const;
        int getGradeExe() const;
        void beSigned(const Bureaucrat &b);
        virtual void execute(const Bureaucrat &executor) const = 0;
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
        class NotSignedException: public std::exception {
            public:
			    virtual const char*	what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, const AForm &f);

#endif