/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:22:31 by vismaily          #+#    #+#             */
/*   Updated: 2022/08/22 16:27:39 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <memory>
# include <cstddef>

namespace	ft
{
	template <
		typename T,
		typename Allocator = std::allocator<T>
	> class	vector
	{
		/* Member types */
		public:
			typedef T					value_type;
			typedef Allocator			allocator_type;
			typedef value_type&			reference;
			typedef const value_type&	const_reference;
			typedef T*					pointer;
			typedef const T*			const_pointer;
			typedef ptrdiff_t			difference_type;
			typedef size_t				size_type;
			/* Member types (iterators) */

		
		/* Constructers and Destructer */
		public:
			explicit	vector(const allocator_type &alloc = allocator_type());

		private:
			size_type					_size;
			size_type					_capacity;
			pointer						*_array;
	};
}

# include "vectorImpl.tpp"

#endif
