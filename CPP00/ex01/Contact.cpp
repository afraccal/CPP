/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:56:26 by afraccal          #+#    #+#             */
/*   Updated: 2023/05/30 14:45:31 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void )
{    
    std::cout << "Slot Contact created" << std::endl;
    return;
}

void    Contact::set_name(std::string str)
{
    name = str;
}

void    Contact::set_lastname(std::string str)
{
    lastname = str;
}

void    Contact::set_nickname(std::string str)
{
    nickname = str;
}

void   Contact::set_phonenumber(std::string str)
{
    phonenumber = str;
}

void   Contact::set_darkest_secret(std::string str)
{
    darkest_secret = str;
}

std::string    Contact::get_name(void)
{
    return (name);
}

std::string    Contact::get_lastname(void)
{
    return (lastname);
}

std::string    Contact::get_nickname(void)
{
    return (nickname);
}

std::string    Contact::get_phonenumber(void)
{
    return (phonenumber);
}

std::string    Contact::get_darkest_secret(void)
{
    return (darkest_secret);
}

void    Contact::print_info()
{
    std::cout <<"First name:          " << name << std::endl;
    std::cout <<"Last name:          " << lastname << std::endl;
    std::cout <<"Nickname:          " << nickname << std::endl;
    std::cout <<"Phone Number:          " << phonenumber << std::endl;
    std::cout <<"Darkest secret:          " << darkest_secret << std::endl;
}

Contact::~Contact( void )
{
    std::cout << "Slot Contact destroyed" << std::endl;
    return;
}