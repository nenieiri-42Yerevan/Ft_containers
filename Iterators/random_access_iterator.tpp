/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.tpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:36:50 by vismaily          #+#    #+#             */
/*   Updated: 2022/08/27 13:41:42 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANDOM_ACCESS_ITERATOR_TPP
# define FT_RANDOM_ACCESS_ITERATOR_TPP

# ifndef FT_RANDOM_ACCESS_ITERATOR_HPP
# error random_access_iterator.tpp should only be included from random_access_iterator.hpp.
# endif

namespace	ft
{
	template <typename T>
	random_access_iterator<T>::random_access_iterator() : _elem(0)
	{
	}

	template <typename T>
	random_access_iterator<T>::random_access_iterator(pointer ptr) : _elem(ptr)
	{
	}

	template <typename T>
	random_access_iterator<T>::random_access_iterator(const random_access_iterator &other)
	{
		this->_elem = other._elem;
	}

	template<typename T>
	random_access_iterator<T>::operator random_access_iterator<const T> () const
	{
		return (random_access_iterator<const T>(this->_elem));
	}

	template <typename T>
	random_access_iterator<T>	&
	random_access_iterator<T>::operator=(const random_access_iterator<T> &other)
	{
		if (this != &other)
			this->_elem = other._elem;
		return (*this);
	}

	template <typename T>
	random_access_iterator<T>::~random_access_iterator()
	{
	}

	template <typename T>
	bool	random_access_iterator<T>::operator==(const random_access_iterator &other) const
	{
		return (this->_elem == other._elem);
	}

	template <typename T>
	bool	random_access_iterator<T>::operator!=(const random_access_iterator &other) const
	{
		return (this->_elem != other._elem);
	}

	template <typename T>
	typename random_access_iterator<T>::reference
	random_access_iterator<T>::operator*() const
	{
		return (*(this->_elem));
	}

	template <typename T>
	typename random_access_iterator<T>::pointer
	random_access_iterator<T>::operator->() const
	{
		return (this->_elem);
	}

	template <typename T>
	random_access_iterator<T>	&random_access_iterator<T>::operator++()
	{
		this->_elem += 1;
		return (*this);
	}

	template <typename T>
	random_access_iterator<T>	random_access_iterator<T>::operator++(int)
	{
		random_access_iterator<T>	temp;
		temp = *this;
		this->_elem += 1;
		return (temp);
	}

	template <typename T>
	random_access_iterator<T>	&random_access_iterator<T>::operator--()
	{
		this->_elem -= 1;
		return (*this);
	}

	template <typename T>
	random_access_iterator<T>	random_access_iterator<T>::operator--(int)
	{
		random_access_iterator<T>	temp;
		temp = *this;
		this->_elem -= 1;
		return (temp);
	}

	template <typename T>
	typename random_access_iterator<T>::reference
	random_access_iterator<T>::operator[](difference_type num) const
	{
		return (*(operator+(num)));
	}

	template <typename T>
	random_access_iterator<T>
	random_access_iterator<T>::operator+
	(random_access_iterator<T>::difference_type num) const
	{
		random_access_iterator<T>	temp(*this);
		temp._elem += num;
		return (temp);
	}

	template <typename T>
	random_access_iterator<T>	random_access_iterator<T>::operator-(difference_type num) const
	{
		random_access_iterator<T>	temp(*this);
		temp._elem -= num;
		return (temp);
	}

	template <typename T>
	random_access_iterator<T>	&random_access_iterator<T>::operator+=(difference_type num)
	{
		this->_elem += num;
		return (*this);
	}

	template <typename T>
	random_access_iterator<T>	&random_access_iterator<T>::operator-=(difference_type num)
	{
		this->_elem -= num;
		return (*this);
	}

	template <typename T>
	typename random_access_iterator<T>::difference_type
	random_access_iterator<T>::operator-(const random_access_iterator<T> &other) const
	{
		return (this->_elem - other._elem);
	}

	template <typename T>
	bool	random_access_iterator<T>::operator>(const random_access_iterator &other) const
	{
		return (this->_elem > other._elem);
	}

	template <typename T>
	bool	random_access_iterator<T>::operator<(const random_access_iterator &other) const
	{
		return (this->_elem < other._elem);
	}

	template <typename T>
	bool	random_access_iterator<T>::operator>=(const random_access_iterator &other) const
	{
		return (this->_elem >= other._elem);
	}

	template <typename T>
	bool	random_access_iterator<T>::operator<=(const random_access_iterator &other) const
	{
		return (this->_elem <= other._elem);
	}

	template <typename T>
	typename random_access_iterator<T>::pointer	random_access_iterator<T>::base() const
	{
		return (this->_elem);
	}

	/* For constants  */

	template <typename T_L, typename T_R>
	typename random_access_iterator<T_L>::difference_type
	operator-(const random_access_iterator<T_L> &lhs, const random_access_iterator<T_R> &rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template <typename T_L, typename T_R>
	bool operator>(const random_access_iterator<T_L> &lhs, \
			const random_access_iterator<T_R> &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <typename T_L, typename T_R>
	bool operator<(const random_access_iterator<T_L> &lhs, \
			const random_access_iterator<T_R> &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename T_L, typename T_R>
	bool operator>=(const random_access_iterator<T_L> &lhs, \
			const random_access_iterator<T_R> &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <typename T_L, typename T_R>
	bool operator<=(const random_access_iterator<T_L> &lhs, \
			const random_access_iterator<T_R> &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <typename T_L, typename T_R>
	bool operator==(const random_access_iterator<T_L> &lhs, \
			const random_access_iterator<T_R> &rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <typename T_L, typename T_R>
	bool operator!=(const random_access_iterator<T_L> &lhs, \
			const random_access_iterator<T_R> &rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <typename T>
	random_access_iterator<T>
	operator+(typename random_access_iterator<T>::difference_type n, \
			random_access_iterator<T> &rhs)
	{
		return (rhs + n);
	}
}

#endif
