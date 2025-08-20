/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaraniemela <saaraniemela@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:42:48 by sniemela          #+#    #+#             */
/*   Updated: 2025/08/20 12:47:49 by saaraniemel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2){
		std::cerr << "Usage: ./RPN \"number(s) operand(s) number(s)... operand(s)\"\n";
		return 1;
	}
	try {
		RPN rpn;
		rpn.validateInput(std::string(av[1]));
		// std::cout << "trying to calculate\n";
		rpn.calculate(std::string(av[1]));
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}