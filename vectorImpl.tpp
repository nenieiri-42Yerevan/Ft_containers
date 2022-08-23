/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorImpl.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:48:51 by vismaily          #+#    #+#             */
/*   Updated: 2022/08/22 12:48:51 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTORIMPL_TPP
# define FT_VECTORIMPL_TPP

# ifndef FT_VECTOR_HPP
# error vectorImpl.tpp should only be included from vector.hpp.
# endif

namespace	ft
{

	/*===================================*/
    /*    Constructors and Destructor	 */
    /*===================================*/

	template <typename T, typename Allocator>
	vector<T, Allocator>::vector(const allocator_type &alloc)
	{
		_size = 0;
		_capacity = 0;
		_array = NULL;
		_alloc = alloc;
	}

	template <typename T, typename Allocator>
	vector<T, Allocator>::vector(size_type n, const value_type &val, \
			const allocator_type &alloc)
	{
		_size = n;
		_capacity = n;
		_alloc = alloc;
		_array = n ? _alloc.allocate(n) : NULL;
		for (size_type i = 0; i < n; ++i)
			_alloc.construct(_array + i, val);
	}

	/*===================================*/
	/* 	  Member functions (capacity)    */
	/*===================================*/
	
	template <typename T, typename Allocator>
	typename vector<T, Allocator>::size_type \
	vector<T, Allocator>::size() const
	{
		return (this->_size);
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::size_type \
	vector<T, Allocator>::max_size() const
	{
		return (this->_alloc.max_size());
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::size_type \
	vector<T, Allocator>::capacity() const
	{
		return (this->_capacity);
	}

	/*=========================================*/
	/* 	  Member functions (Element access)    */
	/*=========================================*/
	
	template <typename T, typename Allocator>
	typename vector<T, Allocator>::reference \
	vector<T, Allocator>::operator[](size_type pos)
	{
		return (this->_array[pos]);
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::const_reference \
	vector<T, Allocator>::operator[](size_type pos) const
	{
		return (this->_array[pos]);
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::reference \
	vector<T, Allocator>::at(size_type pos)
	{
		if (pos < this->_size)
			return (this->_array[pos]);
		else
			throw std::out_of_range("vector::range_check: n (which is "
					+ std::to_string(pos) + ") >= this->size() (which is "
					+ std::to_string(this->_size) + ")");
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::const_reference \
	vector<T, Allocator>::at(size_type pos) const
	{
		if (pos < this->_size)
			return (this->_array[pos]);
		else
			throw std::out_of_range("vector::range_check: n (which is "
					+ std::to_string(pos) + ") >= this->size() (which is "
					+ std::to_string(this->_size) + ")");
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::reference	vector<T, Allocator>::front()
	{
		return (this->_array[0]);
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::const_reference	vector<T, Allocator>::front() const
	{
		return (this->_array[0]);
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::reference	vector<T, Allocator>::back()
	{
		return (this->_array[this->_size - 1]);
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::const_reference	vector<T, Allocator>::back() const
	{
		return (this->_array[this->_size - 1]);
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::pointer	vector<T, Allocator>::data()
	{
		return (this->_array);
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::const_pointer	vector<T, Allocator>::data() const
	{
		return (this->_array);
	}

	/*====================================*/
	/* 	  Member functions (Allocator)    */
	/*====================================*/
	
	template <typename T, typename Allocator>
	typename vector<T, Allocator>::allocator_type \
	vector<T, Allocator>::get_allocator() const
	{
		return (this->_alloc);
	}
}

#endif
