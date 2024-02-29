/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:07:21 by mel-kabb          #+#    #+#             */
/*   Updated: 2024/02/27 23:36:26 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <iterator>

class Calculator
{
private:
    std::stack<int> stack;
    std::string num;
    void checkoperater(char c);

public:
    Calculator(std::string str);
    Calculator(const Calculator &obj);
    Calculator &operator=(const Calculator &obj);
    ~Calculator();
    void CalculateNumber();
};

#endif