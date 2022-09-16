/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:30:35 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/16 12:10:14 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BINARY_SEARCH_TREE_HPP
# define FT_BINARY_SEARCH_TREE_HPP

# include <iostream>
# include <memory>
# include "../Iterators/bidirectional_iterator.hpp"
# include "../Iterators/reverse_iterator.hpp"
# include "../Other/functional.hpp"

namespace	ft
{
	/* Tree */
	template <
		typename T,
		typename Compare = ft::less<T>,
		typename Alloc = std::allocator<T>,
		bool multivalues = false
	> class	binary_search_tree
	{
		/* Node */
		private:
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
			bool		multi;
		};

		/* Member types */
		public:
			typedef T								value_type;
			typedef Compare							key_compare;
			typedef Alloc							allocator_type;
			typedef node							*node_ptr;

			typedef bidirectional_iterator<T>			iterator;
			typedef bidirectional_iterator<const T>		const_iterator;
			typedef reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef reverse_iterator<iterator>			reverse_iterator;
		private:
			typedef typename allocator_type::template rebind<node>::other \
														allocator_node_type;

		/* Constructors and destructors */
		public:
			binary_search_tree(const key_compare &comp = key_compare(),
							const allocator_type &alloc = allocator_type());
			binary_search_tree(const node_ptr head, \
								const key_compare &comp = key_compare(),
								const allocator_type &alloc = allocator_type());
			binary_search_tree(const binary_search_tree &other);
			binary_search_tree	&operator=(const binary_search_tree &other);
			~binary_search_tree();

		/* Tree functional */
		public:
			node_ptr			create_node(value_type data);
			node_ptr			get_head() const;
			int					get_count() const;
			int					height(node_ptr head) const;
			int					height() const;
			node_ptr			min(node_ptr head) const;
			node_ptr			min() const;
			node_ptr			max(node_ptr head) const;
			node_ptr			max() const;
			node_ptr			successor(node_ptr head) const;
			node_ptr			successor() const;
			node_ptr			predecessor(node_ptr head) const;
			node_ptr			predecessor() const;
			node_ptr			search(node_ptr head, value_type key) const;
			node_ptr			search(value_type key) const;

		/* Tree walk */
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

			void				print_tree(node_ptr head) const;
			void				print_tree() const;

		/* Insert and delete */
		public:
			int					tree_insert(node_ptr new_node);
			int					tree_insert(value_type value);
			void				tree_delete(node_ptr old_node);
			void				tree_delete(value_type value);

		/* Iterators */
		public:
			iterator				begin();
			const_iterator			begin() const;
			iterator				end();
			const_iterator			end() const;
			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;

		/* Helper methods */
		private:
			void				transplant(node_ptr u, node_ptr v);
			void				delete_all(node_ptr head);
			void				deep_copy(node_ptr other_node);

		/* Member data */
		private:
			node_ptr			_head;
			allocator_type		_alloc;
			allocator_node_type	_alloc_node;
			key_compare			_comp;
			int					_elem_count;
	};
}

# include "binary_search_tree_impl.tpp"

#endif
