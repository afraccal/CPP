/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:32:25 by afraccal          #+#    #+#             */
/*   Updated: 2023/08/26 14:06:54 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include "iostream"
# include "vector"
# include "algorithm"
# include "iterator"

template <typename T>
int easyfind(T &container, int num){
    std::vector<int>::iterator it;
    it = find(container.begin(), container.end(), num);
    if (it != container.end())
        return (0);
    return (1);
}

#endif