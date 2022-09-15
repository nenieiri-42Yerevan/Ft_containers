/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_impl.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:44:23 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/13 16:44:23 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_IMPL_TPP
# define FT_MAP_IMPL_TPP

# ifndef FT_MAP_HPP
#  error map_impl.tpp should only be included from map.hpp.
# endif

namespace	ft
{
	/*=====================================*/
	/*     Constructors and destructors    */
	/*=====================================*/

	template <typename Key, typename T, typename Compare, typename Allocator>
	map<Key, T, Compare, Allocator>::map(const key_compare &comp, \
							const allocator_type &alloc) : _tree(comp, alloc)
	{
	}
/*
	template <typename Key, typename T, typename Compare, typename Allocator>
	template <typename InputIterator>
	map<Key, T, Compare, Allocator>::map(InputIterator first, \
					InputIterator last, const key_compare &comp, \
					const allocator_type &alloc)
	{
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	map<Key, T, Compare, Allocator>::map(const map &x)
	{
	}
*/
	/*=====================================*/
	/*     Constructors and destructors    */
	/*=====================================*/

	template <typename Key, typename T, typename Compare, typename Allocator>
	void	map<Key, T, Compare, Allocator>::insert(const value_type &val)
	{
		this->_tree.insert(val);
	}
}

#endif
