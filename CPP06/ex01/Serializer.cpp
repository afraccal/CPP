/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:38:12 by afraccal          #+#    #+#             */
/*   Updated: 2023/08/20 15:58:18 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Serializer created" << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
    *this = other;
    std::cout << "Serializer copy created" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &other)
{
    (void)other;
    return (*this);
}

Serializer::~Serializer()
{
    std::cout << "Serializer Deconstructor called." << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}
