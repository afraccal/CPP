#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

/*GETTER*/
std::vector<int> const PmergeMe::get_myvector()
{
    return (this->myvector);
}

std::vector<int> const PmergeMe::get_myvectorsorted()
{
    return (this->sortedVector);
}

std::deque<int> const PmergeMe::get_mydeque()
{
    return (this->mydeque);
}

std::deque<int> const PmergeMe::get_mydequesorted()
{
    return (this->sortedDeque);
}

/* VECTOR */
void    PmergeMe::parseVec(char **arg)
{
    int     num;

    for(int i = 1; arg[i]; i++)
    {
        if(std::istringstream(arg[i]) >> num && num >= 0 && num < INT_MAX)
        {
            myvector.push_back(num);
        }
        else
        {
            throw std::invalid_argument("Error: they must be positive integer number");
        }
    }
    if (myvector.size() == 0)
    {
        throw std::invalid_argument("Error: empty vector");
    }
}

void PmergeMe::printVec(std::vector<int> vec)
{
    std::vector<int>::iterator  it;
    for(it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return;
}

void   PmergeMe::sortVec()
{
    if(myvector.size() == 1)
        return;

    /*Split in two segments(if odd, last element get left unused)
      Pair each i-th element of the segments and compare
      Swap to have element in first segment and correspondig element in second segment*/
    
    /*create pairs*/
    for (size_t i = 0; i < myvector.size(); i++)
    {
        if (i == 0 && (myvector.size() % 2))
            pairVector.push_back(std::make_pair(-1, myvector[i]));
        else
        {
            pairVector.push_back(std::make_pair(myvector[i], myvector[i + 1]));
            i = i + 1;
        }
    }

    /*swap pair*/
    for (std::vector<std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); ++it)
    {
        if ((*it).first > (*it).second)
            std::swap(it->first, it->second);
    }

    /*sort pair keeping account of the first element*/
    for (std::vector<std::pair<int, int> >::iterator it = pairVector.begin() + 1; it != pairVector.end(); ++it)
    {
        std::vector<std::pair<int, int> >::iterator actual = it;
        std::vector<std::pair<int, int> >::iterator prev = it - 1;
        while (actual->first < prev->first)
        {
            std::swap(*actual, *prev);
            if (prev != pairVector.begin())
            {
                actual = prev;
                prev = actual - 1;
            }
        }
    }
    
    /*push first element in sorted vector*/
    for (std::vector<std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); ++it)
    {
        if (it->first != -1)
            sortedVector.push_back(it->first);
    }

    /*insert second element in sorted vector*/
    for (std::vector<std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); ++it)
    {
        std::vector<int>::iterator sorted;

        sorted = std::lower_bound(sortedVector.begin(), sortedVector.end(), it->second);
        sortedVector.insert(sorted,it->second);
    }
}

/*DEQUE*/
void    PmergeMe::parseDeq(char **arg)
{
    int     num;

    for(int i = 1; arg[i]; i++)
    {
        if(std::istringstream(arg[i]) >> num && num >= 0 && num < INT_MAX)
        {
            mydeque.push_back(num);
        }
        else
        {
            throw std::invalid_argument("Error: they must be positive integer number");
        }
    }
    if (mydeque.size() == 0)
    {
        throw std::invalid_argument("Error: empty vector");
    }
}

void PmergeMe::printDeq(std::deque<int> deq)
{
    std::deque<int>::iterator  it;
    for(it = deq.begin(); it != deq.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return;
}

void   PmergeMe::sortDeq()
{
    /*create pairs*/
    for (size_t i = 0; i < mydeque.size(); i++)
    {
        if (i == 0 && (mydeque.size() % 2))
            pairDeque.push_back(std::make_pair(-1, mydeque[i]));
        else
        {
            pairDeque.push_back(std::make_pair(mydeque[i], mydeque[i + 1]));
            i = i + 1;
        }
    }

    /*swap pair*/
    for (std::deque<std::pair<int, int> >::iterator it = pairDeque.begin(); it != pairDeque.end(); ++it)
    {
        if ((*it).first > (*it).second)
            std::swap(it->first, it->second);
    }

    /*sort pair keeping account of the first element*/
    for (std::deque<std::pair<int, int> >::iterator it = pairDeque.begin() + 1; it != pairDeque.end(); ++it)
    {
        std::deque<std::pair<int, int> >::iterator actual = it;
        std::deque<std::pair<int, int> >::iterator prev = it - 1;
        while (actual->first < prev->first)
        {
            std::swap(*actual, *prev);
            if (prev != pairDeque.begin())
            {
                actual = prev;
                prev = actual - 1;
            }
        }
    }
    
    /*push first element in sorted vector*/
    for (std::deque<std::pair<int, int> >::iterator it = pairDeque.begin(); it != pairDeque.end(); ++it)
    {
        if (it->first != -1)
            sortedDeque.push_back(it->first);
    }

    /*insert second element in sorted vector*/
    for (std::deque<std::pair<int, int> >::iterator it = pairDeque.begin(); it != pairDeque.end(); ++it)
    {
        std::deque<int>::iterator sorted;

        sorted = std::lower_bound(sortedDeque.begin(), sortedDeque.end(), it->second);
        sortedDeque.insert(sorted,it->second);
    }
}

PmergeMe::PmergeMe(const PmergeMe &cpy)
{
    *this = cpy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &cpy)
{
    this->mydeque = cpy.mydeque;
    this->myvector = cpy.myvector;
    this->pairVector = cpy.pairVector;
    this->sortedVector = cpy.sortedVector;
    this->pairDeque = cpy.pairDeque;
    this->sortedDeque = cpy.sortedDeque;
    return *this;
}

PmergeMe::~PmergeMe()
{
}
