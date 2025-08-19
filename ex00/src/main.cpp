/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:23:11 by sniemela          #+#    #+#             */
/*   Updated: 2025/08/19 11:51:24 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		// (void)av;
		btc.validateInputAndCout(av[1]);
		// std::cout << "size of data map: " << btc.getMap().size() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}