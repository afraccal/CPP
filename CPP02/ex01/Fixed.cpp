/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:25:52 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/08 15:23:48 by afraccal         ###   ########.fr       */
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

/*
float Fixed::toFloat(void) const:

La funzione toFloat restituisce il valore rappresentato dall'oggetto Fixed in formato float. Per fare ciò,
viene effettuata una divisione tra il valore intero dell'oggetto _fixedNumberValue e la costante 1 << this->_fractionalBitsValue, che rappresenta
il numero di bit utilizzati per la rappresentazione della parte decimale. Il cast (float) viene utilizzato per convertire
il valore intero della parte intera in un valore in virgola mobile di tipo float.
*/

float Fixed::toFloat(void) const
{
    return((float) this->getRawBits() / (1 << this->fractional));
}

/*
int Fixed::toInt(void) const:

La funzione toInt restituisce il valore intero rappresentato dall'oggetto Fixed. Essa effettua una operazione di shift 
verso destra del valore dell'attributo _fixedNumberValue di Fixed di una quantità pari a _fractionalBitsValue, che rappresenta il numero di bit riservati
alla parte frazionaria. In questo modo, vengono eliminati i bit della parte frazionaria e il risultato è un intero corrispondente 
alla parte intera del valore rappresentato da Fixed. La funzione è stata scritta in questo modo per sfruttare la rappresentazione 
fissa a precisione limitata di Fixed e restituire il valore intero corrispondente in modo efficiente.
*/

int Fixed::toInt(void) const
{
    return(this->getRawBits() >> this->fractional);
}

/*
std::ostream &operator<<(std::ostream &output, const Fixed &input):

La funzione operator<< è una funzione che prende in input un output stream (os) e un oggetto Fixed costante (const Fixed &f),
converte l'oggetto f in un valore in virgola mobile e lo scrive sullo stream os. La funzione restituisce l'output stream os, 
in modo da consentire l'operatore di concatenazione << di essere usato ripetutamente per scrivere più oggetti sullo stesso output stream.
Questa funzione è stata scritta in modo tale che quando l'oggetto Fixed viene passato all'operatore <<, viene stampato il valore 
in virgola mobile corrispondente. Questo è utile per la stampa degli oggetti Fixed su un output stream come la console o un file.

L'operatore overload << è utilizzato in questo caso per definire l'output di un oggetto della classe Fixed sullo STDOUT.
In particolare, viene definito un'overload dell'operatore << che prende come primo argomento uno stream di output e come 
secondo argomento un oggetto della classe Fixed. Quando l'operatore << viene utilizzato con un oggetto della classe Fixed,		
viene richiamata la funzione overload, che in questo caso si occupa di stampare il valore dell'oggetto Fixed come un valore
di tipo float. In questo modo è possibile utilizzare l'operatore << per stampare gli oggetti Fixed come se fossero dei valori float.

-> output rappresenta un oggetto std::ostream, che è il tipo di dato di output stream in C++. Viene utilizzato per inviare output verso
un dispositivo di output, come ad esempio lo standard output (ovvero la console), un file, o qualsiasi altra cosa che implementi 
l'interfaccia di output stream.
-> input rappresenta un oggetto della classe Fixed che viene passato per riferimento costante. Viene utilizzato per stampare il valore 
rappresentato dall'oggetto f utilizzando il metodo toFloat() definito nella classe Fixed.
*/

std::ostream & operator<<( std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	//std::cout << std:: endl << "RAW: " << rhs.getRawBits() << std::endl;
	//std::cout << std:: endl << "TOINT: " << rhs.toInt() << std::endl;
	//std::cout << std:: endl << "TOFLOAT: " << rhs.toFloat() << std::endl;
	return (o);
}
