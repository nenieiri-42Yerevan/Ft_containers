/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:20:25 by vismaily          #+#    #+#             */
/*   Updated: 2022/08/23 14:01:26 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <vector>
#include <exception>
#include "vector.hpp"
#include "MyColors.hpp"

int	main()
{
	/* Example for constructor without parametrs with double*/
	/* Exaple for size and capacity with int*/
	std::vector<int>	vec1;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec1.capacity();
	std::cout << ", size: " << vec1.size() << '.';
	std::cout << COLOR_END << std::endl;
	ft::vector<int>		ft_vec1;
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec1.capacity();
	std::cout << ", size: " << ft_vec1.size() << '.' << std::endl;
	std::cout << COLOR_END << std::endl;

	/* Example for constructor with 2 parametrs with double*/
	/* Example for operator[] */
	std::vector<double> vec2(10, double(58));
	std::cout << std::fixed << std::setprecision(2) << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec2.capacity();
	std::cout << ", size: " << vec2.size();
	std::cout << ", value[8]: " << vec2[8] << '.';
	std::cout << COLOR_END << std::endl;
	ft::vector<double> ft_vec2(10, double(58));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec2.capacity();
	std::cout << ", size: " << ft_vec2.size();
	std::cout << ", value[8]: " << ft_vec2[8] << '.' << std::endl;
	std::cout << COLOR_END << std::endl;

	/* Example for const operator[] and for function at() */
	const std::vector<float> vec3(10, double(-60));
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::vector -> capacity: " << vec3.capacity();
	std::cout << ", size: " << vec3.size();
	std::cout << ", value[8]: " << vec3[8];
	std::cout << ", at(3): " << vec3.at(3);
	try
	{
		std::cout << ", at(10): " << vec3.at(10) << '.';
	}
	catch (const std::exception &e)
	{
		std::cout << "Out of range" << std::endl;
	}
	std::cout << COLOR_END << std::endl;
	const ft::vector<float> ft_vec3(10, double(-60));
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::vector  -> capacity: " << ft_vec3.capacity();
	std::cout << ", size: " << ft_vec3.size();
	std::cout << ", value[8]: " << ft_vec3[8];
//	std::cout << ", at(3): " << ft_vec3.at(3)
/*	try
	{
		std::cout << ", at(10): " << ft_vec3.at(10) << '.';
	}
	catch (const std::exception &e)
	{
		std::cout << "Out of range" << std::endl;
	}
*/	std::cout << COLOR_END << std::endl;
	return (0);
}
