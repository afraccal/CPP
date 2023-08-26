/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:17:59 by afraccal          #+#    #+#             */
/*   Updated: 2023/08/26 16:03:04 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include "iostream"
# include "vector"
# include "algorithm"
# include "iterator"
# include "exception"
# include "numeric"
# include "stdlib.h"

class Span 
{
    private:
        std::vector<int> vec;
        unsigned int N;
    public:
        Span();
        Span(unsigned int N);
        Span &operator=(const Span &copy);
	    Span(const Span &copy);
        ~Span();
        void    addNumber(int val);
        int     shortestSpan();
        int     longestSpan();
        template <typename InputIterator>
        void	addNumbers(InputIterator begin, InputIterator end);
    public:
        class Overflow : public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("Error: No more element can be added");
            }
        };
        
        class NotEnoughNumber : public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("Not enough number");
            }
        };
};

template <typename InputIterator>
void			Span::addNumbers(InputIterator begin, InputIterator end)
{
	while (begin != end)
	{
		this->addNumber(*begin);
		begin++;
	}
}

#endif