#pragma once

#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <istream>
#include <map>
#include <regex>
#include <sstream>
#include <string>

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
		void	validateAndCout(char *input);
};