/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:22:46 by afraccal          #+#    #+#             */
/*   Updated: 2023/08/26 16:40:02 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include "iostream"
# include "stack"
# include "list"

template <typename T>
class MutantStack : public std::stack<T>
{
private:
    
public:

MutantStack()
{
    return ;
}

~MutantStack()
{
    return ;
}

MutantStack(const MutantStack &copy)
{
    *this = copy;
}

MutantStack &operator= (const MutantStack &copy)
{
    if (this == copy)
			return (*this);
		this->c = copy.c;
		return (*this);
}

typedef typename std::stack<T>::container_type::iterator iterator;
	iterator	end(void)
	{
		return (this->c.end());
	}
	iterator	begin(void)
	{
		return (this->c.begin());
	}
};

#endif