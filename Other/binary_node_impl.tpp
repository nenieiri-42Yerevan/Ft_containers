/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_node.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:07:10 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/02 14:11:49 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BINARY_NODE_IMPL_TPP
# define FT_BINARY_NODE_IMPL_TPP

# ifndef FT_BINARY_NODE_HPP
#  error binary_node_impl.tpp should only be included from binary_node.hpp.
# endif

namespace	ft
{
	/*=================================*/
    /*              Node               */
    /*=================================*/

	template <typename T>
	binary_node<T>::binary_node() :
		data()
	{
		this->left = NULL;
		this->right = NULL;
		this->p = NULL;
		this->multi = false;
	}

	template <typename T>
	binary_node<T>::binary_node(const T &elem) : data(elem)
	{
		this->left = NULL;
		this->right = NULL;
		this->p = NULL;
		this->multi = false;
	}

	template <typename T>
	binary_node<T>::binary_node(const binary_node &other)
	{
		this->data = other.data;
		this->left = other.left;
		this->right = other.right;
		this->p = other.p;
		this->multi = other.multi;
	}

	template <typename T>
	binary_node<T>	&binary_node<T>::operator=(const binary_node &other)
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
	binary_node<T>::~binary_node()
	{
	}
}

#endif
