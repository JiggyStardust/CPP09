/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:12:38 by sniemela          #+#    #+#             */
/*   Updated: 2025/08/25 12:25:46 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& orig) : _vec(orig._vec) {}

PmergeMe& PmergeMe::operator = (const PmergeMe& orig) {
	if (this != &orig) {
		this->_vec = orig._vec;
	}
	return (*this);
}

void PmergeMe::createVec(char **av)
{
	int	n;
	for (int i = 1; av[i] != NULL; i++){
		std::string num;
		for (int j = 0; av[i][j] != '\0'; j++){
			num += av[i][j];
		}
		// std::cout << "num: " << num << std::endl;
		n = std::stoi(num);
		if (n < 0){
			throw std::runtime_error("Invalid argumment: negative number");
		}
		_vec.push_back(n);
	}
}

void PmergeMe::createDeq(char **av)
{
	int	n;
	for (int i = 1; av[i] != NULL; i++){
		std::string num;
		for (int j = 0; av[i][j] != '\0'; j++){
			num += av[i][j];
		}
		// std::cout << "num: " << num << std::endl;
		n = std::stoi(num);
		if (n < 0){
			throw std::runtime_error("Invalid argumment: negative number");
		}
		_deq.push_back(n);
	}
}

void PmergeMe::sortVec()
{
	
}

void PmergeMe::printVec(){
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDeq(){
	for (std::deque<int>::iterator it = _deq.begin(); it != _deq.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}