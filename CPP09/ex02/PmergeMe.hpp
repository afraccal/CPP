#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <iostream>
# include <string>
# include <cstring>

class PmergeMe
{
private:
    std::vector<int> myvector;
    std::deque<int> mydeque;
public:
    PmergeMe();
    PmergeMe(std::string arg);
    PmergeMe(const PmergeMe &cpy);
    PmergeMe &operator=(const PmergeMe &cpy);
    ~PmergeMe();
};



#endif