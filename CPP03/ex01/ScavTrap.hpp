/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:25:05 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/15 17:51:21 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap ();
    ScavTrap(std::string name);
    ScavTrap(ClapTrap const &other);
    ~ScavTrap ();
    ScavTrap &operator = (ScavTrap const &other);
    void attack(const std::string& target);
    void guardGate();
};

#endif
