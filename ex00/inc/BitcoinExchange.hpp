/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:23:20 by sniemela          #+#    #+#             */
/*   Updated: 2025/08/19 13:27:52 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <ctime>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <istream>
#include <map>
#include <regex>
#include <sstream>
#include <string>
#include <locale>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &orig);
		BitcoinExchange& operator = (const BitcoinExchange &orig);
		void	parseDataFile();
		void	validateInputAndCout(char *input);
		float	getRateForDate(const std::string &date);
		std::map<std::string, float> getMap(); // for debugging
};