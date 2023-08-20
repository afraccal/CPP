/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:51:31 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/30 09:33:49 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern stagista;
	AForm *form;
	Bureaucrat bur("Numero1", 1);
	Bureaucrat nuovo("NumeroX", 142);

	form = stagista.makeForm("error test", "Name 0");
	if (form)
		delete form;
	form = stagista.makeForm("presidential pardon", "Name 1");
	form->beSigned(bur);
	form->execute(bur);
	if (form)
		delete form;
	form = stagista.makeForm("shrubbery creation", "Name 2");
	if (form)
		delete form;
	form = stagista.makeForm("robotomy request", "Name 3");
	form->beSigned(bur);
	form->execute(bur);
	if (form)
		delete form;
}