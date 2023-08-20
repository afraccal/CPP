/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:48:34 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/30 08:45:17 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool _signed;
    const int grade_sign;
    const int grade_exec;

public:
    Form();
    Form(const std::string &_name, int _grade_sign, int _grade_exec);
    Form(const Form &src);
    ~Form();
    Form  &operator=(const Form &other);
    
    const std::string &getName() const;
    int getGrade_sign() const;
    int getGrade_exec() const;
    bool issigned() const;
    
    void checkExecutability(const Bureaucrat &bureaucrat) const;
    bool beSigned(const Bureaucrat &bureaucrat);
    
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

    class CantExecuteForm : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("The form can't be executed");
		}
	};
};

std::ostream &operator<<(std::ostream &ostr, const Form &other);

#endif