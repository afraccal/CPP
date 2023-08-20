/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:26:37 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/16 16:03:28 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string _name;
        
    public:
        DiamondTrap ();
        DiamondTrap(std::string name);
        DiamondTrap(ClapTrap const &other);
        ~DiamondTrap ();
        DiamondTrap &operator = (DiamondTrap const &other);
        void attack(const std::string& target);
        void whoamI(void);
};
#endif