/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:41:32 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/17 18:52:00 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <utility>
#include <string>
#include <map>
#include "../Containers/map.hpp"

#ifndef	MYCOLORS_HPP
# define MYCOLORS_HPP

# define COLOR_YELLOW_B "\033[1;33m"
# define COLOR_PURPLE_B "\033[1;35m"
# define COLOR_BLUE_B "\033[1;34m"
# define COLOR_GREEN_B "\033[1;32m"
# define COLOR_GREEN "\033[0;32m"
# define COLOR_RED_B "\033[1;31m"
# define COLOR_END "\033[0m"

static void	example1()
{
	/* Example 1 */
	/* Example for pair and make_pair */

	std::pair<int, std::string>	pair1;
	std::cout << COLOR_PURPLE_B << "Example 1" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::pair -> first: " << pair1.first;
	std::cout << ", second: " << pair1.second;
	pair1 = std::make_pair(1, "Nenie_Iri");
	std::cout << ", first: " << pair1.first;
	std::cout << ", second: " << pair1.second;
	std::pair<int, std::string>	pair2(2, "HI");
	std::cout << ", first: " << pair2.first;
	std::cout << ", second: " << pair2.second;
	std::pair<int, std::string>	pair3(pair1);
	std::cout << ", first: " << pair3.first;
	std::cout << ", second: " << pair3.second;
	std::cout << ", first: " << std::make_pair(4, 5).first;
	std::cout << ", second: " << std::make_pair(4, 5).second;
	std::pair<int, int>	pair4(1, 5);
	std::pair<int, int>	pair5(1, 4);
	std::cout << ", ==: " << (pair1 == pair2);
	std::cout << ", ==: " << (pair1 == pair3);
	std::cout << ", ==: " << (pair4 == pair5);
	std::cout << ", !=: " << (pair1 != pair2);
	std::cout << ", !=: " << (pair1 != pair3);
	std::cout << ", !=: " << (pair4 != pair5);
	std::cout << ", <: " << (pair1 < pair2);
	std::cout << ", <: " << (pair1 < pair3);
	std::cout << ", <: " << (pair4 < pair5);
	std::cout << ", <=: " << (pair1 <= pair2);
	std::cout << ", <=: " << (pair1 <= pair3);
	std::cout << ", <=: " << (pair4 <= pair5);
	std::cout << ", >: " << (pair1 > pair2);
	std::cout << ", >: " << (pair1 > pair3);
	std::cout << ", >: " << (pair4 > pair5);
	std::cout << ", >=: " << (pair1 >= pair2);
	std::cout << ", >=: " << (pair1 >= pair3);
	std::cout << ", >=: " << (pair4 >= pair5);
	std::cout << '.' << COLOR_END << std::endl;

	ft::pair<int, std::string>	ft_pair1;
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::pair  -> first: " << ft_pair1.first;
	std::cout << ", second: " << ft_pair1.second;
	ft_pair1 = ft::make_pair(1, "Nenie_Iri");
	std::cout << ", first: " << ft_pair1.first;
	std::cout << ", second: " << ft_pair1.second;
	ft::pair<int, std::string>	ft_pair2(2, "HI");
	std::cout << ", first: " << ft_pair2.first;
	std::cout << ", second: " << ft_pair2.second;
	ft::pair<int, std::string>	ft_pair3(ft_pair1);
	std::cout << ", first: " << ft_pair3.first;
	std::cout << ", second: " << ft_pair3.second;
	std::cout << ", first: " << ft::make_pair(4, 5).first;
	std::cout << ", second: " << ft::make_pair(4, 5).second;
	ft::pair<int, int>	ft_pair4(1, 5);
	ft::pair<int, int>	ft_pair5(1, 4);
	std::cout << ", ==: " << (ft_pair1 == ft_pair2);
	std::cout << ", ==: " << (ft_pair1 == ft_pair3);
	std::cout << ", ==: " << (ft_pair4 == ft_pair5);
	std::cout << ", !=: " << (ft_pair1 != ft_pair2);
	std::cout << ", !=: " << (ft_pair1 != ft_pair3);
	std::cout << ", !=: " << (ft_pair4 != ft_pair5);
	std::cout << ", <: " << (ft_pair1 < ft_pair2);
	std::cout << ", <: " << (ft_pair1 < ft_pair3);
	std::cout << ", <: " << (ft_pair4 < ft_pair5);
	std::cout << ", <=: " << (ft_pair1 <= ft_pair2);
	std::cout << ", <=: " << (ft_pair1 <= ft_pair3);
	std::cout << ", <=: " << (ft_pair4 <= ft_pair5);
	std::cout << ", >: " << (ft_pair1 > ft_pair2);
	std::cout << ", >: " << (ft_pair1 > ft_pair3);
	std::cout << ", >: " << (ft_pair4 > ft_pair5);
	std::cout << ", >=: " << (ft_pair1 >= ft_pair2);
	std::cout << ", >=: " << (ft_pair1 >= ft_pair3);
	std::cout << ", >=: " << (ft_pair4 >= ft_pair5);
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example2()
{
	/* Example 2 */
	/* Example for map constructors, size, empty, max_size */
	/* Example for iterators */

	std::pair<int, std::string>	pair1;
	pair1.first = 0; 
	pair1.second = "A"; 
	std::map<int, std::string> A;
	std::map<int, std::string>::iterator it1;
	std::cout << COLOR_PURPLE_B << "Example 2" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::pair -> ";
	std::cout << "size: " << A.size();
	std::cout << ", empty: " << A.empty();
	std::cout << ", size: " << A.max_size();
	A.insert(pair1);
	std::cout << ", size: " << A.size();
	A.insert(std::make_pair(-1, "B"));
	std::cout << ", size: " << A.size();
	A.insert(std::make_pair(1, "C"));
	std::cout << ", pair -> first: " << pair1.first;
	std::cout << ", second: " << pair1.second;
	std::cout << ", size: " << A.size();
	std::cout << ", size: " << A.max_size();
	std::cout << ", empty: " << A.empty();
	it1 = A.begin();
	std::cout << ", it: " << (*it1).first;
	std::cout << ", " << it1->first;
	std::cout << ", " << it1->second;
	std::cout << ", " << (it1++)->first;
	std::cout << ", " << (++it1)->first;
	std::cout << ", " << (--it1)->second;
	std::cout << ", " << (it1--)->second;
	std::cout << ", " << it1->second;
	std::cout << '.' << COLOR_END << std::endl;

	ft::pair<int, std::string>	ft_pair1;
	ft_pair1.first = 0; 
	ft_pair1.second = "A"; 
	ft::map<int, std::string> ft_A;
	ft::map<int, std::string>::iterator ft_it1;
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::pair  -> ";
	std::cout << "size: " << ft_A.size();
	std::cout << ", empty: " << ft_A.empty();
	std::cout << ", size: " << ft_A.max_size();
	ft_A.insert(ft_pair1);
	std::cout << ", size: " << ft_A.size();
	ft_A.insert(ft::make_pair(-1, "B"));
	std::cout << ", size: " << ft_A.size();
	ft_A.insert(ft::make_pair(1, "C"));
	std::cout << ", pair -> first: " << ft_pair1.first;
	std::cout << ", second: " << ft_pair1.second;
	std::cout << ", size: " << ft_A.size();
	std::cout << ", size: " << ft_A.max_size();
	std::cout << ", empty: " << ft_A.empty();
	ft_it1 = ft_A.begin();
	std::cout << ", it: " << (*ft_it1).first;
	std::cout << ", " << ft_it1->first;
	std::cout << ", " << ft_it1->second;
	std::cout << ", " << (ft_it1++)->first;
	std::cout << ", " << (++ft_it1)->first;
	std::cout << ", " << (--ft_it1)->second;
	std::cout << ", " << (ft_it1--)->second;
	std::cout << ", " << ft_it1->second;
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example3()
{
	/* Example 3 */
	/* Example for iterators */

	std::map<int, std::string> A;
	std::map<int, std::string>::iterator it1;
	std::map<int, std::string>::iterator it2;
	it1 = A.begin();
	it2 = A.end();
	std::cout << COLOR_PURPLE_B << "Example 3" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std -> ";
	std::cout << (it1 == it2);
	A.insert(std::make_pair(0, "A"));
	A.insert(std::make_pair(-1, "B"));
	std::cout << ", size: " << A.size();
	A.insert(std::make_pair(1, "C"));
	std::cout << ", size: " << A.size();
	it1 = A.begin();
	it2 = A.end();
	std::cout << ", " << it1->first;
	std::cout << ", " << (it1 == it2);
	std::cout << ", " << (--it2)->second;
	std::cout << ", " << (it2--)->second;
	std::cout << ", " << it2->second;
	std::cout << '.' << COLOR_END << std::endl;

	ft::map<int, std::string> ft_A;
	ft::map<int, std::string>::iterator ft_it1;
	ft::map<int, std::string>::iterator ft_it2;
	ft_it1 = ft_A.begin();
	ft_it2 = ft_A.end();
	std::cout << COLOR_GREEN_B;
	std::cout << "ft  -> ";
	std::cout << (ft_it1 == ft_it2);
	ft_A.insert(ft::make_pair(0, "A"));
	ft_A.insert(ft::make_pair(-1, "B"));
	std::cout << ", size: " << ft_A.size();
	ft_A.insert(ft::make_pair(1, "C"));
	std::cout << ", size: " << ft_A.size();
	ft_it1 = ft_A.begin();
	ft_it2 = ft_A.end();
	std::cout << ", " << ft_it1->first;
	std::cout << ", " << (ft_it1 == ft_it2);
	std::cout << ", " << (--ft_it2)->second;
	std::cout << ", " << (ft_it2--)->second;
	std::cout << ", " << ft_it2->second;
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

void	map_test()
{
	example1();
	example2();
	example3();
}

#endif
