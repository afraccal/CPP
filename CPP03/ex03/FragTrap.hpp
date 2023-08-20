/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:40:53 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/16 16:57:21 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
    FragTrap ();
    FragTrap(std::string name);
    FragTrap(ClapTrap const &other);
    ~FragTrap ();
    FragTrap &operator = (FragTrap const &other);
    void attack(const std::string& target);
    void highFivesGuys(void);
};
#endif