/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:20:47 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/26 15:31:22 by afraccal         ###   ########.fr       */
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
