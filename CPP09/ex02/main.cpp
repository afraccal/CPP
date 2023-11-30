#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << RED << "Error: missing argument" << std::endl;
        return(1);
    }
    if (argc == 2)
    {
        PmergeMe unique;
        unique.parseVec(argv);
        std::cout << BLUE << "There is only one number: ";
        unique.printVec(unique.get_myvector()); 
        std::cout << DEFAULT;
        return (1);
    }
    try
    {
        PmergeMe vec;
        PmergeMe deq;

        clock_t vecStart = clock();
        vec.parseVec(argv);
        std::cout << GREEN << "Before: ";
        vec.printVec(vec.get_myvector());
        vec.sortVec();
        std::cout << BLUE << "After: ";
        vec.printVec(vec.get_myvectorsorted());
        clock_t vecFinish = clock();
        clock_t deqStart = clock();
        deq.parseDeq(argv);
        std::cout << GREEN << "Before: ";
        deq.printDeq(deq.get_mydeque());
        deq.sortDeq();
        std::cout << BLUE << "After: ";
        deq.printDeq(deq.get_mydequesorted());
        clock_t deqFinish = clock();
        double time = double(vecFinish - vecStart) / CLOCKS_PER_SEC * 1000000;
        std::cout << YELLOW <<"Time to process a range of " << argc - 1 << " elements with std::vector: " << time << " us" << DEFAULT << std::endl;
        time = double(deqFinish - deqStart) / CLOCKS_PER_SEC * 1000000;
        std::cout << YELLOW <<"Time to process a range of " << argc - 1 << " elements with std::deque: " << time << " us" << DEFAULT << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << RED << e.what() << '\n';
    }
    
    return (0);
}