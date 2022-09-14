/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:20:25 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/14 14:27:20 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Containers/vector.hpp"
#include "Containers/stack.hpp"
#include "Other/binary_search_tree.hpp"
#include <iostream>
#include <map>
#include <string>

void	vector_test();
void	stack_test();
void	map_test();

int	barev()
{
	std::map<int, std::string> A;
	A.insert(std::make_pair(0, "A"));
	A.insert(std::make_pair(-2, "C"));
	A.insert(std::make_pair(2, "D"));
	A.insert(std::make_pair(-3, "E"));
	A.insert(std::make_pair(1, "G"));
//	A.insert(std::make_pair(-1, "F"));
	A.insert(std::make_pair(3, "H"));
	A.insert(std::make_pair(4, "H"));
	A.insert(std::make_pair(5, "H"));
	A.insert(std::make_pair(6, "H"));
	A.insert(std::make_pair(7, "H"));
	A.insert(std::make_pair(8, "H"));
	A.insert(std::make_pair(9, "H"));

	std::map<int, std::string>::iterator	it;

	it = A.begin();
	++it;
	++it;
	//++it;

	std::cout << it->first << std::endl;
	return (0);
}

int	main()
{
//	vector_test();
//	stack_test();
//	map_test();
	barev();
}
