/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:44:23 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/13 18:37:56 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
# define FT_MAP_HPP

# include <memory>
# include <functional>
# include "../Other/utility.hpp"
# include "../Other/binary_search_tree.hpp"

namespace	ft
{
	template <
		typename Key,
		typename T,
		typename Compare = std::less<Key>,
		typename Allocator = std::allocator<ft::pair<const Key, T> >,
	> class	map
	{
		/* Member types */
		public:
			typedef Key						key_type;
			typedef T						mapped_type;
			typedef ft::pair<const Key, T>	value_type;
			typedef Comapre					key_compare;
			typedef size_t					size_type;
			typedef ptrdiff_t				difference_type;
			typedef Allocator				allocator_type;
			typedef value_type				&reference;
			typedef const value_type		&const_reference;
			// pointer
			// const_pointer
			// iterator
			// const_iterator
			// reverse_iterator
			// const_reverse_iterator

			// value_compare

		/* Member data */
		private:
			binary_search_tree				_tree;
	};
}

#endif
