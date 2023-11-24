#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Only one argument required" <<std::endl;
        return(0);
    }
    RPN data(argv[1]);
}