/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:25:52 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/14 14:34:08 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->number = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    setRawBits(n << this->fractional);
}

Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called" << std::endl;
    setRawBits(roundf(n * ( 1 << this->fractional)));
}

Fixed::Fixed(const Fixed &f)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator = (const Fixed &rhs)
{
    std::cout << "Copy assignment operator called " << std::endl;
    this->number = rhs.getRawBits();
    return(*this);
}

int Fixed::getRawBits( void ) const
{
    return (this->number);
}

void Fixed::setRawBits( int const raw )
{
    this->number = raw;
}

float Fixed::toFloat(void) const
{
    return((float) this->getRawBits() / (1 << this->fractional));
}

int Fixed::toInt(void) const
{
    return(this->getRawBits() >> this->fractional);
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	//std::cout << std:: endl << "RAW: " << rhs.getRawBits() << std::endl;
	//std::cout << std:: endl << "TOINT: " << rhs.toInt() << std::endl;
	//std::cout << std:: endl << "TOFLOAT: " << rhs.toFloat() << std::endl;
	return (o);
}

bool Fixed::operator < (const Fixed &rhs)
{
    return(this->number < rhs.getRawBits());
}

bool Fixed::operator > (const Fixed &rhs)
{
    return(number > rhs.getRawBits());
}

bool Fixed::operator <= (const Fixed &rhs)
{
    return(this->number <= rhs.getRawBits());
}

bool Fixed::operator >= (const Fixed &rhs)
{
    return(this->number >= rhs.getRawBits());
}

bool Fixed::operator == (const Fixed &rhs)
{
    return(this->number == rhs.getRawBits());
}

bool Fixed::operator != (const Fixed &rhs)
{
    return(this->number != rhs.getRawBits());
}

Fixed Fixed::operator + (const Fixed &rhs)
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator - (const Fixed &rhs)
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed  Fixed::operator * (const Fixed &rhs)
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed  Fixed::operator / (const Fixed &rhs)
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed  Fixed::operator ++ (void)
{
    this->number++;
    return(*this);
}

Fixed  Fixed::operator -- (void)
{
    this->number--;
    return(*this);
}

Fixed  Fixed::operator ++ (int)
{
    Fixed tmp = *this;
	++*this;
	return tmp;
}

Fixed  Fixed::operator -- (int)
{
    Fixed tmp = *this;
	--*this;
	return tmp;
}

Fixed & Fixed::min(Fixed & a, Fixed & b )
{
    if (a.number > b.number)
        return (b);
    return (a);
}

const Fixed &Fixed::min(const Fixed & a, const Fixed & b )
{
    if (a.number > b.number)
        return (b);
    return (a);
}

Fixed & Fixed::max(Fixed & a, Fixed & b )
{
    if (b.number > a.number)
        return (b);
    return (a);
}

const Fixed &Fixed::max(const Fixed & a, const Fixed & b )
{
    if (b.number > a.number)
        return (b);
    return (a);
}
