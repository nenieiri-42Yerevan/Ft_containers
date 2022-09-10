/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:30:35 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/10 19:19:30 by vismaily         ###   ########.fr       */
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
			typedef T			value_type;
			typedef node<T>		node_type;
			typedef node<T>		*node_ptr;

		public:
			binary_search_tree();
			//binary_search_tree(const binary_search_tree &other);
			binary_search_tree(const node_ptr head);
			//binary_search_tree	&operator=(const binary_search_tree &other);
			//~binary_search_tree();

		/* Tree functional */
		public:
			node_ptr			create_node(value_type data);
			node_ptr			get_head() const;
			int					get_height(node_ptr head) const;
			int					get_height() const;

		/* Tree walks */
		public:
			void				preorder_tree_walk(node_ptr head) const;
			void				preorder_tree_walk() const;
			void				inorder_tree_walk(node_ptr head) const;
			void				inorder_tree_walk() const;
			void				postorder_tree_walk(node_ptr head) const;
			void				postorder_tree_walk() const;

			void				preorder_tree_walk_reverse(node_ptr head) const;
			void				preorder_tree_walk_reverse() const;
			void				inorder_tree_walk_reverse(node_ptr head) const;
			void				inorder_tree_walk_reverse() const;
			void				postorder_tree_walk_reverse(node_ptr head) const;
			void				postorder_tree_walk_reverse() const;

			void				print_level(node_ptr head, int level) const;
			void				print_level(int level) const;
			void				print_level_reverse(node_ptr head, int level) const;
			void				print_level_reverse(int level) const;

		/* Insert and delete*/
		public:
			void				tree_insert(node_ptr root, node_ptr new_node);
			void				tree_insert(node_ptr new_node);
			void				tree_insert(value_type value);

		private:
			node_ptr			_head;
	};
}

# include "binary_search_tree_impl.tpp"

#endif
