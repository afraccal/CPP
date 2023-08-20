/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:37:05 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/30 09:01:00 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Standard ShrubberyCreationForm\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm("ShrubberyCreationForm", 145, 137), _target("")
{
	std::cout << "Default ShrubberyCreationForm\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src):
	AForm("ShrubberyCreationForm", 145, 137), _target(src.getTarget())
{
	std::cout << "Copy ShrubberyCreationForm\n";
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Destructor ShrubberyCreationForm\n";
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	other.getTarget();
	std::cout << "Assignement ShrubberyCreationForm\n";
	return *this;
}

const std::string	&ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream	f;
	std::string		file_name = this->_target + "_shrubbery";

	this->checkExecutability(executor);
	f.open(file_name.c_str(), std::ios::out);


	f << "    oxoxoo    ooxoo" << std::endl;
	f << "  ooxoxo oo  oxoxooo" << std::endl;
	f << " oooo xxoxoo ooo ooox" << std::endl;
	f << " oxo o oxoxo  xoxxoxo" << std::endl;
	f << "  oxo xooxoooo o ooo" << std::endl;
	f << "    ooo oo   /o/o" << std::endl;
	f << "         |  / /" << std::endl;
	f << "         |   /" << std::endl;
	f << "         |  |" << std::endl;
	f << "         | D|" << std::endl;
	f << "         |  |" << std::endl;
	f << "         |  |" << std::endl;
	f << "  ______/___|____" << std::endl;
	f.close();
	std::cout << "A tree grown: " << this->_target << "_shrubbery\n";
}