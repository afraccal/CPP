/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:53:54 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/06 11:05:17 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
private:
    std::string type;

public:
    Weapon();
    Weapon(std::string str);
    ~Weapon();
    const std::string getType(void);
    std::string setType(std::string name);
};

#endif