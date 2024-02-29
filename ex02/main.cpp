/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:15:13 by mel-kabb          #+#    #+#             */
/*   Updated: 2024/02/29 00:14:18 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>

int main(int ac, char **av)
{

    if (ac <= 2)
    {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }
    std::vector<std::pair<unsigned int, unsigned int> > container;
    std::deque<std::pair<unsigned int, unsigned int> > container2;
    std::vector<unsigned int> big, small;
    std::deque<unsigned int> big2, small2;

    int len = ac % 2 == 0 ? ac - 1 : ac;
    
    for (int iter = 1; iter < len; iter += 2)
    {
        std::stringstream ss;
        int num;
    
        ss << av[iter];
        
        if (ss >> num && ss.eof())
        {
            if (num < 0)
            {
                std::cout << "Invalid input" << std::endl;
                exit(1);
            }
            container.push_back(std::make_pair(std::atoi(av[iter]), std::atoi(av[iter + 1])));
            container2.push_back(std::make_pair(std::atoi(av[iter]), std::atoi(av[iter + 1])));
        }
        else
        {
            std::cout << "Invalid input" << std::endl;
            exit(1);
        }
    }
    float time1;
    if (len != ac) 
    {
        container.push_back(std::make_pair(std::atoi(av[ac - 1]), NULL));
        container2.push_back(std::make_pair(std::atoi(av[ac - 1]), NULL));
            std::cout << "Vector before quicksort: ";
        for (int i = 1; av[i]; i++)
            std::cout << av[i] << " " ;
        clock_t time = clock();
        PmergeMe::quicksort(container);
        PmergeMe::findbignumber(container, big, small);
        clock_t end = clock();
        time1 = static_cast<float>(end - time) / CLOCKS_PER_SEC * 1000;
        std::cout << "\nVector after quicksort: ";
        PmergeMe::print1(small);
         std::cout << "\nTime taken for vector: " << ac - 1 << " attributs with vector" << time1 << " us" << std::endl;
        clock_t time2 = clock();
        PmergeMe::quicksort(container2);
        PmergeMe::findbignumber(container2, big2, small2);
        clock_t end2 = clock();
        float time3 = static_cast<float>(end2 - time2) / CLOCKS_PER_SEC * 1000;
        std::cout << "Time taken for vector: " << ac - 1 << " attributs with deque" << time3 << " us" << std::endl;
    }
    else
    {
        std::cout << "Vector before quicksort: ";
        for (int i = 1; av[i]; i++)
            std::cout << av[i] << " " ;
        clock_t time = clock();
        PmergeMe::quicksort(container);
        PmergeMe::findbignumber(container, big, small);
        clock_t end = clock();
        time1 = static_cast<float>(end - time) / CLOCKS_PER_SEC * 1000;
        std::cout << "\nVector after quicksort: ";
        PmergeMe::print(small);
        std::cout << "\nTime taken for vector: " << ac - 1 << " attributs with vector" << time1 << " us" << std::endl;
        clock_t time2 = clock();
        PmergeMe::quicksort(container2);
        PmergeMe::findbignumber(container2, big2, small2);
        clock_t end2 = clock();
        float time3 = static_cast<float>(end2 - time2) / CLOCKS_PER_SEC * 1000;
        std::cout << "Time taken for vector: " << ac - 1 << " attributs with deque" << time3 << " us" << std::endl;
    }
}