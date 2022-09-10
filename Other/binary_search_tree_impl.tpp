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

	template <typename T>
	node<T>::node() : data()
	{
		this->left = NULL;
		this->right = NULL;
		this->p = NULL;
	}

	template <typename T>
	node<T>::node(const T &elem) : data(elem)
	{
		this->left = NULL;
		this->right = NULL;
		this->p = NULL;
	}

	template <typename T>
	node<T>::node(const node &other)
	{
		this->data = other.data;
		this->left = other.left;
		this->right = other.right;
		this->p = other.p;
	}

	template <typename T>
	node<T>	&node<T>::operator=(const node &other)
	{
		if (this != &other)
		{
			this->data = other.data;
			this->left = other.left;
			this->right = other.right;
			this->p = other.p;
		}
		return (*this);
	}

	template <typename T>
	node<T>::~node()
	{
	}

	/*==========================================*/
    /*   Tree  | Constructors and destructors   */
    /*==========================================*/

	template <typename T>
	binary_search_tree<T>::binary_search_tree()
	{
		this->_head = 0;
	}

/*	template <typename T>
	binary_search_tree<T>::binary_search_tree(const binary_search_tree<T> &other)
	{
		this->_head = other._head;
	}
*/
	template <typename T>
	binary_search_tree<T>::binary_search_tree(const node_ptr head)
	{
		this->_head = head;
	}
/*
	template <typename T>
	binary_search_tree<T>	&binary_search_tree<T>::operator=( \
										const binary_search_tree<T> &other)
	{
		if (this != &other)
			this->_head = other._head;
		return (*this);
	}

	template <typename T>
	binary_search_tree<T>::~binary_search_tree()
	{
	}
*/
	/*======================================*/
    /*           Tree  | fuctional          */
    /*======================================*/

	template <typename T>
	typename binary_search_tree<T>::node_ptr
	binary_search_tree<T>::create_node(value_type data)
	{
		node<value_type>	*new_node;

		new_node = new node<value_type>(data);
		return (new_node);
	}

	template <typename T>
	typename binary_search_tree<T>::node_ptr binary_search_tree<T>::get_head() const
	{
		return (this->_head);
	}

	template <typename T>
	int	binary_search_tree<T>::get_height(node_ptr head) const
	{
		if (head == 0)
			return (0);
		else
		{
			int lheight = get_height(head->left);
			int rheight = get_height(head->right);
			if (lheight > rheight)
				return (lheight + 1);
			else
				return (rheight + 1);
		}
	}

	template <typename T>
	int	binary_search_tree<T>::get_height() const
	{
		return (get_height(this->_head));
	}

	/*=====================================*/
    /*            Tree  |  Walks           */
    /*=====================================*/

	template <typename T>
	void	binary_search_tree<T>::preorder_tree_walk(node_ptr head) const
	{
		if (head != NULL)
		{
			std::cout << head->data << ' ';
			preorder_tree_walk(head->left);
			preorder_tree_walk(head->right);
		}
	}

	template <typename T>
	void	binary_search_tree<T>::preorder_tree_walk() const
	{
		preorder_tree_walk(this->_head);
	}

	template <typename T>
	void	binary_search_tree<T>::inorder_tree_walk(node_ptr head) const
	{
		if (head != NULL)
		{
			inorder_tree_walk(head->left);
			std::cout << head->data << ' ';
			inorder_tree_walk(head->right);
		}
	}

	template <typename T>
	void	binary_search_tree<T>::inorder_tree_walk() const
	{
		inorder_tree_walk(this->_head);
	}

	template <typename T>
	void	binary_search_tree<T>::postorder_tree_walk(node_ptr head) const
	{
		if (head != NULL)
		{
			postorder_tree_walk(head->left);
			postorder_tree_walk(head->right);
			std::cout << head->data << ' ';
		}
	}

	template <typename T>
	void	binary_search_tree<T>::postorder_tree_walk() const
	{
		postorder_tree_walk(this->_head);
	}

	template <typename T>
	void	binary_search_tree<T>::preorder_tree_walk_reverse(node_ptr head) const
	{
		if (head != NULL)
		{
			std::cout << head->data << ' ';
			preorder_tree_walk_reverse(head->right);
			preorder_tree_walk_reverse(head->left);
		}
	}

	template <typename T>
	void	binary_search_tree<T>::preorder_tree_walk_reverse() const
	{
		preorder_tree_walk_reverse(this->_head);
	}

	template <typename T>
	void	binary_search_tree<T>::inorder_tree_walk_reverse(node_ptr head) const
	{
		if (head != NULL)
		{
			inorder_tree_walk_reverse(head->right);
			std::cout << head->data << ' ';
			inorder_tree_walk_reverse(head->left);
		}
	}

	template <typename T>
	void	binary_search_tree<T>::inorder_tree_walk_reverse() const
	{
		inorder_tree_walk_reverse(this->_head);
	}

	template <typename T>
	void	binary_search_tree<T>::postorder_tree_walk_reverse(node_ptr head) const
	{
		if (head != NULL)
		{
			postorder_tree_walk_reverse(head->right);
			postorder_tree_walk_reverse(head->left);
			std::cout << head->data << ' ';
		}
	}

	template <typename T>
	void	binary_search_tree<T>::postorder_tree_walk_reverse() const
	{
		postorder_tree_walk_reverse(this->_head);
	}

	template <typename T>
	void	binary_search_tree<T>::print_level(node_ptr head, int level) const
	{
		if (head != 0)
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

	template <typename T>
	void	binary_search_tree<T>::print_level(int level) const
	{
		print_level(this->_head, level);
	}

	template <typename T>
	void	binary_search_tree<T>::print_level_reverse(node_ptr head, int level) const
	{
		if (head != 0)
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

	template <typename T>
	void	binary_search_tree<T>::print_level_reverse(int level) const
	{
		print_level_reverse(this->_head, level);
	}

	/*=====================================*/
    /*          Insert and delete          */
    /*=====================================*/

	template <typename T>
	void	binary_search_tree<T>::tree_insert(node_ptr root, node_ptr new_node)
	{
		node_ptr	tmp;
		node_ptr	parent;

		tmp = root;
		parent = 0;
		while (tmp != 0)
		{
			parent = tmp;
			if (new_node->data < tmp->data)
				tmp = tmp->left;
			else
				tmp = tmp->right;
		}
		new_node->p = parent;
		if (parent == 0)
		{
			root = new_node;
			this->_head = new_node;
		}
		else if (new_node->data < parent->data)
			parent->left = new_node;
		else
			parent->right = new_node;
	}

	template <typename T>
	void	binary_search_tree<T>::tree_insert(node_ptr new_node)
	{
		binary_search_tree<T>::tree_insert(this->_head, new_node);
	}

	template <typename T>
	void	binary_search_tree<T>::tree_insert(value_type value)
	{
		binary_search_tree<T>::tree_insert(this->_head, create_node(value));
	}
}

#endif
