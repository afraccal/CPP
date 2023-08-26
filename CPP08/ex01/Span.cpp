/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:17:56 by afraccal          #+#    #+#             */
/*   Updated: 2023/08/26 16:09:38 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
    this->N = 0;
}

Span::Span(unsigned int N)
{
    this->N = N;
}

Span & Span::operator=(const Span &copy)
{
    if (this == &copy)
		return (*this);
    this->vec = copy.vec;
    this->N = copy.N;
    return (*this);
}

Span::Span(const Span &copy)
{
    *this = copy;
    return ;
}

Span::~Span()
{
    
}

void Span::addNumber(int val)
{
    if (this->vec.size() < (unsigned long) this->N)
        this->vec.push_back(val);
    else
        throw (Span::Overflow());
}

int Span::shortestSpan()
{
    int val;
    
    if (this->vec.size() <= 1)
        throw (Span::NotEnoughNumber());
    val = abs(this->vec[0] - this->vec[1]);
    for (unsigned int i = 0; i < vec.size() - 1; i++)
    {
        if(abs(this->vec[i] - this->vec[i + 1]) < val)
            val = abs(this->vec[i] - this->vec[i + 1]);
    }
    return (val);
}


int Span::longestSpan()
{
    int val;
    
    if (this->vec.size() < 2)
        throw (Span::NotEnoughNumber());
    val = abs(this->vec[0] - this->vec[1]);
    for (unsigned int i = 0; i < vec.size() - 1; i++)
    {
        if(abs(this->vec[i] - this->vec[i + 1]) >= val)
            val = abs(this->vec[i] - this->vec[i + 1]);
    }
    return (val);
}