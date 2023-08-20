/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:25:49 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/08 15:40:35 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include "iostream"

// CANONIC FORM
// Class containing at least:
// 1) Constructor default
// 2) Copy constructor
// 3) '=' Operator overload
// 4) Destructor (virtual!)
/*Copy assignment vs Copy constructor

The purpose of the copy constructor and the copy assignment operator are almost equivalent -- both copy one object to another. However, the copy constructor initializes new objects, whereas the assignment operator replaces the contents of existing objects.

The difference between the copy constructor and the copy assignment operator causes a lot of confusion for new programmers, but it’s really not all that difficult. Summarizing:

If a new object has to be created before the copying can occur, the copy constructor is used (note: this includes passing or returning objects by value).
If a new object does not have to be created before the copying can occur, the assignment operator is used.
Overloading the assignment operator

Overloading the copy assignment operator (operator=) is fairly straightforward, with one specific caveat that we’ll get to. The copy assignment operator must be overloaded as a member function.*/

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
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};
 
#endif