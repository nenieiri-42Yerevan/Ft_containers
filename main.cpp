/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:20:25 by vismaily          #+#    #+#             */
/*   Updated: 2022/08/23 19:25:35 by vismaily         ###   ########.fr       */
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
	/* Example for constructor without parametrs with double*/
	/* Exaple for size and capacity with int*/

	std::vector<int>	vec;
	std::cout << COLOR_PURPLE_B << "Example 1" << COLOR_END << std::endl;;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size() << '.';
	std::cout << COLOR_END << std::endl;

	ft::vector<int>		ft_vec;
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size() << '.' << std::endl;
	std::cout << COLOR_END << std::endl;
}

void	example2()
{
	/* Example 2 */
	/* Example for constructor with 2 parametrs with double*/
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
	/* Example for const operator[] and for function at() with float*/

	const std::vector<float> vec(10, double(-60));
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

	const ft::vector<float> ft_vec(10, double(-60));
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
	/* Example for front() and back() functions*/

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
	/* Example for max_size() */

	std::vector<long double> vec(5, (long double)(41));
	std::cout << COLOR_PURPLE_B << "Example 6" << COLOR_END << std::endl;;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", max_size: " << vec.max_size() << '.';
	std::cout << COLOR_END << std::endl;

	ft::vector<long double> ft_vec(5, (long double)(41));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", max_size: " << ft_vec.max_size() << '.';
	std::cout << COLOR_END << std::endl;
}

int	main()
{
	example1();
	example2();
	example3();
	example4();
	example5();
	example6();

	return (0);
}
