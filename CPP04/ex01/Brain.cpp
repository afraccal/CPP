/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:21:24 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/20 11:50:39 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor was built" << std::endl;
}

Brain::Brain(const Brain &src)
{
    std::cout << "Copy of the brain was built" << std::endl;
    *this = src;
}

Brain::~Brain()
{
    std::cout << "Brain was destroyed" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
    std::cout << "Assignement Brain operator built" << std::endl;
    int i = -1;
    while (++i < 100)
        this->ideas[i] = src.ideas[i];
    return (*this);
}