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
	/*===================================*/
    /*                Node               */
    /*===================================*/

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

	/*===================================*/
    /*                Tree               */
    /*===================================*/

	template <typename T>
	binary_search_tree<T>::binary_search_tree()
	{
		this->_head = 0;
	}

	template <typename T>
	binary_search_tree<T>::binary_search_tree(const binary_search_tree<T> &other)
	{
		this->_head = other._head;
	}

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

	template <typename T>
	node<typename binary_search_tree<T>::value_type> *
	binary_search_tree<T>::get_head() const
	{
		return (this->_head);
	}

	template <typename T>
	void	binary_search_tree<T>::inorder_tree_walk(node<value_type> *x)
	{
		if (x != NULL)
		{
			inorder_tree_walk(x->left);
			std::cout << x->data << std::endl;
			inorder_tree_walk(x->right);
		}
	}

	template <typename T>
	void	binary_search_tree<T>::inorder_tree_walk()
	{
		inorder_tree_walk(this->_head);
	}
}

#endif
