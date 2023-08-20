/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:36:18 by afraccal          #+#    #+#             */
/*   Updated: 2023/08/20 15:21:11 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP

# include "iostream"
# include "string"
# include "stdlib.h"
# include "sstream"
# include "limits.h"

class ScalarConverter
{
private:
    
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ~ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter &other);
    
    static void convert(std::string literal);
    static bool isNumber(std::string arg);
    static std::string toChar(std::string arg);
	static std::string toInt(std::string arg);
	static std::string toDouble(std::string arg);
	static std::string toFloat(std::string arg);
};

#endif
