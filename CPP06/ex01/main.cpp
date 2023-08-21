/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:37:30 by afraccal          #+#    #+#             */
/*   Updated: 2023/08/21 09:50:42 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data		*ptr = new Data;
	Data		*d_ptr;
	uintptr_t	pointer;
	Serializer	s;

	ptr->string = "common string";
	pointer = s.serialize(ptr);
	d_ptr = s.deserialize(pointer);
	std::cout << "d_ptr->string = " << d_ptr->string << std::endl;
    return(0);
}