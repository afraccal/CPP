#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc!=2)
    {
        std::cerr << "Error: could not open file" << std::endl;
        return 0;
    }
    BitcoinExchange data;

    data.read_file(argv[1]);
    data.converter();
    return (0);
}