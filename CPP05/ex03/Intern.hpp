/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:06:09 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/30 09:19:19 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"
#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(std::string name_form, std::string target);
        Intern(const Intern &src);
        ~Intern();
        Intern &operator =(const Intern &src);

        AForm *makeForm(std::string type, std::string target);

    private:
        std::string target;
        std::string name_form;
};

#endif
