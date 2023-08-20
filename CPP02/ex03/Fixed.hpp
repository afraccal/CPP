/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:25:49 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/14 15:11:48 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include "iostream"
# include "cmath"

class Fixed
{
private:
    int number;
    static const int fractional = 8;

public:
    Fixed();
    Fixed(const Fixed &f);
    ~Fixed();
    Fixed &operator = (const Fixed &rhs);
    
    Fixed(const int n);
    Fixed(const float n);
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat( void ) const;
    int toInt( void ) const;

    bool operator < (const Fixed &rhs);
    bool operator > (const Fixed &rhs);
    bool operator <= (const Fixed &rhs);
    bool operator >= (const Fixed &rhs);
    bool operator == (const Fixed &rhs) const;
    bool operator != (const Fixed &rhs);

    Fixed operator + (const Fixed &rhs) const;
    Fixed operator - (const Fixed &rhs) const;
    Fixed operator * (const Fixed &rhs) const;
    Fixed operator / (const Fixed &rhs) const;

    Fixed operator++( void ); // Prefix (++F)
	Fixed operator--( void ); // Prefix (--F)
	Fixed operator++( int ); // Postfix (F++)
	Fixed operator--( int ); // Postfix (F--)

    static Fixed & min(Fixed & a, Fixed & b );
	static Fixed & max(Fixed & a, Fixed & b );
	static const Fixed &min(const Fixed & a, const Fixed & b );
	static const Fixed &max(const Fixed & a, const Fixed & b );
};
 
 std::ostream & operator<<( std::ostream & o, Fixed const & rhs);
#endif