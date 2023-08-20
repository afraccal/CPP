/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:38:09 by afraccal          #+#    #+#             */
/*   Updated: 2023/08/20 15:56:16 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "iostream"
# include "sstream"
# include "string.h"
# include "stdint.h"
# include "stdlib.h"

typedef struct s_Data 
{
    std::string string;
} Data;

class   Serializer
{
    private:
    
    public:
        Serializer();
        Serializer(const Serializer &other);
        ~Serializer();
        Serializer &operator=(const Serializer &other);

        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};
#endif