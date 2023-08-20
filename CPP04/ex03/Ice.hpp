/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:36:35 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/21 12:44:13 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "iostream"
# include "string"
# include "AMateria.hpp"

class Ice: public AMateria
{
    public:
    Ice();
    Ice(const Ice &src);
    ~Ice();
    Ice &operator =(const Ice &src);
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif