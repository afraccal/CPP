/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:12:05 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/19 12:34:40 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal &src);
    virtual ~Animal();
    Animal & operator = (const Animal &src);
    virtual void makeSound() const;
    virtual const std::string getType() const;
};

#endif