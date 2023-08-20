/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:38:43 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/30 11:46:23 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Default ScalarConverter created" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    std::cout << "Copy ScalarConverter created" << std::endl;
    *this = other;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destroyed" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    std::cout << "operator ScalarConverter setted" << std::endl;
    return(*this);
}

void ScalarConverter::convert(std::string literal)
{
    std::cout << "char: " << toChar(literal) << std::endl;
    std::cout << "int: " << toInt(literal) << std::endl;
    std::cout << "float: " << toFloat(literal) << std::endl;
    std::cout << "double: " << toDouble(literal) << std::endl;
}

bool ScalarConverter::isNumber(std::string arg)
{
    if (!arg.compare("-inf") || !arg.compare("+inf") || !arg.compare("-inff") || !arg.compare("+inff"))
        return (true);
    unsigned long i = 0;
    while (i < arg.size() - 1)
    {
        if (!std::isdigit(arg[i]) && arg[i] != '.' && arg[i] != '+' && arg[i] != '-')
            return (false);
        i++;
    }
    if (!std::isdigit(arg[arg.size() - 1]) && arg[arg.size() - 1] != 'f')
		return(false);
    return (true);
}

std::string ScalarConverter::toChar(std::string arg)
{
    char str[2];
    std::string conversion;
    
    if (!arg.compare("-inf") || !arg.compare("+inf") || !arg.compare("-inff") || !arg.compare("+inff"))
    {
        conversion += "Impossible";
    }
    else if (arg.size() == 1)
    {
        if (arg.c_str()[0] < 32 || arg.c_str()[0] > 126 || (arg.c_str()[0] >= 48 && arg.c_str()[0] <= 57))
        {
            conversion += "Not displayable";
        }
        else
        {
            int num = static_cast<int>(arg[0]);
            str[0] = num;
            str[1] = 0;
            conversion += str;
        }
    }
    else
    {
        int num = std::atoi(arg.c_str());
        str[0] = num;
        str[1] = 0;
        conversion += num;
    }
    return (conversion);
}


std::string ScalarConverter::toInt(std::string arg)
{
    std::stringstream conversion;
    long int num = std::atol(arg.c_str());

    if (!arg.compare("-inf") || !arg.compare("-inff") || !arg.compare("+inf") || !arg.compare("+inff"))
        conversion << "Out of range";
    else if (isNumber(arg) == false || !arg.compare("nan") || !arg.compare("nanf"))
        conversion << "Impossible";
    else if (num > INT_MAX || num < INT_MIN)
		conversion << "Out of range";
    else
        conversion << static_cast<int>(num);
    return (conversion.str());
}


std::string ScalarConverter::toFloat(std::string arg)
{
    std::stringstream conversion;
    float num = std::atof(arg.c_str());

    if (!arg.compare("-inf") || !arg.compare("-inff"))
		conversion << "-Inff";
	else if(!arg.compare("+inff") || !arg.compare("+inf"))
		conversion << "Inff";
	else if (!arg.compare("nan") || !arg.compare("nanf"))
		conversion << "Nanf";
	else if (isNumber(arg) == false)
		conversion << "Nanf";
	else
	{
		conversion << static_cast<float>(num) << "f";
	}
	return(conversion.str());
}


std::string ScalarConverter::toDouble(std::string arg)
{
    std::stringstream conversion;
    double num = std::atof(arg.c_str());

    if (!arg.compare("-inf") || !arg.compare("-inff"))
		conversion << "-Inff";
	else if(!arg.compare("+inff") || !arg.compare("+inf"))
		conversion << "Inff";
	else if (!arg.compare("nan") || !arg.compare("nanf"))
		conversion << "Nan";
	else if (isNumber(arg) == false)
		conversion << "Nan";
	else
	{
		conversion << static_cast<double>(num);
	}
	return(conversion.str()); 
}
