/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator_impl.tpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:08:57 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/14 15:11:34 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIDIRECTIONAL_ITERATOR_IMPL_TPP
# define FT_BIDIRECTIONAL_ITERATOR_IMPL_TPP

# ifndef FT_BIDIRECTIONAL_ITERATOR_HPP
#  error bidirectional_iterator_impl.tpp should only be included from bidirectional_iterator.hpp.
# endif

namespace	ft
{
	template <typename T, typename pair_type>
	bidirectional_iterator<T, pair_type>::bidirectional_iterator() :
		_head(),
		_elem()
	{
	}

	template <typename T, typename pair_type>
	bidirectional_iterator<T, pair_type>::bidirectional_iterator \
		(node_pointer head, node_pointer ptr) :
		_head(head),
		_elem(ptr)
	{
	}

	template <typename T, typename pair_type>
	bidirectional_iterator<T, pair_type>::bidirectional_iterator
		(const bidirectional_iterator &other)
	{
		this->_head = other._head;
		this->_elem = other._elem;
	}

	template <typename T, typename pair_type>
	bidirectional_iterator<T, pair_type>::operator \
		bidirectional_iterator<const T, const pair_type> () const
	{
		return (bidirectional_iterator<const T, const pair_type>(this->_head, this->_elem));
	}

	template <typename T, typename pair_type>
	bidirectional_iterator<T, pair_type>	&
	bidirectional_iterator<T, pair_type>::operator= \
		(const bidirectional_iterator<T, pair_type> &other)
	{
		if (this != &other)
		{
			this->_head = other._head;
			this->_elem = other._elem;
		}
		return (*this);
	}

	template <typename T, typename pair_type>
	bidirectional_iterator<T, pair_type>::~bidirectional_iterator()
	{
	}

	template <typename T, typename pair_type>
	bidirectional_iterator<T, pair_type>	&
		bidirectional_iterator<T, pair_type>::operator++()
	{
		if (this->_elem->right != this->_head->p)
		{
			this->_elem = this->_elem->right;
			while (this->_elem->left != this->_head->p)
				this->_elem = this->_elem->left;
		}
		else
		{
			if (this->_elem == this->_elem->p->left)
				this->_elem = this->_elem->p;
			else
			{
				while (this->_elem == this->_elem->p->right)
					this->_elem = this->_elem->p;
				this->_elem = this->_elem->p;
			}
		}
		return (*this);
	}

	template <typename T, typename pair_type>
	bidirectional_iterator<T, pair_type> \
		bidirectional_iterator<T, pair_type>::operator++(int)
	{
		bidirectional_iterator<T, pair_type>	tmp;

		tmp = *this;
		this->operator++();
		return (tmp);
	}

	template <typename T, typename pair_type>
	bidirectional_iterator<T, pair_type>	&
		bidirectional_iterator<T, pair_type>::operator--()
	{
		if (this->_elem == this->_head->p)
		{
			this->_elem = this->_head;
			while (this->_elem->right != this->_head->p)
				this->_elem = this->_elem->right;
		}
		else if (this->_elem->left != this->_head->p)
		{
			this->_elem = this->_elem->left;
			while (this->_elem->right != this->_head->p)
				this->_elem = this->_elem->right;
		}
		else
		{
			if (this->_elem == this->_elem->p->right)
				this->_elem = this->_elem->p;
			else
			{
				while (this->_elem == this->_elem->p->left)
					this->_elem = this->_elem->p;
				this->_elem = this->_elem->p;
			}
		}
		return (*this);
	}

	template <typename T, typename pair_type>
	bidirectional_iterator<T, pair_type> \
		bidirectional_iterator<T, pair_type>::operator--(int)
	{
		bidirectional_iterator<T, pair_type>	tmp;

		tmp = *this;
		this->operator--();
		return (tmp);
	}

	template <typename T, typename pair_type>
	pair_type	&bidirectional_iterator<T, pair_type>::operator*() const
	{
		return (this->_elem->data);
	}

	template <typename T, typename pair_type>
	pair_type	*bidirectional_iterator<T, pair_type>::operator->() const
	{
		return (&(this->_elem->data));
	}

	template <typename T, typename pair_type>
	typename bidirectional_iterator<T, pair_type>::node_pointer \
		bidirectional_iterator<T, pair_type>::get_elem() const
	{
		return (this->_elem);
	}

	template <typename T, typename pair_type>
	bool	bidirectional_iterator<T, pair_type>::operator==
		(const bidirectional_iterator &other) const
	{
		return (this->_elem == other._elem);
	}

	template <typename T, typename pair_type>
	bool	bidirectional_iterator<T, pair_type>::operator!=
		(const bidirectional_iterator &other) const
	{
		return (this->_elem != other._elem);
	}
}

#endif 
