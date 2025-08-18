#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &orig);
		BitcoinExchange& operator = (const BitcoinExchange &orig);
};