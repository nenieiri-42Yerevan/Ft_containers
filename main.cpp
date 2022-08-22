/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:20:25 by vismaily          #+#    #+#             */
/*   Updated: 2022/08/22 20:00:48 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"

int	main()
{
	std::vector<int>	vec1;
	std::cout << "std::vector -> capacity: " << vec1.capacity();
	std::cout << ", size: " << vec1.size() << '.' << std::endl;
	ft::vector<double>		ft_vec1;
	std::cout << "ft::vector  -> capacity: " << ft_vec1.capacity();
	std::cout << ", size: " << ft_vec1.size() << '.' << std::endl;
	std::cout << std::endl;

	std::vector<double> vec2(10, double(58));
	std::cout << "std::vector -> capacity: " << vec2.capacity();
	std::cout << ", size: " << vec2.size();
	std::cout << ", value[8]: " << vec2[8] << '.' << std::endl;
	ft::vector<double> ft_vec2(10, double(58));
	std::cout << "ft::vector  -> capacity: " << ft_vec2.capacity();
	std::cout << ", size: " << ft_vec2.size();
	//std::cout << ", value[8]: " << ft_vec2[8] << '.' << std::endl;
	std::cout << std::endl;
	return (0);
}
