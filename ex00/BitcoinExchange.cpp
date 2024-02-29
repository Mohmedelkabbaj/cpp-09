/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:46:30 by mel-kabb          #+#    #+#             */
/*   Updated: 2024/02/27 22:20:41 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
    *this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    if (this != &obj)
    {
        this->exchange = obj.exchange;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

int BitcoinExchange::checkDate(char c, int nbr, int mon)
{
    int tab[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (c == 'd' && (nbr < 1 || nbr > tab[mon - 1]))
        return (0);
    if (c == 'm' && (mon < 1 || mon > 12))
        return (0);
    if (c == 'y' && nbr < 2009)
        return (0);
    return (1);
}

int BitcoinExchange::checkvalue(std::string &value)
{
    int i = 0;
    if (value[0] == '\0')
        return (0);
    while (value[i] == ' ')
        i++;
    if (value[i] == '\0')
        return (0);
    if (value[i] == '-' || value[i] == '+')
        i++;
    while (value[i] != '\0' && isdigit(value[i]) == 1)
        i++;
    if (value[i] == '.')
        i++;
    while (value[i] != '\0' && isdigit(value[i]) == 1)
        i++;
    while (value[i] == ' ')
        i++;
    if (value[i] != '\0')
        return (0);
    return (1);
}

void BitcoinExchange::data()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw std::invalid_argument("File not found");
    std::string str;
    std::getline(file, str);
    while (std::getline(file, str))
    {
        std::stringstream s(str);
        std::string date;
        std::string value;
        std::getline(s, date, ',');
        std::getline(s, value, ',');
        exchange[date] = std::stod(value);
    }
}

void BitcoinExchange::infile(std::string filename)
{
    std::ifstream file(filename);
    std::string str;
    std::string value;
    std::string date;
    std::string year;
    std::string month;
    std::string day;
    double value11;
    int iyear;
    int imonth;
    int iday;
    if (!file.is_open())
        throw std::invalid_argument("File not found");
    std::getline(file, str);
    if (str.empty())
        throw std::invalid_argument("File is empty");
    if (strcmp(str.c_str(), "date | value") != 0)
        throw std::invalid_argument("line one is not date | value");
    while (std::getline(file, str))
    {
        if (str.empty())
            continue;
        date = str.substr(0, str.find(" "));
        year = date.substr(0, 4);
        month = date.substr(5, 2);
        day = date.substr(8, 2);
        iyear = std::stoi(year);
        imonth = std::stoi(month);
        iday = std::stoi(day);
        if (iyear == 2009 && imonth == 1 && iday == 1)
        {
            std::cout << "Error: bad input =>" << str << std::endl;
            continue;
        }
        if (checkDate('y', iyear, imonth) == 0 || checkDate('m', imonth, imonth) == 0 || checkDate('d', iday, imonth) == 0)
        {
            std::cout << "Error: bad input =>" << str << std::endl;
            continue;
        }
        if (str.length() < 14)
        {
            std::cout << "Error: bad input =>" << str << std::endl;
            continue;
        }
        value = str.substr(13);
        if (checkvalue(value) == 0)
        {
            std::cout << "Error: invalide value." << std::endl;
            continue;
        }
        value11 = std::stof(value);
        if (value11 > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        if (value11 < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        std::map<std::string, double>::iterator it = exchange.lower_bound(date);
        if ((*it).first != date)
        {
            it--;
        }
        std::cout << date << " => " << value << " = " << (*it).second * value11 << std::endl;
    }
}