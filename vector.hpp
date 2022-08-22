/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:22:31 by vismaily          #+#    #+#             */
/*   Updated: 2022/08/22 15:06:18 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <memory>

namespace	ft
{
	template <
		typename T,
		typename Allocator = std::allocator<T>
	> class	vector
	{
		/* Member types */
		public:
			typedef T			value_type;
			typedef Allocator	allocator_type;
		
		/* Constructers and Destructer */
		public:
			explicit	vector(const allocator_type &alloc = allocator_type());
	};
}

# include "vectorImpl.tpp"

#endif
