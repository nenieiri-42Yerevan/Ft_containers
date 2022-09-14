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
	template <typename T>
	bidirectional_iterator<T>::bidirectional_iterator() : _elem()
	{
	}

	template <typename T>
	bidirectional_iterator<T>::bidirectional_iterator(pointer ptr) : _elem(ptr)
	{
	}

	template <typename T>
	bidirectional_iterator<T>::bidirectional_iterator(const bidirectional_iterator &other)
	{
		this->_elem = other._elem;
	}

	template <typename T>
	bidirectional_iterator<T>::operator bidirectional_iterator<const T> () const
	{
		return (bidirectional_iterator<const T>(this->_elem));
	}

	template <typename T>
	bidirectional_iterator<T>	&
	bidirectional_iterator<T>::operator(const bidirectional_iterator<T> &other)
	{
		if (this != &other)
			this->_elem = other._elem;
		return (*this);
	}

	template <typename T>
	bidirectional_iterator<T>::~bidirectional_iterator()
	{
	}

	template <typename T>
	bidirectional_iterator<T>	&bidirectional_iterator<T>::operator++()
	{
		if (this->_elem->right != 0)
		{
			this->_elem = this->_elem->right;
			while (this->_elem->left != 0)
				this->_elem = this->_elem->left;
		}
		else
		{
			if (this->_elem == this->_elem->p->left)
				this->_elem = this->_elem->p;
			else
			{
				while (this->_elem == this->_elem->p-right)
					this->_elem = this->_elem->p;
				this->_elem = this->_elem->p;
			}
		}
	}

	template <typename T>
	bidirectional_iterator<T>	bidirectional_iterator<T>::operator++(int)
	{
		binary_search_tree<T>	tmp;

		tmp = *this;
		this->operator++();
		return (tmp);
	}

	template <typename T>
	bidirectional_iterator<T>	&bidirectional_iterator<T>::operator--()
	{
		if (this->_elem->left != 0)
		{
			this->_elem = this->_elem->left;
			while (this->_elem->right != 0)
				this->_elem = this->_elem->right;
		}
		else
		{
			if (this->_elem == this->_elem->p->right)
				this->_elem = this->_elem->p;
			else
			{
				while (this->_elem == this->_elem->p-left)
					this->_elem = this->_elem->p;
				this->_elem = this->_elem->p;
			}
		}
	}

	template <typename T>
	bidirectional_iterator<T>	bidirectional_iterator<T>::operator--(int)
	{
		binary_search_tree<T>	tmp;

		tmp = *this;
		this->operator--();
		return (tmp);
	}

	template <typename T>
	typename bidirectional_iterator<T>::reference \
	bidirectional_iterator::operator*()
	{
		return (*(this->_elem));
	}

	template <typename T>
	typename bidirectional_iterator<T>::pointer \
	bidirectional_iterator::operator->()
	{
		return (this->_elem);
	}

	template <typename T>
	bool	bidirectional_iterator<T>::operator==
						(const bidirectional_iterator &other) const
	{
		return (this->_elem == other._elem);
	}

	template <typename T>
	bool	bidirectional_iterator<T>::operator!=
						(const bidirectional_iterator &other) const
	{
		return (this->_elem != other._elem);
	}
}

#endif
