/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:23:27 by sniemela          #+#    #+#             */
/*   Updated: 2025/08/19 14:24:51 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	validateDataLine(std::string &line)
{
	std::regex valid_form(R"(^\d{4}-\d{2}-\d{2},-?(\d{1,6}|\d{1,6}\.\d{1,2}))");

	if (!std::regex_match(line, valid_form))
	{
		throw std::runtime_error("data.csv invalid format in line: " + line);
	}
}

std::map<std::string, float> BitcoinExchange::getMap()
{
	return _data;
}

bool	isValidDate(const std::string &date)
{
	// use get_time to convert the string YYYY-MM-DD into std::tm (struct) as format tm_year, tm_mon, tm_mday
	std::tm time = {};
	std::istringstream ss(date);
	ss >> std::get_time(&time, "%Y-%m-%d");
	if (ss.fail()) {
		// std::cout << "ss failed\n";
		return false;
	}

	// Use mktime (maketime based on tm format) to further check calendar validity. Will still accept silly dates like 34th and move it to the next months dates.

	time.tm_isdst = -1; // mktime gets to decide daytime settings
	if (mktime(&time) == -1){
		// std::cout << "mktime failed\n";
		return false;
	}
	// Convert the date and time information from a given calendar time to a null-terminated multibyte character string

	char buffer[11]; // YYYY-MM-DD'\0'
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &time);
	// std::cout << "date: " << date << ", buffer: " << buffer << std::endl;
	// Now we see, if the original date string still matches with converted time -> catches leap years, unexisting dates etc.
	return (date == buffer);
}

void	BitcoinExchange::parseDataFile()
{
	std::ifstream file("data.csv");
	if (!file) {
		throw std::runtime_error("opening data.csv");
	}
	std::string	line;
	std::string	date;
	float		value;
	
	std::getline(file, line);
	if (line != "date,exchange_rate") {
		file.close();
		throw std::runtime_error("data.csv missing valid header");
	}
	while (std::getline(file, line))
	{
		if (line.empty()) {
			continue;
		}
		try {
			validateDataLine(line);
		}
		catch (std::exception &e) {
			file.close();
			throw std::runtime_error(e.what());
		}
		size_t pos = line.find(",");
		if (pos == std::string::npos){
			file.close();
			throw std::runtime_error("data.csv wrong formatting");
		}
		date = line.substr(0, pos);
//		std::cout << "Date: " << date << std::endl;
		if (!isValidDate(date)) {
			file.close();
			throw std::runtime_error("data.csv: not a valid date " + date);
		}
		try {
			value = stof(line.substr(pos + 1));
		}
		catch (std::exception &e) {
			file.close();
			throw std::runtime_error("parseDataFile()" + std::string(e.what()));
		}
		_data[date] = value;
	}
	file.close();
}

float	BitcoinExchange::getRateForDate(const std::string &date)
{
	auto it = _data.lower_bound(date);
	if (it->first == date){
		return it->second;
	}
	if (it == _data.begin()) {
		return 0;
	}
	return std::prev(it)->second; // either date is in the future or no exact match otherwise: closest date in past
}

void	BitcoinExchange::validateInputAndCout(char *input)
{
	// get_time, mktime, lower_bound
	std::ifstream file(input);
	if (!file) {
		throw std::runtime_error("opening " + std::string(input));
	}
	std::string	line;
	std::string	date;
	float		value;
	
	while (std::getline(file, line)){
		if (!line.empty()){
			break ;
		}
	}
	if (line != "date | value") {
		file.close();
		throw std::runtime_error("invalid header at " + std::string(input));
	}
	while (std::getline(file, line))
	{
		std::istringstream iss;
		if (line.empty()) {
			continue;
		}
		iss.str(line);
		iss >> date;
		std::string	bar;
		iss >> bar;
		// std::cout << "bar: " << bar << std::endl;
		// std::cout << "value: " << value << std::endl;
		if (!isValidDate(date) || bar != "|") {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		iss >> value;
		if (iss.fail()) {
			std::cout << "Error: not a valid number.\n";
			continue;
		}
		if (value < 0) {
			std::cout << "Error: not a positive number.\n";
			continue;
		}
		if (value > 1000) {
			std::cout << "Error: too big a number.\n";
			continue;
		}
		float rate = getRateForDate(date);
		std::cout << date << " => " <<  value << " = " << value * rate << std::endl;
	}
}