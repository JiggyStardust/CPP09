#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& orig) : _data(orig._data) {}

BitcoinExchange& BitcoinExchange::operator = (const BitcoinExchange& orig) 
{
	if (this != &orig)
	{
		this->_data = orig._data;
	}
	return (*this);
}