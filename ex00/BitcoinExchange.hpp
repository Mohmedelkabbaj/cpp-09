/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:46:26 by mel-kabb          #+#    #+#             */
/*   Updated: 2024/02/27 21:43:08 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <fstream>
#include <exception>

class BitcoinExchange
{
private:
    std::map<std::string, double> exchange;
    int checkvalue(std::string &value);
    int checkDate(char c, int nbr, int mon);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &obj);
    BitcoinExchange &operator=(const BitcoinExchange &obj);
    void data();
    void infile(std::string filename);
    ~BitcoinExchange();
};

#endif