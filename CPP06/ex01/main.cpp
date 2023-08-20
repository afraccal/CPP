/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:37:30 by afraccal          #+#    #+#             */
/*   Updated: 2023/08/20 15:55:07 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data		*ptr = new Data;
	Data		*new_ptr;
	uintptr_t	raw;
	Serializer	t;

	ptr->string = "test string data";
	raw = t.serialize(ptr);
	new_ptr = t.deserialize(raw);
	std::cout << "new_ptr->string = " << new_ptr->string << std::endl;
    return(0);
}