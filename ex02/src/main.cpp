/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:13:05 by sniemela          #+#    #+#             */
/*   Updated: 2025/08/25 12:37:52 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int	main(int ac, char **av){
	std::string nums;
	if (ac < 3) {
		std::cerr << "Usage: ./PmergeMe 'positive integers (range: 2-3000 units)'";
		return 1;
	}
	PmergeMe pmm;

	auto startCreateVec = std::chrono::high_resolution_clock::now();
	try {
		pmm.createVec(av);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what();
		return 1;
	}
	auto finishCreateVec = std::chrono::high_resolution_clock::now();

	
	auto startCreateDeq = std::chrono::high_resolution_clock::now();
	try {
		pmm.createDeq(av);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what();
		return 1;
	}
	auto finishCreateDeq = std::chrono::high_resolution_clock::now();
	auto durationCreateVec = std::chrono::duration_cast<std::chrono::microseconds>(finishCreateVec - startCreateVec);
	auto durationCreateDeq = std::chrono::duration_cast<std::chrono::microseconds>(finishCreateDeq - startCreateDeq);
	std::cout << "Before: "; 
	pmm.sortVec();
	pmm.printDeq();
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector<int> : "
		<< durationCreateVec.count() << " us" << std::endl;

	std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque<int> : "
		<< durationCreateDeq.count() << " us" << std::endl;
	return 0;
}