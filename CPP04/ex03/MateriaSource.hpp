/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:18:26 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/21 12:52:08 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "iostream"
# include "string"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    int number_materia;
    AMateria* materia[4];
    
public:
    MateriaSource();
	MateriaSource(const MateriaSource &src);
	~MateriaSource();
	MateriaSource	&operator=(const MateriaSource &src);
    virtual void learnMateria(AMateria* m);
    virtual AMateria* createMateria(std::string const & type);
};

#endif