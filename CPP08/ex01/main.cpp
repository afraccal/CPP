/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:18:03 by afraccal          #+#    #+#             */
/*   Updated: 2023/08/26 16:10:14 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    Span sp = Span(3);

    try
    {
        sp.addNumber(6);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    int	n = 10;
	int	array[n];
	Span	span(n);

	std::cout << "array:";
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % n;
		std::cout << " " <<array[i];
	}
	std::cout << std::endl;

	span.addNumbers(array, array + n);
	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;
    return (0);
}