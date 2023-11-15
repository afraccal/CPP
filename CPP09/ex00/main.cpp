#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc!=2)
    {
        std::cerr << "Wrong number of argument. Only one needed" << std::endl;
        return 0;
    }
    BitcoinExchange date;

    date.read_file(argv[1]);
}