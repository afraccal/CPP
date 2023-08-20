/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:27:09 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/14 15:08:09 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//Costruttore di default che imposta il vettore a 0.
Point::Point(void)
{
	this->x = 0;
	this->y = 0;
}

// Costruttore che prende in pasto delle coordinate per il vettore.
Point::Point(Fixed x, Fixed y)
{
	this->x = x;
	this->y = y;
}

// Costruttore che accetta float come coordinate per il vettore.
Point::Point(const float x, const float y)
{
	this->x = Fixed(x);
	this->y = Fixed(y);
}

Point::Point (const Point &source)
{
    *this = source;
}

Point &Point::operator=(const Point &source)
{
	this->x = source.x;
	this->y = source.y;
	return (*this);
}

Point::~Point()
{
    
}

Fixed const &Point::getX(void) const
{
	return this->x;
}

Fixed const &Point::getY(void) const
{
	return this->y;
}

bool Point::operator==(const Point &p1) const
{
	if (this->x == p1.x && this->y == p1.y)
		return (true);
	return (false);
}