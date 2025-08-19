/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:38:24 by sniemela          #+#    #+#             */
/*   Updated: 2025/08/19 15:12:07 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& orig) : _numbers(orig._numbers), _tokens(orig._tokens) {}

RPN& RPN::operator = (const RPN& orig) {
	if (this != &orig){
		this->_numbers = orig._numbers;
		this->_tokens = orig._tokens;
	}
	return (*this);
}

void	RPN::parseInput(const std::string &input)
{
	std::istringstream iss(input);
	std::string token;
	while (iss >> token){
		if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (_numbers.size() == 0 || _numbers.size() < _tokens.size() + 1) {
				throw std::runtime_error("Invalid operation: operands need to take place before operators and operands > operators.");
			}
			else {
				_tokens.push(token);
			}
		}
		else if () {

		}
		else
	}
}