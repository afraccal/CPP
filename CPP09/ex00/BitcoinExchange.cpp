#include "BitcoinExchange.hpp"

int getintDate(std::string date)
{
    int year, month, day;
    std::stringstream ss;
    int fulldate;
    int not_acceptable = 1;

    ss.str(date);
    year = atoi(date.substr(0,4).c_str());
    month = atoi(date.substr(5,6).c_str());
    if (month < 1 || month > 12)
    {
        not_acceptable = 0;
    }
    day = atoi(date.substr(8,9).c_str());
    int month_limits[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day > month_limits[month - 1] || day < 1)
    {
        not_acceptable = 0;
    }
    fulldate = (year * 10000) + (month * 100) + day;
    if (not_acceptable)
        return (fulldate); 
    return (fulldate * (-1));
}

void    printDate(int n)
{
    int day, month, year;

    if (n < 0)
        n = n * (-1);
    day = n % 100;
    month = n % 10000 / 100;
    year = n / 10000;
    std::cout << year << "-" << month << "-" << day; 
}

BitcoinExchange::BitcoinExchange()
{
    std::string buffer, date, rate;
    std::ifstream file;
    int datenum;

    file.open("data.csv");
    if (file.fail())
    {
        std::cerr << "Error: could not open file" << std::endl;
        exit(1);
    }
    std::getline(file, buffer, '\n');
    while(std::getline(file, buffer, '\n'))
    {
        date = buffer.substr(0, buffer.find(','));
        datenum = getintDate(date);
        rate = buffer.substr(buffer.find(',') + 1, buffer.size());
        
        this->database.insert(std::pair<int, float>(datenum, atof(rate.c_str())));
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
    *this = cpy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
    this->database = cpy.database;
    this->map_convert = cpy.map_convert;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

int BitcoinExchange::read_file(std::string data)
{
    std::string buffer, date, value;
    std::ifstream file;
    int datenum;

    file.open(data);
    if (file.fail())
    {
        std::cerr << "Error: could not open file" << std::endl;
        return (-1);
    }
    std::getline(file, buffer, '\n');
    while(std::getline(file, buffer, '\n'))
    {
        if(buffer.find('|' != std::string::npos))
            date = buffer.substr(0, buffer.find('|') - 1);
        else
        {
            date=buffer;
            datenum = getintDate(date);
            value = -1;
            this->map_convert.insert(std::pair<int, float>(datenum, atof(value.c_str())));
        }
        datenum = getintDate(date);
        value = buffer.substr(buffer.find('|') + 1, buffer.size());
        
        //std::cout << datenum << " //// " << value << std::endl;
        this->map_convert.insert(std::pair<int, float>(datenum, atof(value.c_str())));
    }
    return (0);
}

int error_handling(std::map<int, float>::iterator it)
{
    int error = 0;

    if(it->first < 0)
    {
        std::cerr << "Error: bad input => ";
        printDate(it->first);
        std::cout << std::endl;
        error = 1;
    }
    if(it->second <= 0)
    {
        std::cerr << "Error: not a positive number" << std::endl;
        error = 1;
    }
    if(it->second >= 1000)
    {
        std::cerr << "Error: too large a number" << std::endl;
        error = 1;
    }
    return (error);
}

void BitcoinExchange::converter()
{
    int b = 0, f = 0;
    for(std::map<int, float>::iterator it = this->map_convert.begin(); it != this->map_convert.end(); it++)
    {
        if(error_handling(it))
            continue;
        if (this->database.find(it->first) != this->database.end())
        {
            printDate(it->first);
            std::cout << " => " << it->second << " = " << this->database.find(it->first)->second * it->second << std::endl; 
        }
        else
        {
            for(std::map<int, float>:: iterator itnew = this->database.begin(); itnew != this->database.end(); itnew++)
            {
                if(itnew->first >= it->first)
                {
                    f = itnew->first - it->first;
                    break;
                }
            }
            for(std::map<int, float>:: iterator itnew = this->database.end(); itnew != this->database.begin(); itnew--)
            {
                if(itnew->first <= it->first)
                {
                    b = it->first - itnew->first;
                    break;
                }
            }
            printDate(it->first);
            if (b < f)
                std::cout << " => " << it->second << " = " << this->database.find(it->first - b)->second * it->second << std::endl; 
            else
                std::cout << " => " << it->second << " = " << this->database.find(it->first + f)->second * it->second << std::endl;
        }
    }
}
