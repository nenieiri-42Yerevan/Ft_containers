/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:36:50 by vismaily          #+#    #+#             */
/*   Updated: 2022/08/27 13:41:42 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANDOM_ACCESS_ITERATOR_TPP
# define FT_RANDOM_ACCESS_ITERATOR_TPP

# ifndef FT_RANDOM_ACCESS_HPP
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

	template <typename T>
	random_access_iterator	&random_access_iterator<T>::operator=(const random_access_iterator &other)
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
	typename reference	random_access_iterator<T>::operator*() const
	{
		return (*(this->_elem));
	}

	template <typename T>
	typename pointer	random_access_iterator<T>::operator->() const
	{
		return (this->_elem);
	}

	template <typename T>
	typename random_access_iterator<T>	&random_access_iterator<T>::operator++() const
	{
		this->_elem += 1;
		return (this);
	}

	template <typename T>
	typename random_access_iterator<T>	random_access_iterator<T>::operator++(int) const
	{
		random_access_iterator<T>	temp;
		temp = *this;
		this->_elem += 1;
		return (temp);
	}

	template <typename T>
	typename random_access_iterator<T>	&random_access_iterator<T>::operator--() const
	{
		this->_elem -= 1;
		return (this);
	}

	template <typename T>
	typename random_access_iterator<T>	random_access_iterator<T>::operator--(int) const
	{
		random_access_iterator<T>	temp;
		temp = *this;
		this->_elem -= 1;
		return (temp);
	}

	template <typename T>
	typename reference	random_access_iterator<T>::operator[](difference_type num);
	{
		return (*(operator+(num)));
	}

	template <typename T>
	typename random_access_iterator<T>	random_access_iterator<T>::operator+(difference_type num) const
	{
		random_access_iterator<T>	temp;
		temp._elem += num;
		return (temp);
	}

	template <typename T>
	typename random_access_iterator<T>	random_access_iterator<T>::operator-(difference_type num) const
	{
		random_access_iterator<T>	temp;
		temp._elem -= num;
		return (temp);
	}

	template <typename T>
	typename random_access_iterator<T>	&random_access_iterator<T>::operator+=(difference_type num)
	{
		this->_elem += num;
		return (*this);
	}

	template <typename T>
	typename random_access_iterator<T>	&random_access_iterator<T>::operator-=(difference_type num)
	{
		this->_elem -= num;
		return (*this);
	}

	template <typename T>
	typename random_access_iterator<T>::difference_type
	random_access_iterator<T>::operator-(const random_access_iterator<T> &other) const
	{
		return (this->_elem - other->_elem);
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
}

#endif
