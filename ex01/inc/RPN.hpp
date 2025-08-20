/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaraniemela <saaraniemela@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:30:22 by sniemela          #+#    #+#             */
/*   Updated: 2025/08/20 12:23:46 by saaraniemel      ###   ########.fr       */
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
		std::stack<int> _numbers;
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