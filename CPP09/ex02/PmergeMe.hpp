#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <iostream>
# include <sstream>
# include <string>
# include <cstring>
# include <algorithm>
# include <ctime>

#define RED     "\033[31;1m"
#define GREEN   "\033[32;1m"
#define YELLOW  "\033[33;1m"
#define BLUE    "\033[34;1m"
#define DEFAULT "\033[0m"

class PmergeMe
{
private:
    std::vector<int> myvector;
    std::vector<std::pair<int,int> > pairVector;
    std::vector<int> sortedVector;
    std::deque<int> mydeque;
    std::deque<std::pair<int,int> > pairDeque;
    std::deque<int> sortedDeque;

public:
    PmergeMe();
    PmergeMe(const PmergeMe &cpy);
    PmergeMe &operator=(const PmergeMe &cpy);
    ~PmergeMe();

    std::vector<int> const get_myvector();
    std::vector<int> const get_myvectorsorted();
    std::deque<int> const get_mydeque();
    std::deque<int> const get_mydequesorted();

    void    parseVec(char **arg);
    void    printVec(std::vector<int> vec);
    void    sortVec();
    void    parseDeq(char **arg);
    void    printDeq(std::deque<int> vec);
    void    sortDeq();
};



#endif