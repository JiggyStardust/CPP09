/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:10:07 by sniemela          #+#    #+#             */
/*   Updated: 2025/08/25 12:39:16 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <chrono>
#include <deque>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

class PmergeMe {
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;
		static int		_comp_vec;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& orig);
		PmergeMe& operator = (const PmergeMe& orig);
		void	createVec(char **av);
		void	createDeq(char **av);
		void	printVec();
		void	printDeq();
		void	sortVec();
};