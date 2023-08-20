/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:46:07 by afraccal          #+#    #+#             */
/*   Updated: 2023/05/31 14:31:08 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Zombie_HPP
# define Zombie_HPP

# include "iostream"
# include "string"
# include "new"

class Zombie
{
    public:
        Zombie (std::string name);
        ~Zombie (void);
        void announce(void);
    
    private:
        std::string name;
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif