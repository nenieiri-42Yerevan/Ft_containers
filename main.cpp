/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:20:25 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/10 17:50:55 by vismaily         ###   ########.fr       */
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
	ft::node<int>	*n1 = new ft::node<int>(42);
	ft::node<int>	*n2 = new ft::node<int>(88);

	ft::binary_search_tree<int>	tree1(n1);
	tree1.tree_insert(n2);
	tree1.tree_insert(89);
	tree1.tree_insert(56);
	tree1.tree_insert(-5656);
	tree1.tree_insert(-56);
	tree1.tree_insert(0);
	tree1.tree_insert(1);
	tree1.reverse_inorder_tree_walk();
	std::cout << std::endl;
	tree1.reverse_preorder_tree_walk();
	std::cout << std::endl;
	tree1.reverse_postorder_tree_walk();
	std::cout << std::endl;

	return (0);
}
