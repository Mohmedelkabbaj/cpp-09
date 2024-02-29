/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:32:45 by mel-kabb          #+#    #+#             */
/*   Updated: 2024/02/29 00:41:42 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        Calculator calc(av[1]);
        calc.CalculateNumber();
    }
    else
    {
        std::cout << "Error: wrong number of arguments" << std::endl;
        return (1);
    }
    return (0);
}