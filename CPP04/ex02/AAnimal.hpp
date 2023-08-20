/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:12:05 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/20 13:33:32 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>
# include <string>

class AAnimal
{
protected:
    std::string type;
public:
    virtual ~AAnimal();
    AAnimal & operator = (const AAnimal &src);
    virtual void makeSound() const;
    virtual const std::string getType() const;
};

#endif