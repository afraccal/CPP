/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:06:06 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/30 09:20:04 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Empty Intern is born" << std::endl;
	this->target = "";
	this->name_form = "";
}

Intern::Intern(std::string name_form, std::string target)
{
    std::cout << "Intern is born" << std::endl;
	this->target = target;
	this->name_form = name_form;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern is copied" << std::endl;
	*this = src;
}

Intern::~Intern()
{
	std::cout << "Intern is gone\n";
}

Intern	&Intern::operator=(const Intern &src)
{
	std::cout << "Intern is assigned" << std::endl;
	this->name_form = src.name_form;
	this->target = src.target;
	return (*this);
}

AForm *Intern::makeForm(std::string type, std::string target)
{
    AForm *form;
    if (type == "robotomy request")
        form = new RobotomyRequestForm(target);
    else if (type == "shrubbery creation")
		form = new ShrubberyCreationForm(target);
	else if (type == "presidential pardon")
		form = new PresidentialPardonForm(target);
    else
    {
        std::cout << "Can't make this form" << std::endl;
        return(NULL);
    }
    return (form);
}