/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:36:50 by vismaily          #+#    #+#             */
/*   Updated: 2022/08/27 13:41:42 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_ITERATOR_TPP
# define FT_VECTOR_ITERATOR_TPP

# ifndef FT_VECTOR_HPP
# error vector_iterator.tpp should only be included from vector_iterator.hpp.
# endif

template <typename T>
vector_iterator<T>::vector_iterator()
{
	this->_elem = 0;
}

template <typename T>
vector_iterator<T>::vector_iterator(const vector_iterator &other)
{
	this->_elem = other._elem;
}

template <typename T>
vector_iterator	&vector_iterator<T>::operator=(const vector_iterator &other)
{
	if (this != &other)
		this->_elem = other._elem;
	return (*this);
}

template <typename T>
vector_iterator<T>::~vector_iterator()
{
}

template <typename T>
bool	vector_iterator<T>::operator==(const vector_iterator &other) const
{
	return (this->_elem == other._elem);
}

template <typename T>
bool	vector_iterator<T>::operator!=(const vector_iterator &other) const
{
	return (this->_elem != other._elem);
}

template <typename T>
typename reference	vector_iterator<T>::operator*() const
{
	return (*(this->_elem));
}

template <typename T>
typename pointer	vector_iterator<T>::operator->() const
{
	return (this->_elem);
}

#endif
