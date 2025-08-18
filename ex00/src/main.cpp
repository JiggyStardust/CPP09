#include "../inc/BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "run with ./btc path/to/input_file" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange btc;
		
		// parsee file mapiksi
		// validoi/käsittele mapin rivit
	}
	return 0;
}