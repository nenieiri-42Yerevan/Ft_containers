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
		this->multi = false;
	}

	template <typename T>
	node<T>::node(const T &elem) : data(elem)
	{
		this->left = NULL;
		this->right = NULL;
		this->p = NULL;
		this->multi = false;
	}

	template <typename T>
	node<T>::node(const node &other)
	{
		this->data = other.data;
		this->left = other.left;
		this->right = other.right;
		this->p = other.p;
		this->multi = other.multi;
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
			this->multi = other.multi;
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

	template <typename T, bool multivalues>
	binary_search_tree<T, multivalues>::binary_search_tree()
	{
		this->_head = 0;
	}

	template <typename T, bool multivalues>
	binary_search_tree<T, multivalues>::binary_search_tree( \
			const binary_search_tree<T, multivalues> &other)
	{
		this->_head = 0;
		this->deep_copy(other.get_head());
	}

	template <typename T, bool multivalues>
	binary_search_tree<T, multivalues>::binary_search_tree(const node_ptr head)
	{
		this->_head = head;
	}

	template <typename T, bool multivalues>
	binary_search_tree<T, multivalues>	&
	binary_search_tree<T, multivalues>::operator=( \
			const binary_search_tree<T, multivalues> &other)
	{
		if (this != &other)
		{
			this->delete_all(this->_head);
			this->_head = 0;
			this->deep_copy(other.get_head());
		}
		return (*this);
	}

	template <typename T, bool multivalues>
	binary_search_tree<T, multivalues>::~binary_search_tree()
	{
		this->delete_all(this->_head);
		this->_head = 0;
	}

	/*======================================*/
    /*           Tree  | fuctional          */
    /*======================================*/

	template <typename T, bool multivalues>
	typename binary_search_tree<T, multivalues>::node_ptr
	binary_search_tree<T, multivalues>::create_node(value_type data)
	{
		node<value_type>	*new_node;

		new_node = new node<value_type>(data);
		return (new_node);
	}

	template <typename T, bool multivalues>
	typename binary_search_tree<T, multivalues>::node_ptr \
	binary_search_tree<T, multivalues>::get_head() const
	{
		return (this->_head);
	}

	template <typename T, bool multivalues>
	int	binary_search_tree<T, multivalues>::get_count() const
	{
		return (this->_elem_count);
	}

	template <typename T, bool multivalues>
	int	binary_search_tree<T, multivalues>::height(node_ptr head) const
	{
		if (head == 0)
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

	template <typename T, bool multivalues>
	int	binary_search_tree<T, multivalues>::height() const
	{
		return (this->height(this->_head));
	}

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::print_tree() const
	{
		this->print_tree(this->_head);
	}

	template <typename T, bool multivalues>
	typename binary_search_tree<T, multivalues>::node_ptr \
	binary_search_tree<T, multivalues>::min(node_ptr head) const
	{
		if (head == 0)
			return (0);
		while (head->left != 0)
			head = head->left;
		return (head);
	}

	template <typename T, bool multivalues>
	typename binary_search_tree<T, multivalues>::node_ptr \
	binary_search_tree<T, multivalues>::min() const
	{
		return (this->min(this->_head));
	}

	template <typename T, bool multivalues>
	typename binary_search_tree<T, multivalues>::node_ptr \
	binary_search_tree<T, multivalues>::max(node_ptr head) const
	{
		if (head == 0)
			return (0);
		while (head->right != 0)
			head = head->right;
		return (head);
	}

	template <typename T, bool multivalues>
	typename binary_search_tree<T, multivalues>::node_ptr \
	binary_search_tree<T, multivalues>::max() const
	{
		return (this->max(this->_head));
	}

	template <typename T, bool multivalues>
	typename binary_search_tree<T, multivalues>::node_ptr \
	binary_search_tree<T, multivalues>::successor(node_ptr head) const
	{
		node_ptr	parent;

		if (head == 0)
			return (0);
		if (head->right != 0)
			return (this->min(head->right));
		else
		{
			parent = head->p;
			while (parent != 0 && head == parent->right)
			{
				head = parent;
				parent = head->p;
			}
			return (parent);
		}
	}

	template <typename T, bool multivalues>
	typename binary_search_tree<T, multivalues>::node_ptr \
	binary_search_tree<T, multivalues>::successor() const
	{
		return (this->successor(this->_head));
	}

	template <typename T, bool multivalues>
	typename binary_search_tree<T, multivalues>::node_ptr \
	binary_search_tree<T, multivalues>::predecessor(node_ptr head) const
	{
		node_ptr	parent;

		if (head == 0)
			return (0);
		if (head->left != 0)
			return (this->max(head->left));
		else
		{
			parent = head->p;
			while (parent != 0 && head == parent->left)
			{
				head = parent;
				parent = head->p;
			}
			return (parent);
		}
	}

	template <typename T, bool multivalues>
	typename binary_search_tree<T, multivalues>::node_ptr \
	binary_search_tree<T, multivalues>::predecessor() const
	{
		return (this->predecessor(this->_head));
	}

	template <typename T, bool multivalues>
	typename binary_search_tree<T, multivalues>::node_ptr \
	binary_search_tree<T, multivalues>::search(node_ptr head, value_type key) const
	{
		if (head == 0 || head->data == key)
			return (head);
		if (head->data > key)
			return (this->search(head->left, key));
		else
			return (this->search(head->right, key));
	}

	/* Iterative search */
	/*
	template <typename T, bool multivalues>
	typename binary_search_tree<T, multivalues>::node_ptr \
	binary_search_tree<T, multivalues>::search(node_ptr head, value_type key) const
	{
		while (head != 0 && head->data != key)
		{
			if (head->data > key)
				head = head->left;
			else
				head = head->right;
		}
		return (head);
	}
	*/

	template <typename T, bool multivalues>
	typename binary_search_tree<T, multivalues>::node_ptr \
	binary_search_tree<T, multivalues>::search(value_type key) const
	{
		return (this->search(this->_head, key));
	}

	/*=====================================*/
    /*            Tree  |  Walk            */
    /*=====================================*/

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::preorder_tree_walk(node_ptr head) const
	{
		if (head != NULL)
		{
			std::cout << head->data << ' ';
			preorder_tree_walk(head->left);
			preorder_tree_walk(head->right);
		}
	}

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::preorder_tree_walk() const
	{
		this->preorder_tree_walk(this->_head);
	}

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::inorder_tree_walk(node_ptr head) const
	{
		if (head != NULL)
		{
			inorder_tree_walk(head->left);
			std::cout << head->data << ' ';
			inorder_tree_walk(head->right);
		}
	}

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::inorder_tree_walk() const
	{
		this->inorder_tree_walk(this->_head);
	}

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::postorder_tree_walk(node_ptr head) const
	{
		if (head != NULL)
		{
			postorder_tree_walk(head->left);
			postorder_tree_walk(head->right);
			std::cout << head->data << ' ';
		}
	}

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::postorder_tree_walk() const
	{
		this->postorder_tree_walk(this->_head);
	}

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::preorder_tree_walk_reverse \
	(node_ptr head) const
	{
		if (head != NULL)
		{
			std::cout << head->data << ' ';
			preorder_tree_walk_reverse(head->right);
			preorder_tree_walk_reverse(head->left);
		}
	}

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::preorder_tree_walk_reverse() const
	{
		this->preorder_tree_walk_reverse(this->_head);
	}

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::inorder_tree_walk_reverse \
	(node_ptr head) const
	{
		if (head != NULL)
		{
			inorder_tree_walk_reverse(head->right);
			std::cout << head->data << ' ';
			inorder_tree_walk_reverse(head->left);
		}
	}

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::inorder_tree_walk_reverse() const
	{
		this->inorder_tree_walk_reverse(this->_head);
	}

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::postorder_tree_walk_reverse \
	(node_ptr head) const
	{
		if (head != NULL)
		{
			postorder_tree_walk_reverse(head->right);
			postorder_tree_walk_reverse(head->left);
			std::cout << head->data << ' ';
		}
	}

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::postorder_tree_walk_reverse() const
	{
		this->postorder_tree_walk_reverse(this->_head);
	}

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::print_level \
	(node_ptr head, int level) const
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

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::print_level(int level) const
	{
		this->print_level(this->_head, level);
	}

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::print_level_reverse \
	(node_ptr head, int level) const
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

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::print_level_reverse(int level) const
	{
		this->print_level_reverse(this->_head, level);
	}

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::print_tree(node_ptr head) const
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

	/*=====================================*/
    /*          Insert and delete          */
    /*=====================================*/

	template <typename T, bool multivalues>
	int	binary_search_tree<T, multivalues>::tree_insert(node_ptr new_node)
	{
		node_ptr	tmp;
		node_ptr	parent;

		tmp = this->_head;
		parent = 0;
		while (tmp != 0)
		{
			parent = tmp;
			if (new_node->data == tmp->data)
			{
				if (multivalues == false)
					return (-1);
				if (tmp->multi == false)
					tmp = tmp->right;
				else
					tmp = tmp->left;
				parent->multi = !(parent->multi);
			}
			else if (new_node->data < tmp->data)
				tmp = tmp->left;
			else
				tmp = tmp->right;
		}
		new_node->p = parent;
		if (parent == 0)
			this->_head = new_node;
		else if (new_node->data == parent->data)
		{
			if (parent->multi == true)
				parent->right = new_node;
			else
				parent->left = new_node;
		}
		else if (new_node->data < parent->data)
			parent->left = new_node;
		else
			parent->right = new_node;
		++(this->_elem_count);
		return (0);
	}

	template <typename T, bool multivalues>
	int	binary_search_tree<T, multivalues>::tree_insert(value_type value)
	{
		node_ptr	new_node;
		int			res;

		new_node = this->create_node(value);
		res = this->tree_insert(new_node);
		if (res == -1)
			delete new_node;
		return (res);
	}

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::tree_delete(node_ptr old_node)
	{
		node_ptr	u;

		if (old_node->left == 0)
			this->transplant(old_node, old_node->right);
		else if (old_node->right == 0)
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
		delete old_node;
		--(this->_elem_count);
	}

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::tree_delete(value_type value)
	{
		this->tree_delete(this->search(value));
	}

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::transplant(node_ptr u, node_ptr v)
	{
		if (u == NULL)
			return ;
		if (u->p == NULL)
			this->_head = v;
		else if (u == u->p->left)
			u->p->left = v;
		else
			u->p->right = v;
		if (v != NULL)
			v->p = u->p;
	}

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::delete_all(node_ptr head)
	{
		if (head != 0)
		{
			this->delete_all(head->left);
			this->delete_all(head->right);
			delete head;
		}
	}

	template <typename T, bool multivalues>
	void	binary_search_tree<T, multivalues>::deep_copy(node_ptr other_node)
	{
		if (other_node != 0)
		{
			this->tree_insert(create_node(other_node->data));
			this->deep_copy(other_node->left);
			this->deep_copy(other_node->right);
		}
	}
}

#endif
