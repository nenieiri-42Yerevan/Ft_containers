/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:13:14 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/04 17:01:51 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RB_TREE_HPP
# define FT_RB_TREE_HPP

# include <iostream>
# include <memory>
# include "../Iterators/bidirectional_iterator.hpp"
# include "../Iterators/reverse_iterator.hpp"
# include "../Other/functional.hpp"
# include "../Other/utility.hpp"
# include "../Other/rb_node.hpp"

namespace	ft
{
	template <
		typename T,
		typename KeyOfValue,
		typename Compare = ft::less<T>,
		typename Alloc = std::allocator<T>,
		bool multivalues = false
	> class	rb_tree
	{
		/* Member types */
		public:
			typedef T								value_type;
			typedef Compare							key_compare;
			typedef Alloc							allocator_type;
			typedef ft::rb_node<value_type>			*node_ptr;
			typedef size_t							size_type;

			typedef bidirectional_iterator<rb_node<value_type>, T>	\
													iterator;
			typedef bidirectional_iterator<const rb_node<value_type>, const T>
													const_iterator;
			typedef reverse_iterator<const_iterator>	\
													const_reverse_iterator;
			typedef reverse_iterator<iterator>		reverse_iterator;
		private:
			typedef typename allocator_type:: \
				template rebind<rb_node<value_type> >::other \
													allocator_node_type;

		/* Constructors and destructors */
		public:
			rb_tree(const key_compare &comp = key_compare(), \
					const allocator_type &alloc = allocator_type());
			rb_tree(const node_ptr head, \
					const key_compare &comp = key_compare(), \
					const allocator_type &alloc = allocator_type());
			rb_tree(const rb_tree &other);
			rb_tree	&operator=(const rb_tree &other);
			~rb_tree();

		/* Tree functional */
		public:
			node_ptr			create_node(value_type data);
			node_ptr			get_head() const;
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

		/* Capacity */
		public:
			bool				empty() const;
			size_type			size() const;
			size_type			max_size() const;

		/* Operations */
		public:
			node_ptr			search(node_ptr head, const value_type &data) const;
			node_ptr			search(const value_type &data) const;

			/* Count */
			void				count_in_level(node_ptr head, \
								const value_type &data, int level, \
								size_type &count) const;
			size_type			count(node_ptr head, const value_type &data) const;
			size_type			count(const value_type &data) const;

			/* Bounds */
			iterator			lower_bound(const value_type &data);
			const_iterator		lower_bound(const value_type &data) const;
			iterator			upper_bound(const value_type &data);
			const_iterator		upper_bound(const value_type &data) const;

			ft::pair<iterator, iterator> equal_range(const value_type &data);
			ft::pair<const_iterator, \
						const_iterator> equal_range(const value_type &data) const;

		/* Tree walk */
		public:
			void				preorder_tree_walk(node_ptr head) const;
			void				preorder_tree_walk() const;
			void				inorder_tree_walk(node_ptr head) const;
			void				inorder_tree_walk() const;
			void				postorder_tree_walk(node_ptr head) const;
			void				postorder_tree_walk() const;

			void				print_level(node_ptr head, int level) const;
			void				print_level(int level) const;

			void				print_tree(node_ptr head) const;
			void				print_tree() const;

		/* Insert, erase, swap */
		public:
			ft::pair<iterator, bool>	insert(node_ptr head, node_ptr new_node);
			ft::pair<iterator, bool>	insert(node_ptr new_node);
			iterator					insert(iterator hint, const value_type &value);
			ft::pair<iterator, bool>	insert(const value_type &value);
			void						erase(node_ptr old_node);
			size_type					erase(value_type value);
			void						erase(iterator pos);
			void						clear(node_ptr head);
			void						clear();
			void						swap(rb_tree &other);

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

		/* Allocator */
		public:
			allocator_type			get_allocator() const;

		/* Helper methods */
		private:
			void				transplant(node_ptr u, node_ptr v);
			void				deep_copy(node_ptr other_node, node_ptr other_null);
			bool				comp_data(value_type v1, value_type v2) const;

		/* Member data */
		private:
			node_ptr			_head;
			node_ptr			_null_node;
			allocator_type		_alloc;
			allocator_node_type	_alloc_node;
			key_compare			_comp;
			size_type			_size;
	};
}

# include "rb_tree_impl.tpp"

#endif
