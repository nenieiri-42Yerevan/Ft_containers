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
#  error vector_impl.tpp should only be included from vector.hpp.
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
			const allocator_type &alloc,
	typename enable_if<!is_integral<InputIterator>::value, bool>::type)
	{
		difference_type	n;

		n = ft::distance(first, last);
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
		this->_array = this->_alloc.allocate(other._capacity);
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
			_array = this->_alloc.allocate(other._capacity);
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

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::reverse_iterator	vector<T, Allocator>::rbegin()
	{
		return (reverse_iterator(this->end()));
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::const_reverse_iterator \
	vector<T, Allocator>::rbegin() const
	{
		return (const_reverse_iterator(this->end()));
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::reverse_iterator	vector<T, Allocator>::rend()
	{
		return (reverse_iterator(this->begin()));
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::const_reverse_iterator \
	vector<T, Allocator>::rend() const
	{
		return (const_reverse_iterator(this->begin()));
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
	void	vector<T, Allocator>::resize(size_type n, value_type val)
	{
		if (n > this->max_size())
			throw std::logic_error("vector:resize, max_size error");
		else if (n < this->_size)
			this->erase(this->begin() + n, this->end());
		else if (n > this->_size)
			this->insert(this->end(), n - this->_size, val);
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
					this->_alloc.destroy(this->_alloc.address(this->_array[i]));
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
	void	vector<T, Allocator>::assign(size_type n, const value_type &val)
	{
		this->erase(this->begin(), this->end());
		this->reserve(n);
		this->insert(this->begin(), n, val);
	}

	template <typename T, typename Allocator>
	template <typename InputIt>
	void	vector<T, Allocator>::assign(InputIt first, InputIt last,
	typename enable_if<!is_integral<InputIt>::value, bool>::type)
	{
		this->erase(this->begin(), this->end());
		this->reserve(ft::distance(first, last));
		this->insert(this->begin(), first, last);
	}
	
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
	typename vector<T, Allocator>::iterator	\
	vector<T, Allocator>::insert(iterator pos, const T &value)
	{
		size_type	start;

		start = pos - this->begin();
		this->insert(pos, 1, value);
		return (this->begin() + start);
	}

	template <typename T, typename Allocator>
	void	vector<T, Allocator>::insert(iterator pos, size_type count, const T &value)
	{
		pointer		tmp;
		size_type	start;
		size_type	i;
		size_type	j;

		start = static_cast<size_type>(pos - this->begin());
		i = 0;
		j = 0;
		if (count == 0)
			return ;
		else if (pos < this->begin() && pos > this->end())
			throw std::logic_error("vector:insert error");
		else if (this->max_size() < this->_size + count)
			throw std::length_error("vector:insert error");
		if (this->_size + count > this->_capacity)
		{
			size_type	tmp_cap = this->_capacity == 0 ? 1 : this->_capacity * 2;
			while (tmp_cap < this->_size + count)
				tmp_cap *= 2;
			tmp = this->_alloc.allocate(tmp_cap);
			try
			{
				for (; i < start; ++i)
					this->_alloc.construct(tmp + i, this->_array[i]);
				for (; j < count; ++j)
					this->_alloc.construct(tmp + i + j, value);
				for (; i + j < (this->_size + count); ++i)
					this->_alloc.construct(tmp + i + j, this->_array[i]);
				for (int t = 0; i < this->_size; ++t)
					this->_alloc.destroy(this->_alloc.address(this->_array[t]));
			}
			catch (...)
			{
				for (size_type t = 0; t < i + j; t++)
                	this->_alloc.destroy(tmp + i + j);
				this->_alloc.deallocate(tmp, this->_size + count);
				throw ;
			}
			this->_alloc.deallocate(this->_array, this->_capacity);
			this->_capacity = tmp_cap;
			this->_array = tmp;
		}
		else
		{
			for (size_type t = this->_size + count - 1; t >= start; --t)
			{
				if (t >= start && t < start + count)
					this->_alloc.construct(this->_array + t, value);
				else if (t >= this->_size)
					this->_alloc.construct(this->_array + t, this->_array[t - count]);
				else if (t <= this->_size && t >= start + count)
				{
					this->_alloc.destroy(this->_array + t);
					this->_alloc.construct(this->_array + t, this->_array[t - count]);
				}
				if (t == 0)
					break ;
			}
		}
		this->_size = this->_size + count;
	}

	template <typename T, typename Allocator>
	template <typename InputIt>
	void	vector<T, Allocator>::insert(iterator pos, InputIt first, InputIt last,
	typename enable_if<!is_integral<InputIt>::value, bool>::type)
	{
		pointer		tmp;
		size_type	start;
		size_type	i;
		size_type	j;
		size_type	count;

		count = static_cast<size_type>(ft::distance(first, last));
		start = static_cast<size_type>(pos - this->begin());
		i = 0;
		j = 0;
		if (count == 0)
			return ;
		else if (pos < this->begin() && pos > this->end())
			throw std::logic_error("vector:insert error");
		else if (this->max_size() < this->_size + count)
			throw std::length_error("vector:insert error");
		if (this->_size + count > this->_capacity)
		{
			size_type	tmp_cap = this->_capacity == 0 ? 1 : this->_capacity * 2;
			while (tmp_cap < this->_size + count)
				tmp_cap *= 2;
			tmp = this->_alloc.allocate(tmp_cap);
			try
			{
				for (; i < start; ++i)
					this->_alloc.construct(tmp + i, this->_array[i]);
				for (; j < count; ++j)
					this->_alloc.construct(tmp + i + j, *(first++));
				for (; i + j < (this->_size + count); ++i)
					this->_alloc.construct(tmp + i + j, this->_array[i]);
				for (int t = 0; i < this->_size; ++t)
					this->_alloc.destroy(this->_alloc.address(this->_array[t]));
			}
			catch (...)
			{
				for (size_type t = 0; t < i + j; t++)
                	this->_alloc.destroy(tmp + i + j);
				this->_alloc.deallocate(tmp, this->_size + count);
				throw ;
			}
			this->_alloc.deallocate(this->_array, this->_capacity);
			this->_capacity = tmp_cap;
			this->_array = tmp;
		}
		else
		{
			for (size_type t = this->_size + count - 1; t >= start; --t)
			{
				if (t >= start && t < start + count)
					this->_alloc.construct(this->_array + t, *(--last));
				else if (t >= this->_size)
					this->_alloc.construct(this->_array + t, this->_array[t - count]);
				else if (t <= this->_size && t >= start + count)
				{
					this->_alloc.destroy(this->_array + t);
					this->_alloc.construct(this->_array + t, this->_array[t - count]);
				}
				if (t == 0)
					break ;
			}
		}
		this->_size = this->_size + count;
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::iterator	vector<T, Allocator>::erase(iterator pos)
	{
		return (this->erase(pos, pos + 1));
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::iterator
	vector<T, Allocator>::erase(iterator first, iterator last)
	{
		size_type	count;
		size_type	start;
		size_type	tmp_start;

		count = last - first;
		start = first - this->begin();
		tmp_start = start;
		while (first != last)
		{
			this->_alloc.destroy(this->_alloc.address(*first));
			++first;
		}
		while (count != 0 && last < this->end())
		{
			this->_alloc.construct(this->_alloc.address(this->_array[tmp_start++]), *last);
			this->_alloc.destroy(this->_alloc.address(*last));
			++last;
		}
		this->_size -= count;

		return (this->begin() + start);
	}

	template <typename T, typename Allocator>
	void	vector<T, Allocator>::swap(vector &other)
	{
		pointer			tmp_array;
		size_type		tmp_size;
		allocator_type	tmp_alloc;

		tmp_array = this->_array;
		this->_array = other._array;
		other._array = tmp_array;

		tmp_size = this->_size;
		this->_size = other._size;
		other._size = tmp_size;

		tmp_size = this->_capacity;
		this->_capacity = other._capacity;
		other._capacity = tmp_size;

		tmp_alloc = this->_alloc;
		this->_alloc = other._alloc;
		other._alloc = tmp_alloc;
	}

	template <typename T, typename Allocator>
	void	vector<T, Allocator>::clear()
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

	/*============================*/
	/* 	  Non-member functions    */
	/*============================*/

	template <typename T, typename Allocator>
	void	swap(vector<T, Allocator> &lhs, vector<T, Allocator> &rhs)
	{
		lhs.swap(rhs);
	}

	template <typename T, typename Allocator>
	bool	operator==(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <typename T, typename Allocator>
	bool	operator!=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <typename T, typename Allocator>
	bool	operator<(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
	{
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <typename T, typename Allocator>
	bool	operator<=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
	{
		return (!(rhs < lhs));
	}

	template <typename T, typename Allocator>
	bool	operator>(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
	{
		return (rhs < lhs);
	}

	template <typename T, typename Allocator>
	bool	operator>=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
	{
		return (!(lhs < rhs));
	}
}

#endif
