/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:25:49 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/08 15:09:57 by afraccal         ###   ########.fr       */
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
};
 
 std::ostream & operator<<( std::ostream & o, Fixed const & rhs);
#endif