/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:55:16 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/06 11:36:13 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string str)
{
    this->type = str;
}

Weapon::~Weapon()
{
}

const std::string Weapon::getType(void)
{
    return (this->type);
}

std::string Weapon::setType(std::string type)
{
    this->type = type;
    return (type);
}