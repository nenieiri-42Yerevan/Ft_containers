/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree_impl.tpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:30:35 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/09 12:30:37 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BINARY_SEARCH_TREE_IMPL_TPP
# define FT_BINARY_SEARCH_TREE_IMPL_TPP

# ifndef FT_BINARY_SEARCH_TREE_HPP
#  error binary_search_tree_impl.tpp should only be included from binary_search_tree.hpp.
# endif

namespace	ft
{
	/*=================================*/
    /*              Node               */
    /*=================================*/

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::node::node() :
		data()
	{
		this->left = NULL;
		this->right = NULL;
		this->p = NULL;
		this->multi = false;
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::node::node \
		(const T &elem)
		: data(elem)
	{
		this->left = NULL;
		this->right = NULL;
		this->p = NULL;
		this->multi = false;
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::node::node \
		(const node &other)
	{
		this->data = other.data;
		this->left = other.left;
		this->right = other.right;
		this->p = other.p;
		this->multi = other.multi;
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::node &
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::node::operator=
		(const node &other)
	{
		if (this != &other)
		{
			this->data = other.data;
			this->left = other.left;
			this->right = other.right;
			this->p = other.p;
			this->multi = other.multi;
		}
		return (*this);
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::node::~node()
	{
	}

	/*==========================================*/
    /*   Tree  | Constructors and destructors   */
    /*==========================================*/

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::binary_search_tree
		(const key_compare &comp, const allocator_type &alloc) :
		_alloc(alloc),
		_alloc_node(allocator_node_type()),
		_comp(comp)
	{
		this->_null_node = this->_alloc_node.allocate(1);
		this->_alloc_node.construct(this->_null_node);
		this->_null_node->p = this->_null_node;

		this->_size = 0;
		this->_head = this->_null_node;
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::binary_search_tree
		(const node_ptr head, const key_compare &comp, const allocator_type &alloc) :
		_alloc(alloc),
		_alloc_node(allocator_node_type()),
		_comp(comp)
	{
		this->_null_node = this->_alloc_node.allocate(1);
		this->_alloc_node.construct(this->_null_node);
		this->_null_node->p = this->_null_node;

		this->_size = 1;
		this->_head = head;
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::binary_search_tree
		(const binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues> &other) :
		_alloc(other._alloc),
		_alloc_node(other._alloc_node),
		_comp(other._comp)
	{
		this->_null_node = this->_alloc_node.allocate(1);
		this->_alloc_node.construct(this->_null_node);
		this->_null_node->p = this->_null_node;

		this->_head = this->_null_node;
		this->_size = other._size;
		this->deep_copy(other.get_head());
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>	&
	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::operator=( \
		const binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues> &other)
	{
		if (this != &other)
		{
			this->delete_all(this->_head);

			this->_alloc = other._alloc;
			this->_alloc_node = other._alloc_node;

			this->_head = this->_null_node;
			this->_comp = other._comp;
			this->_size = other._size;
			this->deep_copy(other.get_head());
		}
		return (*this);
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::~binary_search_tree()
	{
		this->delete_all(this->_head);
		this->_alloc_node.destroy(this->_null_node);
		this->_alloc_node.deallocate(this->_null_node, 1);
		this->_head = 0;
	}

	/*======================================*/
    /*           Tree  | fuctional          */
    /*======================================*/

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::node_ptr
	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::create_node
		(value_type data)
	{
		node_ptr	new_node;

		new_node = this->_alloc_node.allocate(1);
		this->_alloc_node.construct(new_node, data);
		new_node->left = _null_node;
		new_node->right = _null_node;
		new_node->p = _null_node;
		return (new_node);
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::node_ptr
	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::get_head() const
	{
		return (this->_head);
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> int	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::height
		(node_ptr head) const
	{
		if (head == this->_null_node)
			return (0);
		else
		{
			int lheight = height(head->left);
			int rheight = height(head->right);
			if (lheight > rheight)
				return (lheight + 1);
			else
				return (rheight + 1);
		}
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> int	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::height
		() const
	{
		return (this->height(this->_head));
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::node_ptr
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::min \
		(node_ptr head) const
	{
		if (head == this->_null_node)
			return (this->_null_node);
		while (head->left != this->_null_node)
			head = head->left;
		return (head);
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::node_ptr
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::min() const
	{
		return (this->min(this->_head));
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::node_ptr
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::max \
		(node_ptr head) const
	{
		if (head == this->_null_node)
			return (this->_null_node);
		while (head->right != this->_null_node)
			head = head->right;
		return (head);
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::node_ptr
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::max() const
	{
		return (this->max(this->_head));
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::node_ptr
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::successor
		(node_ptr head) const
	{
		node_ptr	parent;

		if (head == this->_null_node)
			return (this->_null_node);
		if (head->right != this->_null_node)
			return (this->min(head->right));
		else
		{
			parent = head->p;
			while (parent != this->_null_node && head == parent->right)
			{
				head = parent;
				parent = head->p;
			}
			return (parent);
		}
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::node_ptr
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::successor
		() const
	{
		return (this->successor(this->_head));
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::node_ptr
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::predecessor
		(node_ptr head) const
	{
		node_ptr	parent;

		if (head == this->_null_node)
			return (this->_null_node);
		if (head->left != this->_null_node)
			return (this->max(head->left));
		else
		{
			parent = head->p;
			while (parent != this->_null_node && head == parent->left)
			{
				head = parent;
				parent = head->p;
			}
			return (parent);
		}
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::node_ptr
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::predecessor
		() const
	{
		return (this->predecessor(this->_head));
	}

	/*=============================*/
    /*           Capacity          */
    /*=============================*/

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> bool	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::empty \
		() const
	{
		if (this->_size == 0)
			return (true);
		return (false);
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::size_type
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::size() const
	{
		return (this->_size);
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::size_type
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::max_size \
		() const
	{
		return (this->_alloc_node.max_size());
	}

	/*=============================*/
    /*         Operations          */
    /*=============================*/

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::node_ptr
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::search
		(node_ptr head, const value_type &data) const
	{
		if (head == this->_null_node || \
				(!this->comp_data(head->data, data) && \
				 !this->comp_data(data, head->data)))
			return (head);
		if (this->comp_data(data, head->data))
			return (this->search(head->left, data));
		else
			return (this->search(head->right, data));
	}

	/* Iterative search */
	/*
	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::node_ptr
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::search
		(node_ptr head, const value_type &data) const
	{
		while (head != this->_null_node && \
			(this->comp_data(head->data, data) || \
			this->comp_data(data, head->data))
		{
			if (this->comp_data(data, head->data))
				head = head->left;
			else
				head = head->right;
		}
		return (head);
	}
	*/

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::node_ptr
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::search \
		(const value_type &data) const
	{
		return (this->search(this->_head, data));
	}

	/* ------------------------------- Count ---------------------------------*/

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::count_in_level
		(node_ptr head, const value_type &data, int level, size_type &count) const
	{
		if (head != this->_null_node)
		{
			if (level == 1)
			{
				if (!this->comp_data(head->data, data) && \
					!this->comp_data(data, head->data))
					++count;
			}
			else if (level > 1)
			{
				count_in_level(head->left, data, level - 1, count);
				count_in_level(head->right, data, level - 1, count);
			}
		}
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::size_type
	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::count
		(node_ptr head, const value_type &data) const
	{
		size_type	count;

		count = 0;
		if (multivalues == true)
		{
			int	level = 0;
			int	tree_height = this->height(head);
			while (++level <= tree_height)
				count_in_level(head, data, level, count);
		}
		else
		{
			node_ptr	res = search(head, data);
			if (res != this->_null_node)
				++count;
		}
		return (count);
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::size_type
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::count \
		(const value_type &data) const
	{
		return(this->count(this->_head, data));
	}

	/* ------------------------------- Bounds --------------------------------*/

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::iterator
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::lower_bound
		(const value_type &data)
	{
		iterator	it1;
		iterator	it2;

		it1 = this->begin();
		it2 = this->end();
		while (it1 != it2)
		{
			if (!this->comp_data(*it1, data))
				break ;
			++it1;
		}

		return (it1);
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::const_iterator
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::lower_bound
		(const value_type &data) const
	{
		const_iterator	it1;
		const_iterator	it2;
		while (it1 != it2)
		{
			if (!this->comp_data(*it1, data))
				break ;
			++it1;
		}

		it1 = this->begin();
		it2 = this->end();

		return (it1);
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::iterator
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::upper_bound
		(const value_type &data)
	{
		iterator	it1;
		iterator	it2;

		it1 = this->begin();
		it2 = this->end();
		while (it1 != it2)
		{
			if (this->comp_data(data, *it1))
				break ;
			++it1;
		}

		return (it1);
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::const_iterator
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::upper_bound
		(const value_type &data) const
	{
		const_iterator	it1;
		const_iterator	it2;
		while (it1 != it2)
		{
			if (this->comp_data(data, *it1))
				break ;
			++it1;
		}

		it1 = this->begin();
		it2 = this->end();

		return (it1);
	}

	/*=====================================*/
    /*            Tree  |  Walk            */
    /*=====================================*/

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::preorder_tree_walk
		(node_ptr head) const
	{
		if (head != this->_null_node)
		{
			std::cout << head->data << ' ';
			preorder_tree_walk(head->left);
			preorder_tree_walk(head->right);
		}
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::preorder_tree_walk
		() const
	{
		this->preorder_tree_walk(this->_head);
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::inorder_tree_walk
		(node_ptr head) const
	{
		if (head != this->_null_node)
		{
			inorder_tree_walk(head->left);
			std::cout << head->data << ' ';
			inorder_tree_walk(head->right);
		}
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::inorder_tree_walk
		() const
	{
		this->inorder_tree_walk(this->_head);
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::postorder_tree_walk
		(node_ptr head) const
	{
		if (head != this->_null_node)
		{
			postorder_tree_walk(head->left);
			postorder_tree_walk(head->right);
			std::cout << head->data << ' ';
		}
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::postorder_tree_walk
		() const
	{
		this->postorder_tree_walk(this->_head);
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::
		preorder_tree_walk_reverse(node_ptr head) const
	{
		if (head != this->_null_node)
		{
			std::cout << head->data << ' ';
			preorder_tree_walk_reverse(head->right);
			preorder_tree_walk_reverse(head->left);
		}
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::
		preorder_tree_walk_reverse() const
	{
		this->preorder_tree_walk_reverse(this->_head);
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::
		inorder_tree_walk_reverse(node_ptr head) const
	{
		if (head != this->_null_node)
		{
			inorder_tree_walk_reverse(head->right);
			std::cout << head->data << ' ';
			inorder_tree_walk_reverse(head->left);
		}
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::
		inorder_tree_walk_reverse() const
	{
		this->inorder_tree_walk_reverse(this->_head);
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::
		postorder_tree_walk_reverse (node_ptr head) const
	{
		if (head != this->_null_node)
		{
			postorder_tree_walk_reverse(head->right);
			postorder_tree_walk_reverse(head->left);
			std::cout << head->data << ' ';
		}
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::
		postorder_tree_walk_reverse() const
	{
		this->postorder_tree_walk_reverse(this->_head);
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::print_level
		(node_ptr head, int level) const
	{
		if (head != this->_null_node)
		{
			if (level == 1)
				std::cout << head->data << " ";
			else if (level > 1)
			{
				print_level(head->left, level - 1);
				print_level(head->right, level - 1);
			}
		}
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::print_level
		(int level) const
	{
		this->print_level(this->_head, level);
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::
		print_level_reverse(node_ptr head, int level) const
	{
		if (head != this->_null_node)
		{
			if (level == 1)
				std::cout << head->data << " ";
			else if (level > 1)
			{
				print_level_reverse(head->right, level - 1);
				print_level_reverse(head->left, level - 1);
			}
		}
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::
		print_level_reverse(int level) const
	{
		this->print_level_reverse(this->_head, level);
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::print_tree
		(node_ptr head) const
	{
		int	tree_height;
		int level;

		tree_height = this->height(head);
		level = 1;
		while (level <= tree_height)
		{
			std::cout << "Level " << level - 1 << " - | ";
			print_level(head, level);
			std::cout << "|" << std::endl;
			++level;
		}
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::print_tree
		() const
	{
		this->print_tree(this->_head);
	}

	/*=====================================*/
    /*          Insert and delete          */
    /*=====================================*/

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> ft::pair<
			typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::iterator,
			bool
			>
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::tree_insert
		(node_ptr new_node)
	{
		node_ptr	tmp;
		node_ptr	parent;

		tmp = this->_head;
		parent = this->_null_node;
		while (tmp != this->_null_node)
		{
			parent = tmp;
			if (!this->comp_data(new_node->data, tmp->data) && \
				!this->comp_data(tmp->data, new_node->data))
			{
				if (multivalues == false)
					return (ft::pair<iterator, bool>(iterator(_head, tmp), false));
				if (tmp->multi == false)
					tmp = tmp->right;
				else
					tmp = tmp->left;
				parent->multi = !(parent->multi);
			}
			else if (this->comp_data(new_node->data, tmp->data))
				tmp = tmp->left;
			else
				tmp = tmp->right;
		}
		new_node->p = parent;
		if (parent == this->_null_node)
			this->_head = new_node;
		else if (!this->comp_data(new_node->data, parent->data) && \
				!this->comp_data(parent->data, new_node->data))
		{
			if (parent->multi == true)
				parent->right = new_node;
			else
				parent->left = new_node;
		}
		else if (this->comp_data(new_node->data, parent->data))
			parent->left = new_node;
		else
			parent->right = new_node;
		++(this->_size);
		return (ft::pair<iterator, bool>(iterator(_head, new_node), true));
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> ft::pair<
			typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::iterator,
			bool
			>
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::tree_insert
		(const value_type &value)
	{
		node_ptr					new_node;
		ft::pair<iterator, bool>	res;

		new_node = this->create_node(value);
		res = this->tree_insert(new_node);
		if (res.second == false)
		{
			this->_alloc_node.destroy(new_node);
			this->_alloc_node.deallocate(new_node, 1);
		}
		return (res);
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::tree_delete
		(node_ptr old_node)
	{
		node_ptr	u;

		if (old_node->left == this->_null_node)
			this->transplant(old_node, old_node->right);
		else if (old_node->right == this->_null_node)
			this->transplant(old_node, old_node->left);
		else
		{
			u = this->min(old_node->right);
			if (u != old_node->right)
			{
				this->transplant(u, u->right);
				u->right = old_node->right;
				u->right->p = u;
			}
			this->transplant(old_node, u);
			u->left = old_node->left;
			u->left->p = u;
		}
		this->_alloc_node.destroy(old_node);
		this->_alloc_node.deallocate(old_node, 1);
		--(this->_size);
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::tree_delete
		(value_type value)
	{
		this->tree_delete(this->search(value));
	}

	/*=====================================*/
    /*               Iterators             */
    /*=====================================*/

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::iterator
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::begin()
	{
		return (iterator(this->_head, this->min()));
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::
		const_iterator binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::
		begin() const
	{
		return (const_iterator(this->_head, this->min()));
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::iterator
		binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::end()
	{
		return (iterator(this->_head, this->_null_node));
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::
		const_iterator binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::
		end() const
	{
		return (const_iterator(this->_head, this->_null_node));
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::
		reverse_iterator binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::
		rbegin()
	{
		return (reverse_iterator(this->end()));
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::
		const_reverse_iterator binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::
		rbegin() const
	{
		return (const_reverse_iterator(this->end()));
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::
		reverse_iterator binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::
		rend()
	{
		return (reverse_iterator(this->begin()));
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::
		const_reverse_iterator binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::
		rend() const
	{
		return (const_reverse_iterator(this->begin()));
	}

	/*=====================================*/
    /*         	    Allocator              */
    /*=====================================*/

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> typename binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::
		allocator_type binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::
		get_allocator() const
	{
		return (this->_alloc);
	}

	/*=====================================*/
    /*          Helper methods             */
    /*=====================================*/

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::transplant
		(node_ptr u, node_ptr v)
	{
		if (u == this->_null_node)
			return ;
		if (u->p == this->_null_node)
			this->_head = v;
		else if (u == u->p->left)
			u->p->left = v;
		else
			u->p->right = v;
		if (v != this->_null_node)
			v->p = u->p;
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::delete_all
		(node_ptr head)
	{
		if (head != this->_null_node)
		{
			this->delete_all(head->left);
			this->delete_all(head->right);
			this->_alloc_node.destroy(head);
			this->_alloc_node.deallocate(head, 1);
		}
	}

	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	> void	binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>::deep_copy
		(node_ptr other_node)
	{
		if (other_node != this->_null_node)
		{
			this->tree_insert(create_node(other_node->data));
			this->deep_copy(other_node->left);
			this->deep_copy(other_node->right);
		}
	}
	
	template <
		typename T,
		typename KeyOfValue,
		typename Compare,
		typename Alloc,
		bool multivalues
	>
	bool binary_search_tree<T, KeyOfValue, Compare, Alloc, multivalues>:: \
		comp_data(value_type v1, value_type v2) const
	{
		return (_comp(KeyOfValue()(v1), KeyOfValue()(v2)));
	}
}

#endif
