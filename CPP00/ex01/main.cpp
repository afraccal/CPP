/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:41:17 by afraccal          #+#    #+#             */
/*   Updated: 2023/05/30 14:44:35 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int add(PhoneBook *phonebook)
{
	std::string input;

	std::cout << "Enter all the fields\n";
	std::cout << "First name: ";
	std::getline(std::cin, input);
	if (input.length() == 0)
		return (1);
	phonebook->phonebook[phonebook->contants].set_name(input);
	std::cout << "Last name: ";
	std::getline(std::cin, input);
	if (input.length() == 0)
		return (1);
	phonebook->phonebook[phonebook->contants].set_lastname(input);
	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	if (input.length() == 0)
		return (1);
	phonebook->phonebook[phonebook->contants].set_nickname(input);
	std::cout << "Phone Number: ";
	std::getline(std::cin, input);
	if (input.length() == 0)
		return (1);
	phonebook->phonebook[phonebook->contants].set_phonenumber(input);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, input);
	if (input.length() == 0)
		return (1);
	phonebook->phonebook[phonebook->contants].set_darkest_secret(input);
	phonebook->contants++;
	if (phonebook->max_contants < phonebook->contants)
		phonebook->max_contants = phonebook->contants;
	return (0);
}

std::string	trunc(std::string str)
{
	if (str.length() <= 10)
		return str;
	return (str.substr(0,9) + ".");
}

void	search(PhoneBook *phonebook)
{
	std::string	input;
	int	i;

	i = 0;
	while (i < phonebook->max_contants)
	{
		std::cout << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10) << trunc(phonebook->phonebook[i].get_name());
		std::cout << "|" << std::setw(10) << trunc(phonebook->phonebook[i].get_lastname());
		std::cout << "|" << std::setw(10) << trunc(phonebook->phonebook[i].get_nickname());
		std::cout << "|" << std::setw(10) << trunc(phonebook->phonebook[i].get_phonenumber()) << std::endl;
		i++;
	}
	std::cout << "Select contact by index: ";
	std::getline(std::cin, input);
	if (input.length() == 1 && input[0] > '0' && input[0] < '9')
		phonebook->phonebook[input[0] - '0' - 1].print_info();
	else
		std::cout << "Wrong index" << std::endl;
}

int main()
{
    PhoneBook phonebook;
    std::string cmd;
    int flag;

    phonebook.contants = 0;
    phonebook.max_contants = 0;
    flag = 1;
    while (flag)
    {
        std::cout << "Insert command>> ";
        std::getline(std::cin, cmd);
        if(cmd == "EXIT")
            flag = 0;
        else if(cmd == "ADD")
        {
			if (phonebook.contants == 8)
				phonebook.contants = 0;
            if (add(&phonebook))
			{
				std::cout << "Field empty" << std::endl;
				phonebook.phonebook[phonebook.contants].set_name("");
				phonebook.phonebook[phonebook.contants].set_lastname("");
				phonebook.phonebook[phonebook.contants].set_nickname("");
				phonebook.phonebook[phonebook.contants].set_phonenumber("");	
			}
        }
        else if(cmd == "SEARCH")
        {
            if (!phonebook.contants)
				std::cout << "phonebook empty, use ADD first" << std::endl;
			else
				search(&phonebook);
        }
        else
        {
            std::cout << "Command " << cmd << " not valid, use ADD or SEARCH or EXIT" << std::endl;
        }
    }
    return 0;
}