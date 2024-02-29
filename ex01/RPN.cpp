/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:12:25 by mel-kabb          #+#    #+#             */
/*   Updated: 2024/02/29 00:41:03 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Calculator::Calculator(std::string str)
{
    num = str;
}

Calculator::Calculator(const Calculator &obj)
{
    *this = obj;
}

Calculator &Calculator::operator=(const Calculator &obj)
{
    if (this != &obj)
    {
        this->num = obj.num;
        this->stack = obj.stack;
    }
    return *this;
}

Calculator::~Calculator()
{
}

void Calculator::checkoperater(char c)
{
    if (stack.size() < 2)
    {
        std::cout << "Error: not enough numbers" << std::endl;
        exit(1);
    }
    int b = stack.top();
    stack.pop();
    int a = stack.top();
    stack.pop();
    switch (c)
    {
    case '+':
        stack.push(a + b);
        break;
    case '-':
        stack.push(a - b);
        break;
    case '*':
        stack.push(a * b);
        break;
    case '/':
        if (b == 0)
        {
            std::cout << "Error: division by zero" << std::endl;
            exit(1);
        }
        stack.push(a / b);
        break;
    default:
        throw std::invalid_argument("Error");
    }
}

void Calculator::CalculateNumber()
{
    for (size_t i = 0; i < num.length(); i++)
    {
        if (isdigit(num[i]) == true)
        {
            stack.push(num[i] - '0');
        }
        else if (num[i] == '+' || num[i] == '-' || num[i] == '*' || num[i] == '/')
        {
            checkoperater(num[i]);
        }
        else if (num[i] == ' ')
        {
            continue;
        }
        else
        {
            std::cout << "Error: invalid character" << std::endl;
            exit(1);
        }
    }
    if (stack.size() != 1)
    {
        std::cout << "Error: too many numbers" << std::endl;
        exit(1);
    }
    std::cout << stack.top() << std::endl;
}
