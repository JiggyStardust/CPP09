/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:30:22 by sniemela          #+#    #+#             */
/*   Updated: 2025/08/25 10:06:51 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <exception>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPN {
	private:
		std::stack<float> _numbers;
		std::stack<std::string> _tokens;
		std::stack<std::string> _operators;
	public:
		RPN();
		~RPN();
		RPN(const RPN& orig);
		RPN& operator = (const RPN& orig);
		void	validateInput(const std::string &input);
		void	calculate(const std::string &input);
};