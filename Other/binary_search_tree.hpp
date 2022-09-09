/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:30:35 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/09 17:11:37 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BINARY_SEARCH_TREE_HPP
# define FT_BINARY_SEARCH_TREE_HPP

# include <iostream>

namespace	ft
{
	/* Node */
	template <typename T>
	struct	node
	{
		node();
		node(const T &elem);
		node(const node &other);
		node		&operator=(const node &other);
		~node();

		T			data;
		node		*left;
		node		*right;
		node		*p;
	};

	/* Tree */
	template <typename T>
	class	binary_search_tree
	{
		/* Member types */
		public:
			typedef T		value_type;

		public:
			binary_search_tree();
			binary_search_tree(const binary_search_tree &other);
			binary_search_tree	&operator=(const binary_search_tree &other);
			~binary_search_tree();

		public:
			node<value_type>	*get_head() const;
			void				inorder_tree_walk(node<value_type> *x);
			void				inorder_tree_walk();

		private:
			node<value_type>	*_head;
	};
}

# include "binary_search_tree_impl.tpp"

#endif
