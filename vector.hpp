/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:22:31 by vismaily          #+#    #+#             */
/*   Updated: 2022/08/22 18:47:35 by vismaily         ###   ########.fr       */
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
			typedef value_type*			pointer;
			typedef const value_type*	const_pointer;
			typedef ptrdiff_t			difference_type;
			typedef size_t				size_type;

			/* Member types (iterators) */
		
		/* Constructers and Destructer */
		public:
			explicit	vector(const allocator_type &alloc = allocator_type());
			//explicit	vector( size_type n,
			//					const value_type &val = value_type(),
			//					const allocator_type &alloc = allocator_type());

		/* Member functions (capacity) */
		public:
			size_type					size() const;
			//max_size
			//resize
			size_type					capacity() const;
			//empty
			//reserve
			//shrinktofit

		/* Member data */
		private:
			size_type					_size;
			size_type					_capacity;
			pointer						*_array;
			allocator_type				_alloc;
	};
}

# include "vectorImpl.tpp"

#endif
