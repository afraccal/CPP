/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:54:31 by afraccal          #+#    #+#             */
/*   Updated: 2023/05/30 09:26:22 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Contact_HPP
# define Contact_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
    public:
        Contact (void);
        ~Contact (void);
		
		void set_name(std::string str);
		void set_lastname(std::string str);
		void set_nickname(std::string str);
		void set_phonenumber(std::string str);
		void set_darkest_secret(std::string str);

		std::string get_name(void);
		std::string get_lastname(void);
		std::string get_nickname(void);
		std::string get_phonenumber(void);
		std::string get_darkest_secret(void);
		
		void print_info(void);
	
	private:
		std::string	name;
		std::string lastname;
		std::string nickname;
		std::string phonenumber;
		std::string darkest_secret;
};

#endif