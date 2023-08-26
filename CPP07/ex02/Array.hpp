/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:55:46 by afraccal          #+#    #+#             */
/*   Updated: 2023/08/26 11:35:48 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
#include <iostream>
#include <stdlib.h>

template <typename T>
class Array
{
private:
    T *array;
    int len;

public:
    Array();
    Array(int n);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();
    T &operator[](int i);
    T const &operator[](int i) const;
    int size() const;
    
public:
    class outofboundsEx : public std::exception
    {
        virtual const char *what() const throw()
        {
            return("Error: index not valid");
        };
    };
};

template <typename T>
Array<T>::Array()
{
    this->array = NULL;
    this->len = 0;
    return ;
}

template <typename T>
Array<T>::Array(int n)
{
    this->len = n;
    this->array = new int[n];
}

template <typename T>
Array<T>::Array(const Array &other)
{
    this->array = NULL;
    this->len = 0;
    *this = other;
}

template <typename T>
Array<T> & Array<T>::operator=(const Array &other)
{
    if (this == &other)
		return (*this);
	this->len = other.size();
	delete [] this->array;
	if (this->len)
	{
		this->array = new T[this->len];
		for (int i = 0; i < this->len; i++)
			this->array[i] = other[i];
	}
	else
		this->array = 0;
	return (*this);
}

template <typename T>
T & Array<T>::operator[](int i)
{
    if(i < 0 || i >= this->len)
        throw Array<T>::outofboundsEx();
    else
        return (this->array[i]);
}

template <typename T>
T const & Array<T>::operator[](int i) const
{
    if(i < 0 || i >= this->len)
        throw Array<T>::outofboundsEx();
    else
        return (this->array[i]);
}
    
template <typename T>
int Array<T>::size() const
{
    return(this->len);
}
    
template <typename T>
Array<T>::~Array()
{
    delete [] this->array;
}

#endif