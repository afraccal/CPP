/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:58:40 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/22 15:04:13 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main(void)
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	/*src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());*/

	ICharacter* me = new Character("Cloud Strife");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	/*tmp = src->createMateria("ice");*/
	me->equip(tmp);
	/*me->equip(tmp);*/
	tmp = src->createMateria("cure");
	me->equip(tmp);
	/*me->equip(tmp);
	me->equip(tmp);
	me->unequip(2);*/

	ICharacter* bob = new Character("Barret Wallace");

	/*tmp = src->createMateria("ice");
	bob->equip(tmp);*/
	me->use(0, *bob);
	me->use(1, *bob);
	/*bob->use(0, *me);*/

	delete bob;
	delete me;
	delete src;
	return (0);
}
