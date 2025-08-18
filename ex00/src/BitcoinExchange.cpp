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

void	BitcoinExchange::parseDataFile()
{
	std::ifstream file("data.csv");
	if (!file)
	{
		throw std::runtime_error("opening data.csv");
	}
	std::istringstream iss;
	std::string	line;
	std::string	date;
	float		value;

	std::getline(file, line);
	if (line != "date,exchange_rate")
	{
		throw std::runtime_error("data.csv missing valid header");
	}
	while (std::getline(file, line))
	{
		if (line.empty())
		{
			continue;
		}
		try 
		{
			validateDataLine(line);
		}
		catch (std::exception &e) 
		{
			throw std::runtime_error(e.what());
		}
		size_t pos = line.find(",");
		if (pos == std::string::npos)
		{
			throw std::runtime_error("data.csv wrong formatting");
		}
		date = line.substr(0, pos);
		std::cout << "Date: " << date << std::endl;
		// get_time, mktime to validate the date (leap years etc)
		
		
		
		
		try
		{
			value = stof(line.substr(pos + 1));
		}
		catch (std::exception &e)
		{
			throw std::runtime_error("parseDataFile()" + std::string(e.what()));
		}
	}
	// lower_bound later to match input date with data map
}

void	BitcoinExchange::validateAndCout(char *input)
{
	// get_time, mktime, lower_bound
	std::ifstream file(input);
	if (!file)
	{
		throw std::runtime_error("opening data.csv");
	}
	std::istringstream iss;
	std::string	line;
	std::string	date;
	float		value;
	while (std::getline(file, line))
	{
		if (line.empty())
		{
			continue;
		}
		iss.str(line);
		iss >> date;
		std::string	bar;
		iss >> bar;
		date += " " + bar;
		iss >> value;
	}
}