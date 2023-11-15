#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <cmath>

class BitcoinExchange
{
private:
    std::map<int, float> database;
//    std::multimap<int, float> convert;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &cpy);
    BitcoinExchange &operator=(const BitcoinExchange &cpy);
    ~BitcoinExchange();
    int read_file(std::string data);
    void exchange(std::string data);
};

#endif