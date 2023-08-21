/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:11:49 by afraccal          #+#    #+#             */
/*   Updated: 2023/08/21 09:56:48 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int random = rand() % 3;

	std::cout << random << std::endl;
	if (random == 0)
		return (new A);
	if (random == 1)
		return (new B);
	if (random == 2)
		return (new C);
	return (0);
}

void	identify(Base *ptr)
{
	if (Base *temp = dynamic_cast<A *>(ptr))
	{
		std::cout << "A" << std::endl;
		(void)temp;
	}
	else if (Base *temp = dynamic_cast<B *>(ptr))
	{
		std::cout << "B" << std::endl;
		(void)temp;
	}
	else if (Base *temp = dynamic_cast<C *>(ptr))
	{
		std::cout << "C" << std::endl;
		(void)temp;
	}
}

void	identify(Base &ptr)
{
	try
	{
		Base &temp = dynamic_cast<A&>(ptr);
		(void)temp;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
		(void)e;
	}
	try
	{
		Base &temp = dynamic_cast<B&>(ptr);
		(void)temp;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e)
	{
		(void)e;
	}
	try
	{
		Base &temp = dynamic_cast<C&>(ptr);
		(void)temp;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e)
	{
		(void)e;
	}
}

int main()
{
	srand(time(NULL));
	Base *ptr;
	ptr = generate();
	identify(ptr);
	delete ptr;
	ptr = generate();
	identify(ptr);
	delete ptr;
	ptr = generate();
	identify(ptr);
	delete ptr;
	ptr = generate();
	identify(ptr);
	delete ptr;

	ptr = generate();
	identify(*ptr);
	delete ptr;
	ptr = generate();
	identify(*ptr);
	delete ptr;
	ptr = generate();
	identify(*ptr);
	delete ptr;
	ptr = generate();
	identify(*ptr);
	delete ptr;
}