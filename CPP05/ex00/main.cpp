/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:51:31 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/26 15:43:09 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
	{
		Bureaucrat	b1 = Bureaucrat("b1", 1);
		std::cout << b1 << std::endl;
		b1.decrement(1);
		std::cout << b1 << std::endl;
		b1.increment(1);
		std::cout << b1 << std::endl;
		b1.increment(1);
		std::cout << b1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat		b2 = Bureaucrat("b2", 150);
		std::cout << b2 << std::endl;
		b2.increment(1);
		std::cout << b2 << std::endl;
		b2.decrement(1);
		std::cout << b2 << std::endl;
		b2.decrement(1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat		b3 = Bureaucrat("b3", 0);
		std::cout << b3 << std::endl;
		b3.decrement(1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat		b4 = Bureaucrat("b4", 151);
		std::cout << b4 << std::endl;
		b4.increment(1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}