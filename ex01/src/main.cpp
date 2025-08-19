/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:42:48 by sniemela          #+#    #+#             */
/*   Updated: 2025/08/19 15:04:10 by sniemela         ###   ########.fr       */
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
		rpn.parseInput(std::string(av[1]));
	}
	catch (std::exception &e) {

	}
	(void)av;
	return (0);
}