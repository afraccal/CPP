#include "BitcoinExchange.hpp"

int getintDate(std::string date)
{
    int year, month, day;
    std::stringstream ss;
    int fulldate;

    ss.str(date);
    year = atoi(date.substr(0,4).c_str());
    month = atoi(date.substr(5,6).c_str());
    if (month < 1 || month > 12)
    {
        std::cerr << "Out of month range" << std::endl;
        return (-1);
    }
    day = atoi(date.substr(8,9).c_str());
    int month_limits[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day > month_limits[month - 1] || day < 1)
    {
        std::cerr << "Out of day range" << std::endl;
        return (-1);
    }
    fulldate = (year * 10000) + (month * 100) + day; 
    return (fulldate);
}

void    printDate(int n)
{
    int day, month, year;

    day = n % 100;
    month = n % 10000 / 100;
    year = n / 10000;
    std::cout << year << "-" << month << "-" << day << std::endl; 
}

BitcoinExchange::BitcoinExchange()
{
//    std::ifstream file;
//    std::string buffer, date, rate;
//    int datenum;
//
//    file.open("data.csv");
//    if (file.fail())
//    {
//        std::cerr << "Impossible open file" << std::endl;
//        return ;
//    }
//    while(std::getline(file, buffer, '\n'))
//    {
//        date = buffer.substr(0, buffer.find('|') - 1);
//        datenum = getintDate(date);
//        rate = buffer.substr(buffer.find('|') + 1, buffer.size());
//
//        this->database.insert(std::pair<int, float>(datenum, atof(rate.c_str())));
//    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
    *this = cpy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
    this->database = cpy.database;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

int BitcoinExchange::read_file(std::string data)
{
    std::string buffer, date, rate;
    std::ifstream file;
    int datenum;

    file.open(data);
    if (file.fail())
    {
        std::cerr << "Cannot open file" << std::endl;
        return (-1);
    }
    while(std::getline(file, buffer, '\n'))
    {
        date = buffer.substr(0, buffer.find('|'));
        datenum = getintDate(date);
        rate = buffer.substr(buffer.find(',') + 1, buffer.size());
        
        std::cout << datenum << " //// " << rate << std::endl;
        this->database.insert(std::pair<int, float>(datenum, atof(rate.c_str())));
    }
    return (0);
}

//void BitcoinExchange::exchange(std::string data)
//{
//    for(std::map<int, float>::iterator it = this->convert.begin(); it != this->convert.end(); it++)
//    {
//
//    }
//}
