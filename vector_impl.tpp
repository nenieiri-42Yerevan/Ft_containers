/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_impl.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:48:51 by vismaily          #+#    #+#             */
/*   Updated: 2022/08/22 12:48:51 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_IMPL_TPP
# define FT_VECTOR_IMPL_TPP

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
		size_type	i;

		_alloc = alloc;
		_array = n ? _alloc.allocate(n) : NULL;
		_capacity = n;
		_size = 0;
		try
		{
			for (i = 0; i < n; ++i)
			{
				_alloc.construct(_array + i, val);
				_size += 1;
			}
		}
		catch (...)
		{
			this->clear();
			this->_alloc.deallocate(this->_array, n);
			throw ;
		}
	}

	template <typename T, typename Allocator>
	template <typename InputIterator>
	vector<T, Allocator>::vector(InputIterator first, InputIterator last,
			const allocator_type &alloc)
	{
		difference_type	n;

		n = distance(first, last);
		_alloc = alloc;
		_array = this->_alloc.allocate(n);
		_capacity = n;
		_size = 0;
		try
		{
			while (first != last)
			{
				this->push_back(*first);
				++first;
				this->_size += 1;
			}
		}
		catch (...)
		{
			this->clear();
			this->_alloc.deallocate(this->_array, n);
			throw ;
		}
	}

	template <typename T, typename Allocator>
	vector<T, Allocator>::vector(const vector &other)
	{
		this->_alloc = other._alloc;
		this->_alloc.allocate(other._capacity);
		this->_capacity = other._capacity;
		this->_size = 0;
		while (this->_size != other._size)
			this->push_back(other[this->_size]);
	}

	template <typename T, typename Allocator>
	vector<T, Allocator>	&vector<T, Allocator>::operator=(const vector &other)
	{
		if (this != &other)
		{
			this->clear();
			if (this->_array != 0)
				this->_alloc.deallocate(this->_array, this->_capacity);
			this->_alloc = other._alloc;
			this->_alloc.allocate(other._capacity);
			this->_capacity = other._capacity;
			this->_size = 0;
			while (this->_size != other._size)
				this->push_back(other[this->_size]);
		}
		return (*this);
	}

	template <typename T, typename Allocator>
	vector<T, Allocator>::~vector()
	{
		this->clear();
		if (this->_array != 0)
			this->_alloc.deallocate(this->_array, this->_capacity);
	}

	/*====================================*/
	/* 	  Member functions (Iterators)    */
	/*====================================*/

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::iterator	vector<T, Allocator>::begin()
	{
		return (iterator(this->_array));
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::const_iterator	vector<T, Allocator>::begin() const
	{
		return (const_iterator(this->_array));
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::iterator	vector<T, Allocator>::end()
	{
		return (iterator(this->_array + this->_size));
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::const_iterator	vector<T, Allocator>::end() const
	{
		return (const_iterator(this->_array + this->_size));
	}

	/*===================================*/
	/* 	  Member functions (Capacity)    */
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

	template <typename T, typename Allocator>
	bool	vector<T, Allocator>::empty() const
	{
		return (this->_size == 0);
	}

	template <typename T, typename Allocator>
	void	vector<T, Allocator>::reserve(size_type new_cap)
	{
		pointer		tmp;
		size_type	i;

		if (this->_size ==  this->max_size())
			throw std::length_error("vector::out of max_size");
		else if (new_cap > this->_capacity)
		{
			tmp = this->_alloc.allocate(new_cap);
			try
			{
				for (i = 0; i < this->_size; ++i)
				{
					this->_alloc.construct(tmp + i, this->_array[i]);
					this->_alloc.destroy(&(this->_array[i]));
				}
			}
			catch (...)
			{
				for (size_type j = 0; j < i; j++)
                	this->_alloc.destroy(tmp + j);
				this->_alloc.deallocate(tmp, new_cap);
				throw ;
			}
			this->_alloc.deallocate(this->_array, this->_capacity);
			this->_capacity = new_cap;
			this->_array = tmp;
		}
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
	/* 	  Member functions (Modifiers)    */
	/*====================================*/
	
	template <typename T, typename Allocator>
	void	vector<T, Allocator>::push_back(const value_type &val)
	{
		if (this->_size == this->_capacity)
		{
			if (this->_capacity == 0)
				this->reserve(1);
			else if (this->max_size() >= this->_capacity * 2)
				this->reserve(this->_capacity * 2);
			else
				this->reserve(this->max_size());
		}
		this->_alloc.construct(this->_array + this->_size, val);
		this->_size += 1;
	}

	template <typename T, typename Allocator>
	void	vector<T, Allocator>::pop_back()
	{
		this->_alloc.destroy(&this->back());
		this->_size -= 1;
	}

	template <typename T, typename Allocator>
	void	vector<T,Allocator>::clear()
	{
		for (size_type i = 0; i < this->_size; ++i)
			this->_alloc.destroy(this->_array + i);
		this->_size = 0;
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
