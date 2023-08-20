/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:50:56 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/22 15:04:44 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure default built" << std::endl;
}

Cure::Cure(const Cure &src) : AMateria("cure")
{
    std::cout << "Copy Cure default built" << std::endl;
    *this = src;
}

Cure::~Cure()
{
    std::cout << "Cure destroyed" << std::endl;
}

Cure &Cure::operator=(const Cure &src)
{
    std::cout << "Assignement Cure built" << std::endl;
    this->_type = src._type;
    return (*this);
}

AMateria *Cure::clone() const
{
    return(new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}