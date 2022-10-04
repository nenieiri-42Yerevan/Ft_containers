/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_node_impl.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:21:57 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/04 17:21:57 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RB_NODE_IMPL_TPP
# define FT_RB_NODE_IMPL_TPP

# ifndef FT_RB_NODE_HPP
#  error rb_node_impl.tpp should only be included from rb_node.hpp.
# endif

namespace	ft
{
	template <typename T>
	rb_node<T>::rb_node() :
		data()
	{
		this->left = NULL;
		this->right = NULL;
		this->p = NULL;
	}

	template <typename T>
	rb_node<T>::rb_node(const T &elem) : data(elem)
	{
		this->left = NULL;
		this->right = NULL;
		this->p = NULL;
	}

	template <typename T>
	rb_node<T>::rb_node(const rb_node &other)
	{
		this->data = other.data;
		this->left = other.left;
		this->right = other.right;
		this->p = other.p;
	}

	template <typename T>
	rb_node<T>	&rb_node<T>::operator=(const rb_node &other)
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
	rb_node<T>::~rb_node()
	{
	}
}

#endif
