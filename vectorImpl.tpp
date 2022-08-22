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
	template <typename T, typename Allocator>
	vector<T, Allocator>::vector(const allocator_type &alloc)
	{
		_size = 0;
		_capacity = 0;
		_array = NULL;
	}
}

#endif
