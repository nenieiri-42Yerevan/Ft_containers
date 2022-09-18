/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:44:23 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/18 14:41:38 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
# define FT_MAP_HPP

# include <memory>
# include "../Other/utility.hpp"
# include "../Other/binary_search_tree.hpp"
# include "../Other/functional.hpp"

namespace	ft
{
	template <
		typename Key,
		typename T,
		typename Compare = ft::less<Key>,
		typename Allocator = std::allocator<ft::pair<const Key, T> >
	> class	map
	{
		/* Member types */
		public:
			typedef Key						key_type;
			typedef T						mapped_type;
			typedef ft::pair<const Key, T>	value_type;
			typedef Compare					key_compare;
			typedef size_t					size_type;
			typedef ptrdiff_t				difference_type;
			typedef Allocator				allocator_type;
			typedef value_type				&reference;
			typedef const value_type		&const_reference;
			typedef value_type				*pointer;
			typedef const value_type		*const_pointer;

			typedef typename binary_search_tree<value_type, key_compare, \
				allocator_type, false>::iterator	iterator;
			typedef typename binary_search_tree<value_type, key_compare, \
				allocator_type, false>::const_iterator	const_iterator;
			typedef typename binary_search_tree<value_type, key_compare, \
				allocator_type, false>::reverse_iterator	reverse_iterator;
			typedef typename binary_search_tree<value_type, key_compare, \
				allocator_type, false>::const_reverse_iterator	const_reverse_iterator;

		/* Constructors and destructors */
		public:
			explicit	map(const key_compare &comp = key_compare(),
							const allocator_type &alloc = allocator_type());
/*
			template <typename InputIterator>
			map(InputIterator first, InputIterator last,
					const key_compare &comp = key_compare(),
					const allocator_type &alloc = allocator_type());

			map(const map &x);
*/

		/* Iterators */
		public:
			iterator						begin();
			const_iterator					begin() const;
			iterator						end();
			const_iterator					end() const;
			// rbegin
			// rend

		/* Capacity */
		public:
			bool							empty() const;
			size_type						size() const;
			size_type						max_size() const;

		/* Modifires */
		public:
			void	insert(const value_type &val);

		/* Member data */
		private:
			binary_search_tree<value_type, key_compare, allocator_type, false> _tree;
	};
}

# include "map_impl.tpp"

#endif
