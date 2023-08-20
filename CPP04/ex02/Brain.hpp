/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:21:21 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/19 14:28:37 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "iostream"
# include "string"

class Brain
{
public:
    Brain();
    Brain (const Brain &src);
    ~Brain();
    Brain &operator=(const Brain &src);
    std::string ideas[100];
};




#endif