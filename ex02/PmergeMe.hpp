/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:15:22 by mel-kabb          #+#    #+#             */
/*   Updated: 2024/02/29 00:08:41 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <chrono>
#include <sys/time.h>

static unsigned int a;
static int b = 0;


class PmergeMe
{
private:
    PmergeMe();
    PmergeMe(const PmergeMe &obj);
    PmergeMe &operator=(const PmergeMe &obj);
    ~PmergeMe();

public:
    template <typename T>
    static void print(T &vector)
    {
        for (size_t i = 0; i < vector.size(); i++)
        {
            std::cout << vector[i] << " ";
        }
    }

    template <typename T>
    static void print1(T &vector)
    {
        for (size_t i = 1; i < vector.size(); i++)
        {
            std::cout << vector[i] << " ";
        }
    }

    template <typename T>
    static void quicksort(T &container)
    {
        for (size_t i = 0; i < container.size(); i++)
        {
            if (container[i].first > container[i].second)
            {
                std::swap(container[i].first, container[i].second);
            }
        }
    }

    template <typename T, typename M>
    static void insert(T &big, M &small)
    {
        b = 0;
        for (size_t i = 0; i < big.size(); i++)
            small.insert(std::lower_bound(small.begin(), small.end(), big[i]), big[i]);
        if (b == 1)
            small.insert(std::lower_bound(small.begin(), small.end(), a), a);
    }

    template <typename T, typename M, typename K>
    static void findbignumber(T &container, M &big, K &small)
    {
        for (size_t i = 0; i < container.size(); i++)
        {
            small.push_back(container[i].first);
        }
        for (size_t i = 0; i < container.size(); i++)
        {
            big.push_back(container[i].second);
        }
        std::sort(small.begin(), small.end());
        insert(big, small);
    }
};

#endif
