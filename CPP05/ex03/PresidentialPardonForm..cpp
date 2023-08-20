/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm..cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:36:57 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/29 11:50:32 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
	AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Standard PresidentialPardonForm\n";
}

PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("PresidentialPardonForm", 25, 5), _target("")
{
	std::cout << "Default PresidentialPardonForm\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src):
	AForm("PresidentialPardonForm", 25, 5), _target(src.getTarget())
{
	std::cout << "Copy PresidentialPardonForm\n";
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Destructor PresidentialPardonForm\n";
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const & other)
{
	other.getTarget();
	std::cout << "Assignement PresidentialPardonForm\n";
	return *this;
}

const std::string	&PresidentialPardonForm::getTarget(void) const
{
	return this->_target;
}

void	PresidentialPardonForm::execute( const Bureaucrat &executor) const
{
	this->checkExecutability(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
