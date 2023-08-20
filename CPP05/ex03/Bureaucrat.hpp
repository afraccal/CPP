/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:19:22 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/30 08:52:24 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
    const std::string name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string &_name, int _grade);
    Bureaucrat(const Bureaucrat &src);
    ~Bureaucrat();
    
    Bureaucrat	&operator=(const Bureaucrat &other);
    
    const std::string &getName() const;
    int     getGrade() const;
    
    bool    signForm(AForm &form) const;
	bool	executeForm(const AForm &form) const;
       
    void increment(int num);
    void decrement(int num);
    
    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {
                return ("Grade too high");
            }
    };

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {
                return ("Grade too low");
            }
    };
};

std::ostream	&operator<<(std::ostream &ostr, const Bureaucrat &instance);

#endif