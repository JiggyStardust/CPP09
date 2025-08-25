/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:38:24 by sniemela          #+#    #+#             */
/*   Updated: 2025/08/25 10:08:23 by sniemela         ###   ########.fr       */
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

bool	tokenIsOperator(std::string &token)
{
	if (token == "+" || token == "-" || token == "*" || token == "/") {
		return true;
	}
	return false;
}

void	RPN::calculate(const std::string &input)
{
	std::istringstream iss(input);
	std::string	op;
	float		n;
	float		first;
	float		second;
	float		res;
	
	while (iss >> op) {
		// std::cout << "INSIDE CALCULATION LOOP\n";
		if (!tokenIsOperator(op)) {
			n = std::stof(op);
			_numbers.push(n);
			continue;
		}
		second = _numbers.top();
		_numbers.pop();
		first = _numbers.top();
		_numbers.pop();
		
		if (op == "+") {
			res = first + second;
			_numbers.push(res);
		}
		else if (op == "-") {
			res = first - second;
			_numbers.push(res);
		}
		else if (op == "*") {
			res = first * second;
			_numbers.push(res);
		}
		else if (op == "/") {
			res = first / second;
			_numbers.push(res);
		}
	}
	std::cout << "result: " << _numbers.top() << std::endl;
}

void	RPN::validateInput(const std::string &input)
{
	std::istringstream iss(input);
	std::string token;
	int	numbers = 0;
	int	operators = 0;
	
	while (iss >> token){
		if (tokenIsOperator(token)) {
			if (numbers < operators + 2) {
				throw std::runtime_error("Invalid syntax: operands need to take place before operators and operands > operators.");
			}
			else {
				// _tokens.push(token);
				operators++;
			}
		}
		else if ((token.size() == 1 && token >= "0" && token <= "9") || (token.size() == 2 && token >= "-1" && token <= "-9")) {
			// _tokens.push(token);
			numbers++;
		}
		else {
			throw std::runtime_error("Invalid syntax: supported symbols are digits and + - * /");
		}
	}
	if (!tokenIsOperator(token)) {
		throw std::runtime_error("Invalid syntax: operator should be placed last.");
	}
	else if (operators != numbers - 1) {
		throw std::runtime_error("Invalid syntax: invalid amount of operands and operators"); 
	}
	// std::cout << "Valid syntax!\n";
}