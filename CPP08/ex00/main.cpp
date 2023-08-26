/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:42:43 by afraccal          #+#    #+#             */
/*   Updated: 2023/08/26 13:52:50 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"
#include "stdlib.h"

int main()
{
    srand(time(NULL));
    int j = rand() % 20;
    std::vector<int> numbers (10, 0);
	for (int i = 0; i < 10; i++)
		numbers[i] = rand() % 20;
    for (int i = 0; i < 10; i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;
    int i = easyfind(numbers, j);
	std::cout << "numero da cercare: " << j << std::endl;
    if (!i)
        std::cout << "Numero presente nel container" << std::endl;
    else
        std::cout << "Numero non trovato" << std::endl;
}