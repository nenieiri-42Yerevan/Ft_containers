/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:20:25 by vismaily          #+#    #+#             */
/*   Updated: 2022/08/24 18:31:27 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include "vector.hpp"
#include "MyColors.hpp"

void	example1()
{
	/* Example 1 */
	/* Example for constructor without parametrs */
	/* Exaple for size and capacity with int */
	/* Exaple for size and capacity with int */
	/* Exaple for push_back */

	std::vector<int>	vec;
	std::cout << COLOR_PURPLE_B << "Example 1" << COLOR_END << std::endl;;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	vec.push_back(42);
	std::cout << ", push_back[42] value[0]: " << vec[0];
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	vec.push_back(84);
	std::cout << ", push_back[84] value[1]: " << vec[1];
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	vec.push_back(168);
	std::cout << ", push_back[168] value[2]: " << vec.at(2);
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	vec.push_back(336);
	vec.push_back(672);
	std::cout << ", push_back[336],[672] value[3]: " << vec.at(3);
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size() << '.';
	std::cout << COLOR_END << std::endl;

	ft::vector<int>		ft_vec;
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	ft_vec.push_back(42);
	std::cout << ", push_back[42] value[0]: " << ft_vec[0];
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	ft_vec.push_back(84);
	std::cout << ", push_back[84] value[1]: " << ft_vec[1];
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	ft_vec.push_back(168);
	std::cout << ", push_back[168] value[2]: " << ft_vec.at(2);
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	ft_vec.push_back(336);
	ft_vec.push_back(672);
	std::cout << ", push_back[336],[672] value[3]: " << ft_vec.at(3);
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size() << '.' << std::endl;
	std::cout << COLOR_END << std::endl;
}

void	example2()
{
	/* Example 2 */
	/* Example for constructor with 2 parametrs with double */
	/* Example for operator[] */

	std::vector<double> vec(3, double(58));
	std::cout << COLOR_PURPLE_B << "Example 2" << COLOR_END << std::endl;;
	std::cout << std::fixed << std::setprecision(2) << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", value[2]: " << vec[2] << '.';
	std::cout << COLOR_END << std::endl;

	ft::vector<double> ft_vec(3, double(58));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", value[2]: " << ft_vec[2] << '.' << std::endl;
	std::cout << COLOR_END << std::endl;
}

void	example3()
{
	/* Example 3 */
	/* Example for const operator[] and for function at() with float */

	const std::vector<float> vec(10, float(-60));
	std::cout << COLOR_PURPLE_B << "Example 3" << COLOR_END << std::endl;;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> at(3): " << vec.at(3);
	try
	{
		std::cout << ", at(13): " << vec.at(13) << '.';
	}
	catch (const std::out_of_range &e)
	{
		std::cout << e.what() << '.';
	}
	std::cout << COLOR_END << std::endl;

	const ft::vector<float> ft_vec(10, float(-60));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector -> at(3): " << ft_vec.at(3);
	try
	{
		std::cout << ", at(13): " << ft_vec.at(13) << '.';
	}
	catch (const std::out_of_range &e)
	{
		std::cout << e.what() << '.';
	}
	std::cout << COLOR_END << std::endl << std::endl;
}

void	example4()
{
	/* Example 4 */
	/* Example for front() and back() functions */

	const std::vector<int> vec(3, double(58));
	std::cout << COLOR_PURPLE_B << "Example 4" << COLOR_END << std::endl;;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", value[0]: " << vec[0];
	std::cout << ", front(): " << vec.front();
	std::cout << ", value[2]: " << vec[0];
	std::cout << ", back(): " << vec.back() << '.';
	std::cout << COLOR_END << std::endl;

	const ft::vector<int> ft_vec(3, int(58));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", value[0]: " << ft_vec[0];
	std::cout << ", front(): " << ft_vec.front();
	std::cout << ", value[2]: " << ft_vec[0];
	std::cout << ", back(): " << ft_vec.back() << '.';
	std::cout << COLOR_END << std::endl << std::endl;
}

void	example5()
{
	/* Example 5 */
	/* Example for data() */

	int	*p;

	std::vector<int> vec(5, int(41));
	std::cout << COLOR_PURPLE_B << "Example 5" << COLOR_END << std::endl;;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	p = vec.data();
	std::cout << ", p[0]: " << p[0];
	std::cout << COLOR_END << std::endl;

	ft::vector<int> ft_vec(5, int(41));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	p = ft_vec.data();
	std::cout << ", p[0]: " << p[0];
	std::cout << COLOR_END << std::endl << std::endl;;
}

void	example6()
{
	/* Example 6 */
	/* Example for max_size() and get_allocator() */

	long double	*p;

	std::vector<long double> vec(5, (long double)(41));
	std::cout << COLOR_PURPLE_B << "Example 6" << COLOR_END << std::endl;;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", max_size: " << vec.max_size();

	p = vec.get_allocator().allocate(3);
	for (int i = 0; i < 3; ++i)
		vec.get_allocator().construct(&p[i], i);
	std::cout << ", allocated array:";
	for (int i = 0; i < 3; ++i)
		std::cout << ' ' << p[i];

	std::cout << '.' << COLOR_END << std::endl;

	ft::vector<long double> ft_vec(5, (long double)(41));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", max_size: " << ft_vec.max_size();

	p = ft_vec.get_allocator().allocate(3);
	for (int i = 0; i < 3; ++i)
		ft_vec.get_allocator().construct(&p[i], i);
	std::cout << ", allocated array:";
	for (int i = 0; i < 3; ++i)
		std::cout << ' ' << p[i];

	std::cout << '.' << COLOR_END << std::endl << std::endl;;
}

void	example7()
{
	/* Example 7 */
	/* Example for push_back() and pop_back() */

	std::vector<int> vec(5, (int)(42));
	std::cout << COLOR_PURPLE_B << "Example 7" << COLOR_END << std::endl;;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();

	for (size_t i = 50; i < 55; ++i)
		vec.push_back(i);
	vec.pop_back();
	vec.pop_back();
	std::cout << " values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << '.' << COLOR_END << std::endl;

	ft::vector<int> ft_vec(5, (int)(42));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();

	for (size_t i = 50; i < 55; ++i)
		ft_vec.push_back(i);
	ft_vec.pop_back();
	ft_vec.pop_back();
	std::cout << " values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	std::cout << '.' << COLOR_END << std::endl;
}

int	main()
{
	example1();
	example2();
	example3();
	example4();
	example5();
	example6();
	example7();

	return (0);
}
