/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:34:43 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/06 10:31:31 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Zombie_HPP
# define Zombie_HPP

# include "iostream"

class Zombie
{
    public:
        Zombie (void);
        Zombie (std::string name);
        ~Zombie (void);
        void announce(void);
        void SetName(std::string name);
    
    private:
        std::string name;
};

Zombie* zombieHorde( int N, std::string name );
#endif