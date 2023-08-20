/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:33:14 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/14 14:48:27 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

// Roba presa da GeeksforGeeks: https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/

/*
BSP sta per "Binary Space Partitioning" ed è una tecnica utilizzata in computer grafica
per dividere uno spazio bidimensionale o tridimensionale in parti più piccole. In pratica,
si parte da una forma geometrica complessa (ad esempio un poligono o un poliedro) e si procede
a suddividerla in parti più semplici utilizzando piani di taglio. Questi piani permettono di 
creare delle divisioni nette nello spazio, in modo da semplificare il rendering e migliorare 
le prestazioni grafiche. La tecnica BSP viene utilizzata per la creazione di scene 3D in
videogiochi e applicazioni simili.

float area(Point const a, Point const b, Point const c):

Calcola l'area di un triangolo in base alle coordinate dei suoi tre vertici (a, b, c). 
Questo viene fatto utilizzando la formula dell'area del triangolo data dal prodotto del semiperimetro 
per il raggio della circonferenza inscritta nel triangolo.
Nel caso specifico, la funzione calcola l'area del triangolo utilizzando la formula di Erone, che richiede
solo la conoscenza delle lunghezze dei lati. Questa formula viene quindi riscritta in base alle coordinate dei tre vertici.
In particolare, il valore dell'area viene calcolato come il valore assoluto della somma di tre prodotti incrociati tra
le coordinate dei vertici del triangolo.
*/

float area(Point const a, Point const b, Point const c)
{
    return 0.5 * fabs(
		(a.getX().toFloat()*(b.getY().toFloat()-c.getY().toFloat()) 
		+ b.getX().toFloat()*(c.getY().toFloat()-a.getY().toFloat()) 
		+ c.getX().toFloat()*(a.getY().toFloat()-b.getY().toFloat())));
}

/*
bool bsp(Point const a, Point const b, Point const c, Point const point):

Il codice implementa il  BSP (Binary Space Partitioning) per verificare
se un punto si trova all'interno di un triangolo o meno. Il triangolo è definito 
dai suoi vertici a, b e c, mentre il punto da verificare è rappresentato dall'oggetto point.
Il calcolo viene effettuato utilizzando la funzione area, che calcola l'area del triangolo 
definito dai suoi tre vertici utilizzando la formula. La funzione bsp utilizza la funzione 
area per calcolare l'area del triangolo ABC (variabile ar) e le aree dei triangoli Point-BC, A-Point-C e AB-Point
(variabili ar_1, ar_2 e ar_3 rispettivamente) formati dal punto da verificare e due vertici del triangolo ABC.
Se il punto si trova su uno dei lati del triangolo o su uno dei suoi vertici, almeno una delle variabili
ar_1, ar_2 o ar_3 sarà uguale a 0, e quindi la funzione restituirà false.
Se invece il punto si trova all'interno del triangolo, la somma delle aree dei tre triangoli Point-BC, A-Point-C e AB-Point
sarà uguale all'area del triangolo ABC, con una tolleranza specificata dalla costante 0.1.
Se questa condizione è soddisfatta, la funzione restituisce true, altrimenti restituisce false.
*/

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float total;
	float ar = area(a, b, c); // calcolo dell'area del triangolo principale
	float ar_1 = area(point, b, c); // calcolo dell'area del triangolo formato da point e i lati bc
	float ar_2 = area(a, point, c); // calcolo dell'area del triangolo formato da point e i lati ac
	float ar_3 = area(a, b, point); // calcolo dell'area del triangolo formato da point e i lati ab

	if (point == a || point == b || point == c)
        return false; // il punto è su uno dei vertici del triangolo
    if (ar_1 == 0 || ar_2 == 0 || ar_3 == 0)
        return false; // il punto è su uno dei lati del triangolo
    total = ar_1 + ar_2 + ar_3;
    if (fabs(ar - total) < 0.000001)
        return true; // il punto è all'interno del triangolo
    return false; // il punto è all'esterno del triangolo
}
