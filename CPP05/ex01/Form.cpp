/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:48:16 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/30 08:48:34 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name(""), _signed(false), grade_sign(150), grade_exec(1)
{
    std::cout << "Form default costructor called" << std::endl;
}

Form::Form(const std::string &_name, int _grade_sign, int _grade_exec):
	name(_name), _signed(false), grade_sign(_grade_sign),
	grade_exec(_grade_exec)
{
	if (this->grade_exec < 1
			|| this->grade_sign < 1)
		throw Form::GradeTooHighException();
	if (this->grade_exec > 150
			|| this->grade_sign > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form constructor created\n";
}

Form::Form(const Form &src) : name(src.getName()), _signed(issigned()), grade_sign(src.getGrade_sign()), grade_exec(src.getGrade_exec())
{
    std::cout << "Form copy costructor called" << std::endl;
    *this = src;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

Form	&Form::operator=(const Form &other)
{
    this->_signed = other._signed;
	std::cout << "Assignement Form" << std::endl;
	return *this;
}

const std::string &Form::getName() const
{
    return(this->name);
}

int Form::getGrade_sign() const
{
    return(this->grade_sign);
}

int Form::getGrade_exec() const
{
    return(this->grade_exec);
}

bool Form::issigned() const
{
    return(this->_signed);
}

void	Form::checkExecutability(const Bureaucrat &bureaucrat) const
{
	if (this->_signed == false
			|| bureaucrat.getGrade() > this->grade_exec)
		throw Form::CantExecuteForm();
}

bool Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->grade_sign)
    {
        this->_signed = false;
        return (false);
    }
    else
    {
        this->_signed = true;
        return (true);
    }
}

std::ostream &operator<<(std::ostream &ostr, const Form &other)
{
    ostr << other.getName() << ", grade to sign: " << other.getGrade_sign() << ", grade to execute: " << other.getGrade_exec() << std::endl;
	return (ostr);
	return ostr;
}