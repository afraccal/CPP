/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:17:36 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/14 15:13:06 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "iostream"
# include "cmath"
# include "Fixed.hpp"

class Point
{
    private:
        Fixed x;
        Fixed y;
        
    public:
        Point (void);
		Point(Fixed x, Fixed y);
		Point(const float x, const float y);	
        Point (const Point &source);
        ~Point();
        Point &operator = (const Point &source);
        
        Fixed const &getX(void) const;
		Fixed const &getY(void) const;
        bool operator==(const Point &p1) const;	
        
};

#endif