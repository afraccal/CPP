/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:21:36 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/22 14:50:15 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    this->number_materia = 0;
    int i = -1;
    while(++i < 4)
        this->materia[i] = NULL;
    std::cout << "MateriaSource default constructor built" << std::endl; 
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
    std::cout << "MateriaSource copy constructor built" << std::endl; 
    *this = src;
}

MateriaSource::~MateriaSource()
{
    int i = -1;
    while(++i < 4)
        if (this->materia[i])
            delete this->materia[i];
    std::cout << "MateriaSource destroyed" << std::endl;
}

MateriaSource & MateriaSource::operator=(const MateriaSource &src)
{
    int i = -1;
    while(++i < 4)
        this->materia[i] = src.materia[i];
    std::cout << "Assignement MateriaSource operator built" << std::endl; 
    return(*this);
}

void MateriaSource::learnMateria(AMateria*m)
{
    if(this->number_materia >= 4)
        std::cout << "Impossible learn new materia" << std::endl;
    else
    {
        this->materia[this->number_materia] = m;
        number_materia++;
        std::cout << "New materia learned: " << m->getType() << std::endl;
    }
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
    int i = -1;
    while (++i < 4  && this->materia[i])
    {
        if(type == this->materia[i]->getType())
        {
            std::cout << "Materia has been created" << std::endl;
            return(this->materia[i]->clone());
        }
    }
    std::cout << "Materia couldn't be created" << std::endl;
    return (this->materia[i] = NULL);
}