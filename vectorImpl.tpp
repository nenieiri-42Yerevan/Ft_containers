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
		_array = _alloc.allocate(n);
		(void)val;
	}

	/*===================================*/
	/* 	  Member functions (capacity)    */
	/*===================================*/
	
	template <typename T, typename Allocator>
	typename vector<T, Allocator>::size_type	vector<T, Allocator>::size() const
	{
		return (this->_size);
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::size_type	vector<T, Allocator>::capacity() const
	{
		return (this->_capacity);
	}
}

#endif
