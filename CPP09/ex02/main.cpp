#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "Error: only one argument acceptable" << std::endl;
        return (0);
    }

    PmergeMe test(argv[1]);
    return (0);
}