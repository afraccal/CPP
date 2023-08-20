/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:25:46 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/14 15:13:55 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point t_point[3];
	Point point;
	float x;
	float y;
	int index;

	index = 0;
	std::cout << "---Check if your point is inside the triangle---" << std::endl;
	std::cout << "---Define the triangle---" << std::endl;
	while (index < 3)
	{
		std::cout << "Coordinate " << index << ": " << std::endl;
		std::cout << index << "x: ";
		std::cin >> x;
		std::cout << index << "y: ";
		std::cin >> y;
		t_point[index] = Point(x, y);
		std::cout << "Point created!" << std::endl;
		index++;
	}
	std::cout << "Insert coordinates of your point to check:" << std::endl;
	std::cout << "x: ";
	std::cin >> x;
	std::cout << "y: ";
	std::cin >> y;
	point = Point(x, y);
	std::cout << "Point created!" << std::endl;		
	if (bsp(t_point[0], t_point[1], t_point[2], point) == true)	
		std::cout << "TRUE: Your point is inside the triangle!" << std::endl;
	else
		std::cout << "FALSE: Your point is not inside the triangle!" << std::endl;	
	return (0);
}

/*
Test da provare utilizzando lo stesso triangolo fornito da GeeksforGeeks:

Vertici: A(0,0) ; B(20,0) ; C(10,30)

Dove A(0,0) e' il vertice in basso a sinistra del triangolo ;
B(20,0) e' il punto in basso a destra del triangolo ;
C(10,30) e' il vertice in alto al centro del triangolo.

Test vettori positivi (TRUE): 

10,15
10,10
7,10
13,10
5,5
3,3

Test vettori negativi (FALSE):

10,30 \ 20,0 = Il punto si trova su un vertice
5,15 = Il punto si trova su un lato del triangolo
15,15 = Il punto si trova su un lato del triangolo
10,0 = Il punto si trova su un lato del triangolo
25,25 \ 30,15 = Questi 2 punti si trovano all'esterno del triangolo
*/