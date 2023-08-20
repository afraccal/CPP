/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:30:13 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/20 12:12:44 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal *ani[6];
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    const Cat* Lucifero = new Cat();
    const Dog* Sansone = new Dog();
    Brain *brains;
    int i = 0;

    while (i < 3)
    {
        ani[i] = new Dog();
        i++;
    }
    while (i < 6)
    {
        ani[i] = new Cat();
        i++;
    }
    i = 0;
    while (i < 6)
    {
        std::cout << "ani[" << i << "] is type " << ani[i]->getType() << std::endl;
        i++;
    }
    i = 0;
    while (i < 6)
    {
        delete ani[i];
        i++;
    }

    brains = Lucifero->getBrain();
    brains->ideas[0] = "I am cinderella's cat";
    brains->ideas[1] = "Mamma mia";
    
    brains = Sansone->getBrain();
    brains->ideas[0] = "I am a good boy";    

    std::cout << Lucifero->getBrain()->ideas[0] << std::endl;
    std::cout << Lucifero->getBrain()->ideas[1] << std::endl;
    std::cout << Sansone->getBrain()->ideas[0] << std::endl;
    delete Lucifero;
    delete Sansone;
    delete dog;//should not create a leak
    delete cat;
    return(0);
}