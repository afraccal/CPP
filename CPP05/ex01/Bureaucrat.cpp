/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:20:47 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/29 10:28:59 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("")
{
    this->grade = 150;
    std::cout << "Bureaucrat default costructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &_name, int _grade) : name(_name)
{
    if(_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if(_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = _grade;
    std::cout << "Bureaucrat costructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
    std::cout << "Bureaucrat copy costructor called" << std::endl;
    *this = src;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	this->grade = other.grade;
	std::cout << "Assignement Bureaucrat" << std::endl;
	return *this;
}

const std::string &Bureaucrat::getName() const
{
    return(this->name);
}

int Bureaucrat::getGrade() const
{
    return(this->grade);
}

void Bureaucrat::increment(int num)
{
    std::cout << "Increment " << getGrade() << " of " << num << std::endl;
    this->grade -= num;
    if(this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrement(int num)
{
    std::cout << "Decrement " << getGrade() << " of " << num << std::endl;
    this->grade += num;
    if(this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

std::ostream &	operator<<(std::ostream & ostr, Bureaucrat const & instance)
{
	ostr << instance.getName() << ", Bureaucrat grade " << instance.getGrade();
	return ostr;
}

bool    Bureaucrat::signForm(Form &form) const
{
    if(form.beSigned(*this))
    {
        std::cout << this->name << " signs form " << form.getName() << std::endl;
		return true;
	}
	else
	{
		std::cout << this->name << " cannot sign form " << form.getName()
			<< " because their grade is not high enough\n";
		return false;
	}
}

bool	Bureaucrat::executeForm(const Form &form) const
{
	try
	{
		form.checkExecutability(*this);
		std::cout << this->name << " executes form " << form.getName() << std::endl;
		return true;
	}
	catch (Form::CantExecuteForm &e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}
}