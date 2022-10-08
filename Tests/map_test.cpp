/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:41:32 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/08 14:21:31 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <utility>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <functional>
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
	std::cout << "std::map -> ";
	std::cout << (it1 == it2);
	A.insert(std::make_pair(0, "0A"));
	A.insert(std::make_pair(-2, "-2B"));
	std::cout << ", size: " << A.size();
	A.insert(std::make_pair(2, "2C"));
	A.insert(std::make_pair(-1, "-1D"));
	A.insert(std::make_pair(-3, "-3E"));
	A.insert(std::make_pair(1, "1F"));
	A.insert(std::make_pair(3, "3J"));
	std::cout << ", size: " << A.size();
	it1 = A.begin();
	it2 = A.end();
	std::cout << ", it: " << (it1 == it2);
	std::cout << ", " << it1->first;
	std::cout << ", " << (--it2)->second;
	std::cout << ", " << (it2--)->second;
	std::cout << ", " << it2->second;
	it2->second = "hello";
	it2 = A.end();
	std::cout << ", loop:";
	while (it1 != it2)
		std::cout << " " << (it1++)->second;
	std::cout << '.' << COLOR_END << std::endl;

	ft::map<int, std::string> ft_A;
	ft::map<int, std::string>::iterator ft_it1;
	ft::map<int, std::string>::iterator ft_it2;
	ft_it1 = ft_A.begin();
	ft_it2 = ft_A.end();
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::map  -> ";
	std::cout << (ft_it1 == ft_it2);
	ft_A.insert(ft::make_pair(0, "0A"));
	ft_A.insert(ft::make_pair(-2, "-2B"));
	std::cout << ", size: " << ft_A.size();
	ft_A.insert(ft::make_pair(2, "2C"));
	ft_A.insert(ft::make_pair(-1, "-1D"));
	ft_A.insert(ft::make_pair(-3, "-3E"));
	ft_A.insert(ft::make_pair(1, "1F"));
	ft_A.insert(ft::make_pair(3, "3J"));
	std::cout << ", size: " << ft_A.size();
	ft_it1 = ft_A.begin();
	ft_it2 = ft_A.end();
	std::cout << ", it: " << (ft_it1 == ft_it2);
	std::cout << ", " << ft_it1->first;
	std::cout << ", " << (--ft_it2)->second;
	std::cout << ", " << (ft_it2--)->second;
	std::cout << ", " << ft_it2->second;
	ft_it2->second = "hello";
	ft_it2 = ft_A.end();
	std::cout << ", loop:";
	while (ft_it1 != ft_it2)
		std::cout << " " << (ft_it1++)->second;
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example4()
{
	/* Example 4 */
	/* Example for const iterators */

	std::map<int, std::string> A;
	std::map<int, std::string>::const_iterator it1;
	std::map<int, std::string>::const_iterator it2;
	it1 = A.begin();
	it2 = A.end();
	std::cout << COLOR_PURPLE_B << "Example 4" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::map -> ";
	std::cout << (it1 == it2);
	A.insert(std::make_pair(0, "0A"));
	A.insert(std::make_pair(-2, "-2B"));
	std::cout << ", size: " << A.size();
	A.insert(std::make_pair(2, "2C"));
	A.insert(std::make_pair(-1, "-1D"));
	A.insert(std::make_pair(-3, "-3E"));
	A.insert(std::make_pair(1, "1F"));
	A.insert(std::make_pair(3, "3J"));
	std::cout << ", size: " << A.size();
	it1 = A.begin();
	it2 = A.end();
	std::cout << ", it: " << (it1 == it2);
	std::cout << ", " << it1->first;
	std::cout << ", " << (--it2)->second;
	std::cout << ", " << (it2--)->second;
	std::cout << ", " << it2->second;
	it2 = A.end();
	std::cout << ", loop:";
	while (it1 != it2)
		std::cout << " " << (it1++)->second;
	it1 = A.begin();
	std::cout << ", loop:";
	while (it1 != it2)
		std::cout << " " << (--it2)->second;
	std::cout << '.' << COLOR_END << std::endl;

	ft::map<int, std::string> ft_A;
	ft::map<int, std::string>::const_iterator ft_it1;
	ft::map<int, std::string>::const_iterator ft_it2;
	ft_it1 = ft_A.begin();
	ft_it2 = ft_A.end();
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::map  -> ";
	std::cout << (ft_it1 == ft_it2);
	ft_A.insert(ft::make_pair(0, "0A"));
	ft_A.insert(ft::make_pair(-2, "-2B"));
	std::cout << ", size: " << ft_A.size();
	ft_A.insert(ft::make_pair(2, "2C"));
	ft_A.insert(ft::make_pair(-1, "-1D"));
	ft_A.insert(ft::make_pair(-3, "-3E"));
	ft_A.insert(ft::make_pair(1, "1F"));
	ft_A.insert(ft::make_pair(3, "3J"));
	std::cout << ", size: " << ft_A.size();
	ft_it1 = ft_A.begin();
	ft_it2 = ft_A.end();
	std::cout << ", it: " << (ft_it1 == ft_it2);
	std::cout << ", " << ft_it1->first;
	std::cout << ", " << (--ft_it2)->second;
	std::cout << ", " << (ft_it2--)->second;
	std::cout << ", " << ft_it2->second;
	ft_it2 = ft_A.end();
	std::cout << ", loop:";
	while (ft_it1 != ft_it2)
		std::cout << " " << (ft_it1++)->second;
	ft_it1 = ft_A.begin();
	std::cout << ", loop:";
	while (ft_it1 != ft_it2)
		std::cout << " " << (--ft_it2)->second;
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example5()
{
	/* Example 5 */
	/* Example for iterators comparison */

	std::map<int, std::string>				tree;
	std::map<int, std::string>::iterator	it1;
	std::map<int, std::string>::iterator	it2;
	std::cout << COLOR_PURPLE_B << "Example 5" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::map ->";
	tree.insert(std::make_pair(0, "0A"));
	tree.insert(std::make_pair(-2, "-2B"));
	tree.insert(std::make_pair(2, "2C"));
	tree.insert(std::make_pair(-1, "-1D"));
	tree.insert(std::make_pair(-3, "-3E"));
	tree.insert(std::make_pair(1, "1F"));
	tree.insert(std::make_pair(3, "3J"));
	it1 = tree.begin();
	it2 = tree.begin();
	++it2;
	++it2;
	std::cout << " ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	it1 = it2;
	std::cout << ", ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	++it1;
	std::cout << ", ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	std::cout << '.' << COLOR_END << std::endl;

	ft::map<int, std::string>			ft_tree;
	ft::map<int, std::string>::iterator	ft_it1;
	ft::map<int, std::string>::iterator	ft_it2;
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::map  ->";
	ft_tree.insert(ft::make_pair(0, "0A"));
	ft_tree.insert(ft::make_pair(-2, "-2B"));
	ft_tree.insert(ft::make_pair(2, "2C"));
	ft_tree.insert(ft::make_pair(-1, "-1D"));
	ft_tree.insert(ft::make_pair(-3, "-3E"));
	ft_tree.insert(ft::make_pair(1, "1F"));
	ft_tree.insert(ft::make_pair(3, "3J"));
	ft_it1 = ft_tree.begin();
	ft_it2 = ft_tree.begin();
	++ft_it2;
	++ft_it2;
	std::cout << " ==: " << (ft_it2 == ft_it1);
	std::cout << ", !=: " << (ft_it2 != ft_it1);
	ft_it1 = ft_it2;
	std::cout << ", ==: " << (ft_it2 == ft_it1);
	std::cout << ", !=: " << (ft_it2 != ft_it1);
	++ft_it1;
	std::cout << ", ==: " << (ft_it2 == ft_it1);
	std::cout << ", !=: " << (ft_it2 != ft_it1);
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example6()
{
	/* Example 6 */
	/* Example for const iterators comparison */

	std::map<int, std::string>					tree;
	std::map<int, std::string>::const_iterator	it1;
	std::map<int, std::string>::const_iterator	it2;
	std::cout << COLOR_PURPLE_B << "Example 6" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::map ->";
	tree.insert(std::make_pair(0, "0A"));
	tree.insert(std::make_pair(-2, "-2B"));
	tree.insert(std::make_pair(2, "2C"));
	tree.insert(std::make_pair(-1, "-1D"));
	tree.insert(std::make_pair(-3, "-3E"));
	tree.insert(std::make_pair(1, "1F"));
	tree.insert(std::make_pair(3, "3J"));
	it1 = tree.begin();
	it2 = tree.begin();
	++it2;
	++it2;
	std::cout << " ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	it1 = it2;
	std::cout << ", ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	++it1;
	std::cout << ", ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	std::cout << '.' << COLOR_END << std::endl;

	ft::map<int, std::string>					ft_tree;
	ft::map<int, std::string>::const_iterator	ft_it1;
	ft::map<int, std::string>::const_iterator	ft_it2;
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::map  ->";
	ft_tree.insert(ft::make_pair(0, "0A"));
	ft_tree.insert(ft::make_pair(-2, "-2B"));
	ft_tree.insert(ft::make_pair(2, "2C"));
	ft_tree.insert(ft::make_pair(-1, "-1D"));
	ft_tree.insert(ft::make_pair(-3, "-3E"));
	ft_tree.insert(ft::make_pair(1, "1F"));
	ft_tree.insert(ft::make_pair(3, "3J"));
	ft_it1 = ft_tree.begin();
	ft_it2 = ft_tree.begin();
	++ft_it2;
	++ft_it2;
	std::cout << " ==: " << (ft_it2 == ft_it1);
	std::cout << ", !=: " << (ft_it2 != ft_it1);
	ft_it1 = ft_it2;
	std::cout << ", ==: " << (ft_it2 == ft_it1);
	std::cout << ", !=: " << (ft_it2 != ft_it1);
	++ft_it1;
	std::cout << ", ==: " << (ft_it2 == ft_it1);
	std::cout << ", !=: " << (ft_it2 != ft_it1);
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example7()
{
	/* Example 7 */
	/* Example for const and non-const iterators comparison */

	std::map<int, std::string>					tree;
	std::map<int, std::string>::iterator		it1;
	std::map<int, std::string>::const_iterator	it2;
	std::cout << COLOR_PURPLE_B << "Example 7" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::map ->";
	tree.insert(std::make_pair(0, "0A"));
	tree.insert(std::make_pair(-2, "-2B"));
	tree.insert(std::make_pair(2, "2C"));
	tree.insert(std::make_pair(-1, "-1D"));
	tree.insert(std::make_pair(-3, "-3E"));
	tree.insert(std::make_pair(1, "1F"));
	tree.insert(std::make_pair(3, "3J"));
	it1 = tree.begin();
	it2 = tree.begin();
	++it2;
	++it2;
	std::cout << " ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	++it1;
	++it1;
	std::cout << ", ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	++it1;
	std::cout << ", ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	std::cout << '.' << COLOR_END << std::endl;

	ft::map<int, std::string>					ft_tree;
	ft::map<int, std::string>::iterator			ft_it1;
	ft::map<int, std::string>::const_iterator	ft_it2;
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::map  ->";
	ft_tree.insert(ft::make_pair(0, "0A"));
	ft_tree.insert(ft::make_pair(-2, "-2B"));
	ft_tree.insert(ft::make_pair(2, "2C"));
	ft_tree.insert(ft::make_pair(-1, "-1D"));
	ft_tree.insert(ft::make_pair(-3, "-3E"));
	ft_tree.insert(ft::make_pair(1, "1F"));
	ft_tree.insert(ft::make_pair(3, "3J"));
	ft_it1 = ft_tree.begin();
	ft_it2 = ft_tree.begin();
	++ft_it2;
	++ft_it2;
	std::cout << " ==: " << (ft_it2 == ft_it1);
	std::cout << ", !=: " << (ft_it2 != ft_it1);
	++ft_it1;
	++ft_it1;
	std::cout << ", ==: " << (ft_it2 == ft_it1);
	std::cout << ", !=: " << (ft_it2 != ft_it1);
	++ft_it1;
	std::cout << ", ==: " << (ft_it2 == ft_it1);
	std::cout << ", !=: " << (ft_it2 != ft_it1);
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example8()
{
	/* Example 8 */
	/* Example for other compare function */

	std::map<int, std::string, std::greater<int> > A;
	std::map<int, std::string, std::greater<int> >::iterator it1;
	std::map<int, std::string, std::greater<int> >::iterator it2;
	it1 = A.begin();
	it2 = A.end();
	std::cout << COLOR_PURPLE_B << "Example 8" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::map -> ";
	std::cout << (it1 == it2);
	A.insert(std::make_pair(0, "0A"));
	A.insert(std::make_pair(-2, "-2B"));
	std::cout << " size: " << A.size();
	A.insert(std::make_pair(2, "2C"));
	A.insert(std::make_pair(-1, "-1D"));
	A.insert(std::make_pair(-3, "-3E"));
	A.insert(std::make_pair(1, "1F"));
	A.insert(std::make_pair(3, "3J"));
	std::cout << ", size: " << A.size();
	it1 = A.begin();
	it2 = A.end();
	std::cout << ", it: " << (it1 == it2);
	std::cout << ", " << it1->first;
	std::cout << ", " << (--it2)->second;
	std::cout << ", " << (it2--)->second;
	std::cout << ", " << it2->second;
	it2->second = "hello";
	it2 = A.end();
	std::cout << ", loop:";
	while (it1 != it2)
		std::cout << " " << (it1++)->second;
	std::cout << '.' << COLOR_END << std::endl;

	ft::map<int, std::string, std::greater<int> > ft_A;
	ft::map<int, std::string, std::greater<int> >::iterator ft_it1;
	ft::map<int, std::string, std::greater<int> >::iterator ft_it2;
	ft_it1 = ft_A.begin();
	ft_it2 = ft_A.end();
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::map  -> ";
	std::cout << (ft_it1 == ft_it2);
	ft_A.insert(ft::make_pair(0, "0A"));
	ft_A.insert(ft::make_pair(-2, "-2B"));
	std::cout << " size: " << ft_A.size();
	ft_A.insert(ft::make_pair(2, "2C"));
	ft_A.insert(ft::make_pair(-1, "-1D"));
	ft_A.insert(ft::make_pair(-3, "-3E"));
	ft_A.insert(ft::make_pair(1, "1F"));
	ft_A.insert(ft::make_pair(3, "3J"));
	std::cout << ", size: " << ft_A.size();
	ft_it1 = ft_A.begin();
	ft_it2 = ft_A.end();
	std::cout << ", it: " << (ft_it1 == ft_it2);
	std::cout << ", " << ft_it1->first;
	std::cout << ", " << (--ft_it2)->second;
	std::cout << ", " << (ft_it2--)->second;
	std::cout << ", " << ft_it2->second;
	ft_it2->second = "hello";
	ft_it2 = ft_A.end();
	std::cout << ", loop:";
	while (ft_it1 != ft_it2)
		std::cout << " " << (ft_it1++)->second;
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example9()
{
	/* Example 9 */
	/* Example for reverse iterator */

	std::map<int, std::string>						A;
	std::map<int, std::string>::reverse_iterator	it1;
	std::map<int, std::string>::reverse_iterator	it2;
	it1 = A.rbegin();
	it2 = A.rend();
	std::cout << COLOR_PURPLE_B << "Example 9" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::map -> ";
	std::cout << (it1 == it2);
	A.insert(std::make_pair(0, "0A"));
	A.insert(std::make_pair(-2, "-2B"));
	A.insert(std::make_pair(2, "2C"));
	A.insert(std::make_pair(-1, "-1D"));
	A.insert(std::make_pair(-3, "-3E"));
	A.insert(std::make_pair(1, "1F"));
	A.insert(std::make_pair(3, "3J"));
	it1 = A.rbegin();
	it2 = A.rend();
	std::cout << " it: " << (it1 == it2);
	std::cout << ", " << it1->first;
	std::cout << ", " << (--it2)->second;
	std::cout << ", " << (it2--)->second;
	std::cout << ", " << it2->second;
	it2->second = "hello";
	it2 = A.rend();
	std::cout << ", loop:";
	while (it1 != it2)
		std::cout << " " << (it1++)->second;
	std::cout << '.' << COLOR_END << std::endl;

	ft::map<int, std::string>					ft_A;
	ft::map<int, std::string>::reverse_iterator ft_it1;
	ft::map<int, std::string>::reverse_iterator ft_it2;
	ft_it1 = ft_A.rbegin();
	ft_it2 = ft_A.rend();
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::map  -> ";
	std::cout << (ft_it1 == ft_it2);
	ft_A.insert(ft::make_pair(0, "0A"));
	ft_A.insert(ft::make_pair(-2, "-2B"));
	ft_A.insert(ft::make_pair(2, "2C"));
	ft_A.insert(ft::make_pair(-1, "-1D"));
	ft_A.insert(ft::make_pair(-3, "-3E"));
	ft_A.insert(ft::make_pair(1, "1F"));
	ft_A.insert(ft::make_pair(3, "3J"));
	ft_it1 = ft_A.rbegin();
	ft_it2 = ft_A.rend();
	std::cout << " it: " << (ft_it1 == ft_it2);
	std::cout << ", " << ft_it1->first;
	std::cout << ", " << (--ft_it2)->second;
	std::cout << ", " << (ft_it2--)->second;
	std::cout << ", " << ft_it2->second;
	ft_it2->second = "hello";
	ft_it2 = ft_A.rend();
	std::cout << ", loop:";
	while (ft_it1 != ft_it2)
		std::cout << " " << (ft_it1++)->second;
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example10()
{
	/* Example 10 */
	/* Example for key and value compare */

	std::cout << COLOR_PURPLE_B << "Example 10" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::map<char, int>	A;
	A.insert(std::make_pair('x', 1001));
	A.insert(std::make_pair('y', 2002));
	A.insert(std::make_pair('z', 3003));
	std::pair<char, int> highest = *(A.rbegin());
	std::map<char, int>::iterator	it = A.begin();
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::map ->";
	do
	{
		std::cout << " " << it->first << " => " << it->second;
	} while (A.value_comp()(*it++, highest));
	std::map<char, int>::value_compare	cmp = A.value_comp();
	std::cout << " " << cmp(*A.begin(), *A.begin());
	std::cout << " " << cmp(*A.begin(), *(++A.begin()));
	std::map<char, int>::key_compare	key_cmp = A.key_comp();
	std::cout << " " << key_cmp('a', 'b');
	std::cout << " " << key_cmp('a', 'a');
	std::cout << '.' << COLOR_END << std::endl;

	std::cout << COLOR_GREEN_B;
	ft::map<char, int>	ft_A;
	ft_A.insert(ft::make_pair('x', 1001));
	ft_A.insert(ft::make_pair('y', 2002));
	ft_A.insert(ft::make_pair('z', 3003));
	ft::pair<char, int> ft_highest = *(ft_A.rbegin());
	ft::map<char, int>::iterator	ft_it = ft_A.begin();
	std::cout << "ft::map  ->";
	do
	{
		std::cout << " " << ft_it->first << " => " << ft_it->second;
	} while (ft_A.value_comp()(*ft_it++, ft_highest));
	ft::map<char, int>::value_compare	ft_cmp = ft_A.value_comp();
	std::cout << " " << ft_cmp(*ft_A.begin(), *ft_A.begin());
	std::cout << " " << ft_cmp(*ft_A.begin(), *(++ft_A.begin()));
	ft::map<char, int>::key_compare	ft_key_cmp = ft_A.key_comp();
	std::cout << " " << ft_key_cmp('a', 'b');
	std::cout << " " << ft_key_cmp('a', 'a');
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example11()
{
	/* Example 11 */
	/* Example for get_allocator */

	std::cout << COLOR_PURPLE_B << "Example 11" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::map<char, int>			A;
	std::pair<const char, int>	*p;
	p = A.get_allocator().allocate(42);
	A.get_allocator().deallocate(p, 42);
	std::cout << '.' << COLOR_END << std::endl;

	std::cout << COLOR_GREEN_B;
	ft::map<char, int>			ft_A;
	ft::pair<const char, int>	*ft_p;
	ft_p = ft_A.get_allocator().allocate(42);
	ft_A.get_allocator().deallocate(ft_p, 42);
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example12()
{
	/* Example 12 */
	/* Example for find */

	std::cout << COLOR_PURPLE_B << "Example 12" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::map<char, int>	A;
	A.insert(std::make_pair('d', 0));
	A.insert(std::make_pair('b', -2));
	A.insert(std::make_pair('f', 2));
	A.insert(std::make_pair('c', -1));
	A.insert(std::make_pair('e', 1));
	A.insert(std::make_pair('a', -3));
	A.insert(std::make_pair('j', 3));
	std::cout << "std::map -> ";
	std::cout << "find: " << A.find('e')->first;
	std::map<char, int>::const_iterator	it1 = A.find('a');
	std::map<char, int>::const_iterator	it2 = A.find('o');
	while (it1 != it2)
		std::cout << " " << (it1++)->first;
	std::cout << '.' << COLOR_END << std::endl;

	std::cout << COLOR_GREEN_B;
	ft::map<char, int>	ft_A;
	ft_A.insert(ft::make_pair('d', 0));
	ft_A.insert(ft::make_pair('b', -2));
	ft_A.insert(ft::make_pair('f', 2));
	ft_A.insert(ft::make_pair('c', -1));
	ft_A.insert(ft::make_pair('e', 1));
	ft_A.insert(ft::make_pair('a', -3));
	ft_A.insert(ft::make_pair('j', 3));
	std::cout << "ft::map  -> ";
	std::cout << "find: " << ft_A.find('e')->first;
	ft::map<char, int>::const_iterator	ft_it1 = ft_A.find('a');
	ft::map<char, int>::const_iterator	ft_it2 = ft_A.find('o');
	while (ft_it1 != ft_it2)
		std::cout << " " << (ft_it1++)->first;
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example13()
{
	/* Example 13 */
	/* Example for count */

	std::cout << COLOR_PURPLE_B << "Example 13" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::map<char, int>	A;
	A.insert(std::make_pair('d', 0));
	A.insert(std::make_pair('d', 0));
	A.insert(std::make_pair('b', -2));
	A.insert(std::make_pair('f', 2));
	A.insert(std::make_pair('c', -1));
	A.insert(std::make_pair('c', -1));
	A.insert(std::make_pair('c', -1));
	A.insert(std::make_pair('c', -1));
	A.insert(std::make_pair('e', 1));
	A.insert(std::make_pair('g', 3));
	std::cout << "std::map -> ";
	std::cout << "count:";
	for (char c = 'a'; c < 'k'; ++c)
		std::cout << " " << A.count(c);
	A.clear();
	std::cout << ", size " << A.size();
	std::cout << '.' << COLOR_END << std::endl;

	std::cout << COLOR_GREEN_B;
	ft::map<char, int>	ft_A;
	ft_A.insert(ft::make_pair('d', 0));
	ft_A.insert(ft::make_pair('d', 0));
	ft_A.insert(ft::make_pair('b', -2));
	ft_A.insert(ft::make_pair('f', 2));
	ft_A.insert(ft::make_pair('c', -1));
	ft_A.insert(ft::make_pair('c', -1));
	ft_A.insert(ft::make_pair('c', -1));
	ft_A.insert(ft::make_pair('c', -1));
	ft_A.insert(ft::make_pair('e', 1));
	ft_A.insert(ft::make_pair('g', 3));
	std::cout << "ft::map  -> ";
	std::cout << "count:";
	for (char c = 'a'; c < 'k'; ++c)
		std::cout << " " << ft_A.count(c);
	ft_A.clear();
	std::cout << ", size " << ft_A.size();
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example14()
{
	/* Example 14 */
	/* Example for bounds */

	std::cout << COLOR_PURPLE_B << "Example 14" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::map<char, int>	A;
	A.insert(std::make_pair('d', 0));
	A.insert(std::make_pair('b', -2));
	A.insert(std::make_pair('f', 2));
	A.insert(std::make_pair('c', -1));
	A.insert(std::make_pair('e', 1));
	A.insert(std::make_pair('a', -3));
	A.insert(std::make_pair('g', 3));
	std::cout << "std::map -> ";
	std::map<char, int>::iterator	itlow;
	std::map<char, int>::iterator	itup;
	itlow = A.lower_bound('c');
	itup = A.lower_bound('e');
	std::cout << "bound:";
	for (; itlow != itup; ++itlow)
		std::cout << " " << itlow->first;
	itlow = A.lower_bound('0');
	itup = A.lower_bound('e');
	std::cout << ", bound:";
	for (; itlow != itup; ++itlow)
		std::cout << " " << itlow->first;
	itlow = A.lower_bound('c');
	itup = A.lower_bound('x');
	std::cout << ", bound:";
	for (; itlow != itup; ++itlow)
		std::cout << " " << itlow->first;
	itlow = A.upper_bound('c');
	itup = A.upper_bound('e');
	std::cout << ", upper_bound:";
	for (; itlow != itup; ++itlow)
		std::cout << " " << itlow->first;
	itlow = A.upper_bound('0');
	itup = A.upper_bound('e');
	std::cout << ", bound:";
	for (; itlow != itup; ++itlow)
		std::cout << " " << itlow->first;
	itlow = A.upper_bound('c');
	itup = A.upper_bound('x');
	std::cout << ", bound:";
	for (; itlow != itup; ++itlow)
		std::cout << " " << itlow->first;
	itlow = A.lower_bound('b');
	itup = A.upper_bound('d');
	std::cout << ", up_low_bound:";
	for (; itlow != itup; ++itlow)
		std::cout << " " << itlow->first;
	A.clear();
	std::cout << ", size " << A.size();
	std::cout << '.' << COLOR_END << std::endl;

	std::cout << COLOR_GREEN_B;
	ft::map<char, int>	ft_A;
	ft_A.insert(ft::make_pair('d', 0));
	ft_A.insert(ft::make_pair('b', -2));
	ft_A.insert(ft::make_pair('f', 2));
	ft_A.insert(ft::make_pair('c', -1));
	ft_A.insert(ft::make_pair('e', 1));
	ft_A.insert(ft::make_pair('a', -3));
	ft_A.insert(ft::make_pair('g', 3));
	std::cout << "ft::map  -> ";
	ft::map<char, int>::iterator	ft_itlow;
	ft::map<char, int>::iterator	ft_itup;
	ft_itlow = ft_A.lower_bound('c');
	ft_itup = ft_A.lower_bound('e');
	std::cout << "bound:";
	for (; ft_itlow != ft_itup; ++ft_itlow)
		std::cout << " " << ft_itlow->first;
	ft_itlow = ft_A.lower_bound('0');
	ft_itup = ft_A.lower_bound('e');
	std::cout << ", bound:";
	for (; ft_itlow != ft_itup; ++ft_itlow)
		std::cout << " " << ft_itlow->first;
	ft_itlow = ft_A.lower_bound('c');
	ft_itup = ft_A.lower_bound('x');
	std::cout << ", bound:";
	for (; ft_itlow != ft_itup; ++ft_itlow)
		std::cout << " " << ft_itlow->first;
	ft_itlow = ft_A.upper_bound('c');
	ft_itup = ft_A.upper_bound('e');
	std::cout << ", upper_bound:";
	for (; ft_itlow != ft_itup; ++ft_itlow)
		std::cout << " " << ft_itlow->first;
	ft_itlow = ft_A.upper_bound('0');
	ft_itup = ft_A.upper_bound('e');
	std::cout << ", bound:";
	for (; ft_itlow != ft_itup; ++ft_itlow)
		std::cout << " " << ft_itlow->first;
	ft_itlow = ft_A.upper_bound('c');
	ft_itup = ft_A.upper_bound('x');
	std::cout << ", bound:";
	for (; ft_itlow != ft_itup; ++ft_itlow)
		std::cout << " " << ft_itlow->first;
	ft_itlow = ft_A.lower_bound('b');
	ft_itup = ft_A.upper_bound('d');
	std::cout << ", up_low_bound:";
	for (; ft_itlow != ft_itup; ++ft_itlow)
		std::cout << " " << ft_itlow->first;
	ft_A.clear();
	std::cout << ", size " << ft_A.size();
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example15()
{
	/* Example 15 */
	/* Example for inserts */

	std::cout << COLOR_PURPLE_B << "Example 15" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::map<int, int>	A;
	A.insert(std::make_pair(4, 0));
	A.insert(std::make_pair(2, -2));
	A.insert(std::make_pair(6, 2));
	A.insert(std::make_pair(3, -1));
	A.insert(std::make_pair(5, 1));
	A.insert(std::make_pair(1, -3));
	std::cout << "std::map -> ";
	std::cout << " size " << A.size();
	std::pair<std::map<int, int>::iterator, bool>	res;
	res = A.insert(std::make_pair(7, 3));
	std::cout << ", bool " << res.second;
	std::cout << ", val " << res.first->second;
	std::cout << ", size " << A.size();
	res = A.insert(std::pair<int, int>(6, 8));
	std::cout << ", bool " << res.second;
	std::cout << ", val " << res.first->second;
	std::cout << ", size " << A.size();
	std::map<int, int>	B;
	B.insert(std::pair<int, int>(1, 100));
	B.insert(std::pair<int, int>(-1, -100));
	B.insert(std::pair<int, int>(2, 200));
	std::map<int, int>::iterator	it5;
	it5 = B.insert(B.begin(), std::pair<int, int>(3, 300));
	std::cout << ", res " << it5->first;
	it5 = B.insert(B.begin(), std::pair<int, int>(3, 300));
	std::cout << ", res " << it5->first;
	it5 = B.insert(B.end(), std::pair<int, int>(-30, -3000));
	std::cout << ", res " << it5->first;
	it5 = B.insert(B.end(), std::pair<int, int>(-30, -3000));
	std::cout << ", res " << it5->first;
	it5 = B.insert(--B.end(), std::pair<int, int>(-2, -200));
	std::cout << ", res " << it5->first;
	it5 = B.insert(--B.end(), std::pair<int, int>(-2, -200));
	std::cout << ", res " << it5->first;
	it5 = B.insert(++(++B.begin()), std::pair<int, int>(-8, -800));
	std::cout << ", res " << it5->first;
	it5 = B.insert(++(++B.begin()), std::pair<int, int>(-8, -800));
	std::cout << ", res " << it5->first;
	it5 = B.insert(--(--(--B.end())), std::pair<int, int>(1000, 100000));
	std::cout << ", res " << it5->first;
	it5 = B.insert(--(--(--B.end())), std::pair<int, int>(1000, 100000));
	std::cout << ", res " << it5->first;
	it5 = B.insert(--(--(--B.end())), std::pair<int, int>(1000, 100000));
	std::cout << ", res " << it5->first << ",";
	for (std::map<int, int>::iterator it = B.begin(); it != B.end(); ++it)
		std::cout << " " << it->second;
	std::cout << ", size " << B.size();
	std::map<int, int>::iterator it10 = A.begin();
	std::map<int, int>::iterator it11 = A.end();
	B.insert(it10, it11);
	std::cout << ", insert_iters";
	for (std::map<int, int>::iterator it = B.begin(); it != B.end(); ++it)
		std::cout << " " << it->second;
	std::cout << ", size " << B.size();
	B.clear();
	std::cout << ", size " << B.size();
	std::cout << '.' << COLOR_END << std::endl;

	std::cout << COLOR_GREEN_B;
	ft::map<int, int>	ft_A;
	ft_A.insert(ft::make_pair(4, 0));
	ft_A.insert(ft::make_pair(2, -2));
	ft_A.insert(ft::make_pair(6, 2));
	ft_A.insert(ft::make_pair(3, -1));
	ft_A.insert(ft::make_pair(5, 1));
	ft_A.insert(ft::make_pair(1, -3));
	std::cout << "ft::map  -> ";
	std::cout << " size " << ft_A.size();
	ft::pair<ft::map<int, int>::iterator, bool>	ft_res;
	ft_res = ft_A.insert(ft::make_pair(7, 3));
	std::cout << ", bool " << ft_res.second;
	std::cout << ", val " << ft_res.first->second;
	std::cout << ", size " << ft_A.size();
	ft_res = ft_A.insert(ft::pair<int, int>(6, 8));
	std::cout << ", bool " << ft_res.second;
	std::cout << ", val " << ft_res.first->second;
	std::cout << ", size " << ft_A.size();
	ft::map<int, int>	ft_B;
	ft_B.insert(ft::pair<int, int>(1, 100));
	ft_B.insert(ft::pair<int, int>(-1, -100));
	ft_B.insert(ft::pair<int, int>(2, 200));
	ft::map<int, int>::iterator	ft_it5;
	ft_it5 = ft_B.insert(ft_B.begin(), ft::pair<int, int>(3, 300));
	std::cout << ", res " << ft_it5->first;
	ft_it5 = ft_B.insert(ft_B.begin(), ft::pair<int, int>(3, 300));
	std::cout << ", res " << ft_it5->first;
	ft_it5 = ft_B.insert(ft_B.end(), ft::pair<int, int>(-30, -3000));
	std::cout << ", res " << ft_it5->first;
	ft_it5 = ft_B.insert(ft_B.end(), ft::pair<int, int>(-30, -3000));
	std::cout << ", res " << ft_it5->first;
	ft_it5 = ft_B.insert(--ft_B.end(), ft::pair<int, int>(-2, -200));
	std::cout << ", res " << ft_it5->first;
	ft_it5 = ft_B.insert(--ft_B.end(), ft::pair<int, int>(-2, -200));
	std::cout << ", res " << ft_it5->first;
	ft_it5 = ft_B.insert(++(++ft_B.begin()), ft::pair<int, int>(-8, -800));
	std::cout << ", res " << ft_it5->first;
	ft_it5 = ft_B.insert(++(++ft_B.begin()), ft::pair<int, int>(-8, -800));
	std::cout << ", res " << ft_it5->first;
	ft_it5 = ft_B.insert(--(--(--ft_B.end())), ft::pair<int, int>(1000, 100000));
	std::cout << ", res " << ft_it5->first;
	ft_it5 = ft_B.insert(--(--(--ft_B.end())), ft::pair<int, int>(1000, 100000));
	std::cout << ", res " << ft_it5->first;
	ft_it5 = ft_B.insert(--(--(--ft_B.end())), ft::pair<int, int>(1000, 100000));
	std::cout << ", res " << ft_it5->first << ",";
	for (ft::map<int, int>::iterator ft_it = ft_B.begin(); ft_it != ft_B.end(); ++ft_it)
		std::cout << " " << ft_it->second;
	std::cout << ", size " << ft_B.size();
	ft::map<int, int>::iterator ft_it10 = ft_A.begin();
	ft::map<int, int>::iterator ft_it11 = ft_A.end();
	ft_B.insert(ft_it10, ft_it11);
	std::cout << ", insert_iters";
	for (ft::map<int, int>::iterator ft_it = ft_B.begin(); ft_it != ft_B.end(); ++ft_it)
		std::cout << " " << ft_it->second;
	std::cout << ", size " << ft_B.size();
	ft_B.clear();
	std::cout << ", size " << ft_B.size();
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example16()
{
	/* Example 16 */
	/* Example for erase */

	std::cout << COLOR_PURPLE_B << "Example 16" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::map<int, int>	A;
	A.insert(std::make_pair(0, 0));
	A.insert(std::make_pair(-2, -2));
	A.insert(std::make_pair(2, 2));
	A.insert(std::make_pair(-1, -1));
	A.insert(std::make_pair(1, 1));
	A.insert(std::make_pair(-3, -3));
	A.insert(std::make_pair(3, 3));
	A.insert(std::make_pair(-4, -4));
	A.insert(std::make_pair(4, 4));
	std::cout << "std::map -> ";
	std::cout << "size: " << A.size() << ", before_erase:";
	for (std::map<int, int>::iterator first = A.begin(); first != A.end(); ++first)
		std::cout << " " << first->second;
	std::map<int, int>::iterator	it1;
	std::map<int, int>::iterator	it2;
	it1 = A.find(-1);
	it2 = A.find(1);
	A.erase(it1, it2);
	std::cout << ", after_erase:";
	for (std::map<int, int>::iterator first = A.begin(); first != A.end(); ++first)
		std::cout << " " << first->second;
	std::cout << ", size: " << A.size() << ", after_erase:";
	A.erase(A.find(-2));
	A.erase(A.find(2));
	for (std::map<int, int>::iterator first = A.begin(); first != A.end(); ++first)
		std::cout << " " << first->second;
	std::cout << ", size: " << A.size() << ", after_erase:";
	A.erase(A.find(-3));
	A.erase(A.find(4));
	for (std::map<int, int>::iterator first = A.begin(); first != A.end(); ++first)
		std::cout << " " << first->second;
	std::cout << ", size: " << A.size();
	A.clear();
	std::cout << ", size: " << A.size();
	std::cout << '.' << COLOR_END << std::endl;

	std::cout << COLOR_GREEN_B;
	ft::map<int, int>	ft_A;
	ft_A.insert(ft::make_pair(0, 0));
	ft_A.insert(ft::make_pair(-2, -2));
	ft_A.insert(ft::make_pair(2, 2));
	ft_A.insert(ft::make_pair(-1, -1));
	ft_A.insert(ft::make_pair(1, 1));
	ft_A.insert(ft::make_pair(-3, -3));
	ft_A.insert(ft::make_pair(3, 3));
	ft_A.insert(ft::make_pair(-4, -4));
	ft_A.insert(ft::make_pair(4, 4));
	std::cout << "ft::map  -> ";
	std::cout << "size: " << ft_A.size() << ", before_erase:";
	for (ft::map<int, int>::iterator first = ft_A.begin(); first != ft_A.end(); ++first)
		std::cout << " " << first->second;
	ft::map<int, int>::iterator	ft_it1;
	ft::map<int, int>::iterator	ft_it2;
	ft_it1 = ft_A.find(-1);
	ft_it2 = ft_A.find(1);
	ft_A.erase(ft_it1, ft_it2);
	std::cout << ", after_erase:";
	for (ft::map<int, int>::iterator first = ft_A.begin(); first != ft_A.end(); ++first)
		std::cout << " " << first->second;
	std::cout << ", size: " << ft_A.size() << ", after_erase:";
	ft_A.erase(ft_A.find(-2));
	ft_A.erase(ft_A.find(2));
	for (ft::map<int, int>::iterator first = ft_A.begin(); first != ft_A.end(); ++first)
		std::cout << " " << first->second;
	std::cout << ", size: " << ft_A.size() << ", after_erase:";
	ft_A.erase(-3);
	ft_A.erase(4);
	for (ft::map<int, int>::iterator first = ft_A.begin(); first != ft_A.end(); ++first)
		std::cout << " " << first->second;
	std::cout << ", size: " << ft_A.size();
	ft_A.clear();
	std::cout << ", size: " << ft_A.size();
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example17()
{
	/* Example 17 */
	/* Example for equal_range and constructors*/

	std::cout << COLOR_PURPLE_B << "Example 17" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::map<int, int>	A;
	A.insert(std::make_pair(0, 0));
	A.insert(std::make_pair(-2, -2));
	A.insert(std::make_pair(2, 2));
	A.insert(std::make_pair(-1, -1));
	A.insert(std::make_pair(1, 1));
	A.insert(std::make_pair(-3, -3));
	A.insert(std::make_pair(3, 3));
	A.insert(std::make_pair(-4, -4));
	A.insert(std::make_pair(4, 4));
	std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator>	p;
	p = A.equal_range(-1);
	std::cout << "std::map -> ";
	std::cout << "lower " << p.first->first;
	std::cout << ", upper " << p.second->first;
	p = A.equal_range(-4);
	std::cout << ", lower " << p.first->first;
	std::cout << ", upper " << p.second->first;
	std::map<int, int>	B;
	B.insert(std::pair<int, int>(100, 10000));
	B.insert(std::pair<int, int>(-100, -10000));
	B.insert(std::pair<int, int>(200, 20000));
	std::map<int, int>::iterator	it5;
	it5 = B.insert(B.begin(), std::pair<int, int>(30, 3000));
	it5 = B.insert(B.end(), std::pair<int, int>(-300, -30000));
	std::cout << ", A:";
	for (std::map<int, int>::iterator f = A.begin(); f != A.end(); ++f)
		std::cout << " " << f->second;
	std::cout << ", B:";
	for (std::map<int, int>::iterator f = B.begin(); f != B.end(); ++f)
		std::cout << " " << f->second;
	A = B;
	std::cout << ", A_after=:";
	for (std::map<int, int>::iterator f = A.begin(); f != A.end(); ++f)
		std::cout << " " << f->second;
	std::map<int, int>	C;
	C.insert(std::make_pair(0, 0));
	C.insert(std::make_pair(-2, -2));
	A = C;
	std::cout << ", A_after=:";
	for (std::map<int, int>::iterator f = A.begin(); f != A.end(); ++f)
		std::cout << " " << f->second;
	std::map<int, int>	D(B.begin(), B.end());
	std::cout << ", D:";
	for (std::map<int, int>::iterator f = D.begin(); f != D.end(); ++f)
		std::cout << " " << f->second;
	std::cout << '.' << COLOR_END << std::endl;

	std::cout << COLOR_GREEN_B;
	ft::map<int, int>	ft_A;
	ft_A.insert(ft::make_pair(0, 0));
	ft_A.insert(ft::make_pair(-2, -2));
	ft_A.insert(ft::make_pair(2, 2));
	ft_A.insert(ft::make_pair(-1, -1));
	ft_A.insert(ft::make_pair(1, 1));
	ft_A.insert(ft::make_pair(-3, -3));
	ft_A.insert(ft::make_pair(3, 3));
	ft_A.insert(ft::make_pair(-4, -4));
	ft_A.insert(ft::make_pair(4, 4));
	ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator>	ft_p;
	ft_p = ft_A.equal_range(-1);
	std::cout << "ft::map  -> ";
	std::cout << "lower " << ft_p.first->first;
	std::cout << ", upper " << ft_p.second->first;
	ft_p = ft_A.equal_range(-4);
	std::cout << ", lower " << ft_p.first->first;
	std::cout << ", upper " << ft_p.second->first;
	ft::map<int, int>	ft_B;
	ft_B.insert(ft::pair<int, int>(100, 10000));
	ft_B.insert(ft::pair<int, int>(-100, -10000));
	ft_B.insert(ft::pair<int, int>(200, 20000));
	ft::map<int, int>::iterator	ft_it5;
	ft_it5 = ft_B.insert(ft_B.begin(), ft::pair<int, int>(30, 3000));
	ft_it5 = ft_B.insert(ft_B.end(), ft::pair<int, int>(-300, -30000));
	std::cout << ", A:";
	for (ft::map<int, int>::iterator f = ft_A.begin(); f != ft_A.end(); ++f)
		std::cout << " " << f->second;
	std::cout << ", B:";
	for (ft::map<int, int>::iterator f = ft_B.begin(); f != ft_B.end(); ++f)
		std::cout << " " << f->second;
	ft_A = ft_B;
	std::cout << ", A_after=:";
	for (ft::map<int, int>::iterator f = ft_A.begin(); f != ft_A.end(); ++f)
		std::cout << " " << f->second;
	ft::map<int, int>	ft_C;
	ft_C.insert(ft::make_pair(0, 0));
	ft_C.insert(ft::make_pair(-2, -2));
	ft_A = ft_C;
	std::cout << ", A_after=:";
	for (ft::map<int, int>::iterator f = ft_A.begin(); f != ft_A.end(); ++f)
		std::cout << " " << f->second;
	ft::map<int, int>	ft_D(ft_B.begin(), ft_B.end());
	std::cout << ", D:";
	for (ft::map<int, int>::iterator f = ft_D.begin(); f != ft_D.end(); ++f)
		std::cout << " " << f->second;
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example18()
{
	/* Example 18 */
	/* Example for swap */

	std::cout << COLOR_PURPLE_B << "Example 18" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::map<int, int>	A;
	A.insert(std::make_pair(0, 0));
	A.insert(std::make_pair(-2, -2));
	A.insert(std::make_pair(2, 2));
	A.insert(std::make_pair(-1, -1));
	A.insert(std::make_pair(1, 1));
	A.insert(std::make_pair(-3, -3));
	A.insert(std::make_pair(3, 3));
	std::map<int, int>	B;
	B.insert(std::pair<int, int>(100, 10000));
	B.insert(std::pair<int, int>(-100, -10000));
	B.insert(std::pair<int, int>(200, 20000));
	std::map<int, int>::iterator	it5;
	it5 = B.insert(B.begin(), std::pair<int, int>(30, 3000));
	it5 = B.insert(B.end(), std::pair<int, int>(-300, -30000));
	std::map<int, int>::iterator	it11 = A.begin();
	std::map<int, int>::iterator	it22 = B.begin();
	std::cout << "std::map -> ";
	std::cout << "A:";
	for (std::map<int, int>::iterator f = A.begin(); f != A.end(); ++f)
		std::cout << " " << f->second;
	std::cout << ", A_size: " << A.size();
	std::cout << ", B:";
	for (std::map<int, int>::iterator f = B.begin(); f != B.end(); ++f)
		std::cout << " " << f->second;
	std::cout << ", B_size: " << B.size();
	A.swap(B);
	std::cout << ", A_after=:";
	for (std::map<int, int>::iterator f = A.begin(); f != A.end(); ++f)
		std::cout << " " << f->second;
	std::cout << ", A_size: " << A.size();
	std::cout << ", B_after=:";
	for (std::map<int, int>::iterator f = B.begin(); f != B.end(); ++f)
		std::cout << " " << f->second;
	std::cout << ", B_size: " << B.size();
	std::cout << ", iter: " << (it11 == B.begin());
	std::cout << ", " << (it22 == A.begin());
	swap(A, B);
	std::cout << ", A_after=:";
	for (std::map<int, int>::iterator f = A.begin(); f != A.end(); ++f)
		std::cout << " " << f->second;
	std::cout << ", A_size: " << A.size();
	std::cout << ", B_after=:";
	for (std::map<int, int>::iterator f = B.begin(); f != B.end(); ++f)
		std::cout << " " << f->second;
	std::cout << ", B_size: " << B.size();
	std::cout << '.' << COLOR_END << std::endl;

	std::cout << COLOR_GREEN_B;
	ft::map<int, int>	ft_A;
	ft_A.insert(ft::make_pair(0, 0));
	ft_A.insert(ft::make_pair(-2, -2));
	ft_A.insert(ft::make_pair(2, 2));
	ft_A.insert(ft::make_pair(-1, -1));
	ft_A.insert(ft::make_pair(1, 1));
	ft_A.insert(ft::make_pair(-3, -3));
	ft_A.insert(ft::make_pair(3, 3));
	ft::map<int, int>	ft_B;
	ft_B.insert(ft::pair<int, int>(100, 10000));
	ft_B.insert(ft::pair<int, int>(-100, -10000));
	ft_B.insert(ft::pair<int, int>(200, 20000));
	ft::map<int, int>::iterator	ft_it5;
	ft_it5 = ft_B.insert(ft_B.begin(), ft::pair<int, int>(30, 3000));
	ft_it5 = ft_B.insert(ft_B.end(), ft::pair<int, int>(-300, -30000));
	ft::map<int, int>::iterator	ft_it11 = ft_A.begin();
	ft::map<int, int>::iterator	ft_it22 = ft_B.begin();
	std::cout << "ft::map  -> ";
	std::cout << "A:";
	for (ft::map<int, int>::iterator f = ft_A.begin(); f != ft_A.end(); ++f)
		std::cout << " " << f->second;
	std::cout << ", A_size: " << ft_A.size();
	std::cout << ", B:";
	for (ft::map<int, int>::iterator f = ft_B.begin(); f != ft_B.end(); ++f)
		std::cout << " " << f->second;
	std::cout << ", B_size: " << ft_B.size();
	ft_A.swap(ft_B);
	std::cout << ", A_after=:";
	for (ft::map<int, int>::iterator f = ft_A.begin(); f != ft_A.end(); ++f)
		std::cout << " " << f->second;
	std::cout << ", A_size: " << ft_A.size();
	std::cout << ", B_after=:";
	for (ft::map<int, int>::iterator f = ft_B.begin(); f != ft_B.end(); ++f)
		std::cout << " " << f->second;
	std::cout << ", B_size: " << ft_B.size();
	std::cout << ", iter: " << (ft_it11 == ft_B.begin());
	std::cout << ", " << (ft_it22 == ft_A.begin());
	swap(ft_A, ft_B);
	std::cout << ", A_after=:";
	for (ft::map<int, int>::iterator f = ft_A.begin(); f != ft_A.end(); ++f)
		std::cout << " " << f->second;
	std::cout << ", A_size: " << ft_A.size();
	std::cout << ", B_after=:";
	for (ft::map<int, int>::iterator f = ft_B.begin(); f != ft_B.end(); ++f)
		std::cout << " " << f->second;
	std::cout << ", B_size: " << ft_B.size();
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example19()
{
	/* Example 19 */
	/* Example for comparison functions */

	std::cout << COLOR_PURPLE_B << "Example 19" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::map<int, int>	A;
	A.insert(std::make_pair(0, 0));
	A.insert(std::make_pair(-2, -2));
	A.insert(std::make_pair(2, 2));
	std::map<int, int>	B;
	B.insert(std::pair<int, int>(0, 0));
	B.insert(std::pair<int, int>(-100, -10000));
	B.insert(std::pair<int, int>(200, 20000));
	std::map<int, int>	C;
	C.insert(std::make_pair(0, 0));
	C.insert(std::make_pair(-2, -2));
	C.insert(std::make_pair(2, 2));
	std::map<int, int>	D;
	D.insert(std::pair<int, int>(0, 0));
	D.insert(std::pair<int, int>(-1, 1));
	D.insert(std::pair<int, int>(200, -20000));
	std::cout << "std::map -> ";
	std::cout << "==: " << (A == B);
	std::cout << ", ==: " << (A == C);
	std::cout << ", ==: " << (A == D);
	std::cout << ", !=: " << (A != B);
	std::cout << ", !=: " << (A != C);
	std::cout << ", !=: " << (A != D);
	std::cout << ", <: " << (A < B);
	std::cout << ", <: " << (A < C);
	std::cout << ", <: " << (A < D);
	std::cout << ", <=: " << (A <= B);
	std::cout << ", <=: " << (A <= C);
	std::cout << ", <=: " << (A <= D);
	std::cout << ", >: " << (A > B);
	std::cout << ", >: " << (A > C);
	std::cout << ", >: " << (A > D);
	std::cout << ", >=: " << (A >= B);
	std::cout << ", >=: " << (A >= C);
	std::cout << ", >=: " << (A >= D);
	std::cout << '.' << COLOR_END << std::endl;

	std::cout << COLOR_GREEN_B;
	ft::map<int, int>	ft_A;
	ft_A.insert(ft::make_pair(0, 0));
	ft_A.insert(ft::make_pair(-2, -2));
	ft_A.insert(ft::make_pair(2, 2));
	ft::map<int, int>	ft_B;
	ft_B.insert(ft::pair<int, int>(0, 0));
	ft_B.insert(ft::pair<int, int>(100, 10000));
	ft_B.insert(ft::pair<int, int>(-200, -20000));
	ft::map<int, int>	ft_C;
	ft_C.insert(ft::make_pair(0, 0));
	ft_C.insert(ft::make_pair(-2, -2));
	ft_C.insert(ft::make_pair(2, 2));
	ft::map<int, int>	ft_D;
	ft_D.insert(ft::pair<int, int>(0, 0));
	ft_D.insert(ft::pair<int, int>(-1, -1));
	ft_D.insert(ft::pair<int, int>(200, 20000));
	std::cout << "ft::map  -> ";
	std::cout << "==: " << (ft_A == ft_B);
	std::cout << ", ==: " << (ft_A == ft_C);
	std::cout << ", ==: " << (ft_A == ft_D);
	std::cout << ", !=: " << (ft_A != ft_B);
	std::cout << ", !=: " << (ft_A != ft_C);
	std::cout << ", !=: " << (ft_A != ft_D);
	std::cout << ", <: " << (ft_A < ft_B);
	std::cout << ", <: " << (ft_A < ft_C);
	std::cout << ", <: " << (ft_A < ft_D);
	std::cout << ", <=: " << (ft_A <= ft_B);
	std::cout << ", <=: " << (ft_A <= ft_C);
	std::cout << ", <=: " << (ft_A <= ft_D);
	std::cout << ", >: " << (ft_A > ft_B);
	std::cout << ", >: " << (ft_A > ft_C);
	std::cout << ", >: " << (ft_A > ft_D);
	std::cout << ", >=: " << (ft_A >= ft_B);
	std::cout << ", >=: " << (ft_A >= ft_C);
	std::cout << ", >=: " << (ft_A >= ft_D);
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example20()
{
	/* Example 20 */
	/* Example for operator[] and at() */

	std::cout << COLOR_PURPLE_B << "Example 20" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::map<char, char>	A;
	A['a'] = 'A';
	A['b'] = 'B';
	A['c'] = A['b'];
	std::cout << "std::map -> ";
	std::cout << "[a]=" << A['a'];
	std::cout << ", [b]=" << A['b'];
	std::cout << ", [c]=" << A['c'];
	std::cout << ", [d]=" << A['d'];
	A.at('a') = 'a';
	A.at('b') = 'b';
	A.at('c') = 'c';
	std::cout << ", at(a)=" << A.at('a');
	std::cout << ", at(b)=" << A.at('b');
	std::cout << ", at(c)=" << A.at('c');
	try
	{
		A.at('t');
	}
	catch (const std::exception &e)
	{
		std::cout << " " << e.what();
	}
	std::cout << '.' << COLOR_END << std::endl;

	std::cout << COLOR_GREEN_B;
	ft::map<char, char>	ft_A;
	ft_A['a'] = 'A';
	ft_A['b'] = 'B';
	ft_A['c'] = ft_A['b'];
	std::cout << "ft::map  -> ";
	std::cout << "[a]=" << ft_A['a'];
	std::cout << ", [b]=" << ft_A['b'];
	std::cout << ", [c]=" << ft_A['c'];
	std::cout << ", [d]=" << ft_A['d'];
	ft_A.at('a') = 'a';
	ft_A.at('b') = 'b';
	ft_A.at('c') = 'c';
	std::cout << ", at(a)=" << ft_A.at('a');
	std::cout << ", at(b)=" << ft_A.at('b');
	std::cout << ", at(c)=" << ft_A.at('c');
	try
	{
		ft_A.at('t');
	}
	catch (const std::exception &e)
	{
		std::cout << " " << e.what();
	}
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example21()
{
	/* Example 21 */
	/* Example from mli-tester about erase */

	unsigned int lst_size = 6;

	std::cout << COLOR_PURPLE_B << "Example 21" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::list<std::pair<const int, std::string> > lst;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(std::make_pair(i, std::string((lst_size - i), i + 65)));
	std::map<const int, std::string> mp(lst.begin(), lst.end());
	std::cout << "std::map -> ";
	std::cout << "size: " << mp.size();
	std::cout << ", value:";
	for (std::map<const int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
		std::cout << " " << it->first;
	for (int i = 2; i < 4; ++i)
		mp.erase(i);
	std::cout << ", value:";
	for (std::map<const int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
		std::cout << " " << it->first;
	mp.erase(mp.begin()->first);
	mp.erase((--mp.end())->first);
	std::cout << ", value:";
	for (std::map<const int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
		std::cout << " " << it->first;
	mp[-1] = "Hello";
	mp[10] = "Hi there";
	mp[10] = "Hi there";
	std::cout << ", size: " << mp.size();
	mp.erase(0);
	mp.erase(1);
	std::cout << ", value:";
	for (std::map<const int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
		std::cout << " " << it->first;
	std::cout << '.' << COLOR_END << std::endl;

	std::list<ft::pair<const int, std::string> > ft_lst;
	for (unsigned int i = 0; i < lst_size; ++i)
		ft_lst.push_back(ft::make_pair(i, std::string((lst_size - i), i + 65)));
	std::cout << COLOR_GREEN_B;
	ft::map<const int, std::string> ft_mp(ft_lst.begin(), ft_lst.end());
	std::cout << "ft::map  -> ";
	std::cout << "size: " << ft_mp.size();
	std::cout << ", value:";
	for (ft::map<const int, std::string>::iterator it = ft_mp.begin(); it != ft_mp.end(); ++it)
		std::cout << " " << it->first;
	for (int i = 2; i < 4; ++i)
		ft_mp.erase(i);
	std::cout << ", value:";
	for (ft::map<const int, std::string>::iterator it = ft_mp.begin(); it != ft_mp.end(); ++it)
		std::cout << " " << it->first;
	ft_mp.erase(ft_mp.begin()->first);
	ft_mp.erase((--ft_mp.end())->first);
	std::cout << ", value:";
	for (ft::map<const int, std::string>::iterator it = ft_mp.begin(); it != ft_mp.end(); ++it)
		std::cout << " " << it->first;
	ft_mp[-1] = "Hello";
	ft_mp[10] = "Hi there";
	ft_mp[10] = "Hi there";
	std::cout << ", size: " << ft_mp.size();
	ft_mp.erase(0);
	ft_mp.erase(1);
	std::cout << ", value:";
	for (ft::map<const int, std::string>::iterator it = ft_mp.begin(); it != ft_mp.end(); ++it)
		std::cout << " " << it->first;
	std::cout << '.' << COLOR_END << std::endl << std::endl;
}

static void	example22()
{
	/* Example 22 */
	/* Example from bounds */

	std::cout << COLOR_PURPLE_B << "Example 22" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::map -> ";
    std::vector<int> v;
	std::map<int, int, std::greater<int> > mp2;
    mp2.insert(std::make_pair(20, 20));
    mp2.insert(std::make_pair(30, 30));
    mp2.insert(std::make_pair(40, 40));
    mp2.insert(std::make_pair(50, 50));
    mp2.insert(std::make_pair(60, 60));
	std::map<int, int>::iterator it;
    for (int i = 11; i < 70; i += 10) {
        it = mp2.upper_bound(i);
        v.push_back(it->first);
    }
	std::cout << "value:";
	for (std::vector<int>::iterator it1 = v.begin(); it1 != v.end(); ++it1)
		std::cout << " " << *it1;
	std::cout << '.' << COLOR_END << std::endl;

	std::cout << COLOR_GREEN_B;
	std::cout << "ft::map  -> ";
    std::vector<int> ft_v;
	ft::map<int, int, std::greater<int> > ft_mp2;
    ft_mp2.insert(ft::make_pair(20, 20));
    ft_mp2.insert(ft::make_pair(30, 30));
    ft_mp2.insert(ft::make_pair(40, 40));
    ft_mp2.insert(ft::make_pair(50, 50));
    ft_mp2.insert(ft::make_pair(60, 60));
	ft::map<int, int>::iterator ft_it;
    for (int i = 11; i < 70; i += 10) {
        ft_it = ft_mp2.upper_bound(i);
        ft_v.push_back(ft_it->first);
    }
	std::cout << "value:";
	for (std::vector<int>::iterator ft_it1 = ft_v.begin(); ft_it1 != ft_v.end(); ++ft_it1)
		std::cout << " " << *ft_it1;
	std::cout << '.' << COLOR_END << std::endl;
}

void	map_test()
{
	example1();
	example2();
	example3();
	example4();
	example5();
	example6();
	example7();
	example8();
	example9();
	example10();
	example11();
	example12();
	example13();
	example14();
	example15();
	example16();
	example17();
	example18();
	example19();
	example20();
	example21();
	example22();
}

#endif
