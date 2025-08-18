#include "../inc/BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "run with ./btc path/to/input_file" << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange btc;
		btc.parseDataFile();
		btc.validateAndCout(av[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}