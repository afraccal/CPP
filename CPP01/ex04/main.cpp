/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:38:23 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/07 15:06:58 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	std::string s1;
	std::string s2;
	std::string file;
	std::ifstream file1;
	std::ofstream file2;
	int i;
	int pos;
	char c;
	
	if (argc != 4)
	{
		std::cout << "wrong number of arguments" << std::endl;
		return (0);
	}

	i = -1;
	s1 = argv[2];
	s2 = argv[3];
	file1.open(argv[1]);
	if (file1.fail())
	{
		std::cout << "Something went wrong with infile" << std::endl;
		return (1);
	}
	while (!file1.eof() && file1 >> std::noskipws >> c)
		file += c;
	file2.open((std::string(argv[1]) + ".replace").c_str());
	if (file2.fail())
	{
		std::cout << "Something went wrong with outfile" << std::endl;
		return (1);
	}
	while (++i < (int)file.size())
	{
		pos = file.find(argv[2], i);
		if (pos != -1 && pos == i)
		{
			file2 << argv[3];
			i += std::string(argv[2]).size() - 1; 
		}
		else
			file2 << file[i];
	}
	file1.close();
	file2.close();
	return (0);
}