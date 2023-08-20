/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:34:18 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/21 12:44:05 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "iostream"
# include "string"
# include "AMateria.hpp"

class Cure : public AMateria
{
    public:
    Cure();
    Cure(const Cure &src);
    ~Cure();
    Cure &operator =(const Cure &src);
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif