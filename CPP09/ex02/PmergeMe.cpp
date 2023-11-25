#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(std::string arg)
{
    int i = 0;
    unsigned long space;

    while((space = arg.substr().find(" ")))
    {   
        i++;
        std::cout << space << "||" << i << std::endl;
        space++;
    }

    std::cout << "Before: " << arg << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &cpy)
{
    *this = cpy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &cpy)
{
    this->mydeque = cpy.mydeque;
    this->myvector =cpy.myvector;
    return *this;
}

PmergeMe::~PmergeMe()
{
}
