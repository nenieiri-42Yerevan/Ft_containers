/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:41:32 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/24 14:59:33 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <utility>
#include <string>
#include <map>
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
	std::cout << "std -> ";
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
	std::cout << "ft  -> ";
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
	std::cout << "std -> ";
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
	std::cout << "ft  -> ";
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
	std::cout << "std -> ";
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
	std::cout << "ft  -> ";
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
	std::cout << "std -> ";
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
	std::cout << "ft  -> ";
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
	std::cout << "std ->";
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
	std::cout << "ft  ->";
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
	itlow = A.lower_bound('c');
	itup = A.lower_bound('x');
	std::cout << " bound:";
	for (; itlow != itup; ++itlow)
		std::cout << " " << itlow->first;
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
	ft_itlow = ft_A.lower_bound('c');
	ft_itup = ft_A.lower_bound('x');
	std::cout << " bound:";
	for (; ft_itlow != ft_itup; ++ft_itlow)
		std::cout << " " << ft_itlow->first;
	std::cout << '.' << COLOR_END << std::endl << std::endl;
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
}

#endif
