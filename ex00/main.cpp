/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:19:36 by mel-kabb          #+#    #+#             */
/*   Updated: 2024/02/29 00:52:22 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac > 2)
    {
        return (std::cout << "Too many arguments" << std::endl, 0);
    }
    try
    {

        std::string filename(av[1]);
        BitcoinExchange exchange;
        exchange.data();
        exchange.infile(filename);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}