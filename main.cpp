/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:20:25 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/12 19:59:53 by vismaily         ###   ########.fr       */
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

int	barev()
{
	ft::binary_search_tree<int, true>	tree1;
	tree1.tree_insert(42);
	tree1.tree_insert(42);
	tree1.tree_insert(42);
	tree1.tree_insert(42);
	tree1.tree_insert(42);
	tree1.print_tree();

	std::cout << std::endl;
	tree1.print_tree();
	return (0);
}

int	main()
{
//	vector_test();
//	stack_test();
//	map_test();
	barev();
}
