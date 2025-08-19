/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:30:22 by sniemela          #+#    #+#             */
/*   Updated: 2025/08/19 14:59:57 by sniemela         ###   ########.fr       */
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
		std::stack<std::string> _tokens; // for operators
	public:
		RPN();
		~RPN();
		RPN(const RPN& orig);
		RPN& operator = (const RPN& orig);
		void	parseInput(const std::string &input);
};