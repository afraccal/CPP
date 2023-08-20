/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:30:13 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/26 11:02:38 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

const WrongAnimal* wrong = new WrongAnimal();
const WrongAnimal* catwrong = new WrongCat();
std::cout << wrong->getType() << " " << std::endl;
std::cout << catwrong->getType() << " " << std::endl;
wrong->makeSound();
catwrong->makeSound();

delete meta;
delete j;
delete i;
delete wrong;
delete catwrong;

return(0);
}