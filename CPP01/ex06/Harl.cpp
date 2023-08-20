/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:15:03 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/07 17:37:36 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    std::cout << "Harl starts complaining" << std::endl;
}

Harl::~Harl()
{
    std::cout << "Harl stops complaining" << std::endl;
}

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do" << std::endl;
}
void Harl::info ( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
}
void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;   
}
void Harl::error ( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;       
}

void Harl::complain (std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    /*int i;
    void    (Harl::*ptr_complain[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    i = -1;*/
    int j;
    j = 0;
    while (j < 4)
    {
        if(level == levels[j])
            break;
        j++;
    }
    switch (j)
    {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            this->debug();
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            this->info();
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            this->warning();
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            this->error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    /*
    j = 0;
    while (++i < 4)
    {
        if(levels[i - j] == level)
        {
            (this->*(ptr_complain[i]))();
            j++;
        }
    }
    if (!j)
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
*/
}