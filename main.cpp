/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:20:25 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/09 17:17:05 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Containers/vector.hpp"
#include "Containers/stack.hpp"
#include "Other/binary_search_tree.hpp"
#include <iostream>
#include <string>

void	vector_test();
void	stack_test();
void	map_test();

int	main()
{
//	vector_test();
//	stack_test();
//	map_test();
	ft::node<int>	n1;
	ft::node<int>	n2(42);
	ft::node<int>	n3(n2);

	std::cout << n1.data << std::endl;
	std::cout << n2.data << std::endl;
	std::cout << n3.data << std::endl;
	n1 = n2;
	std::cout << n1.data << std::endl;

	ft::binary_search_tree<int>	tree1;
	ft::binary_search_tree<std::string>	tree2;

	tree1.inorder_tree_walk();

	return (0);
}
