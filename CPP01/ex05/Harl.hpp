/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:14:59 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/07 16:07:18 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
private:
    void debug( void );
    void info ( void );
    void warning( void );
    void error ( void );
public:
    Harl();
    ~Harl();
    void complain( std::string level);
};

#endif