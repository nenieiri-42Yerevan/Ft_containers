/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:44:23 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/26 10:06:28 by vismaily         ###   ########.fr       */
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

			typedef typename binary_search_tree<value_type, \
					select_first<value_type>, key_compare, allocator_type, \
					false>::iterator	iterator;
			typedef typename binary_search_tree<value_type, \
					select_first<value_type>, key_compare, allocator_type, \
					false>::const_iterator	const_iterator;
			typedef typename binary_search_tree<value_type, \
					select_first<value_type>, key_compare, allocator_type, \
					false>::reverse_iterator	reverse_iterator;
			typedef typename binary_search_tree<value_type, \
					select_first<value_type>, key_compare, allocator_type, \
					false>::const_reverse_iterator	const_reverse_iterator;

		/* Member clases */
		public:
			class	value_compare : binary_function<value_type, value_type, bool>
			{
				public:
					value_compare(key_compare c) : _comp(c)
					{
					}

					bool	operator()(const value_type &lhs, \
										const value_type &rhs) const
					{
						return (this->_comp(lhs.first, rhs.first));
					}

				protected:
					key_compare	_comp;

				private:
					friend class	map<key_type, value_type, \
										key_compare, allocator_type>;
			};

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
			reverse_iterator				rbegin();
			const_reverse_iterator			rbegin() const;
			reverse_iterator				rend();
			const_reverse_iterator			rend() const;

		/* Capacity */
		public:
			bool							empty() const;
			size_type						size() const;
			size_type						max_size() const;

		/* Element access */
		public:
			//mapped_type						&operator[](const key_type &key);
			//at

		/* Modifires */
		public:
			ft::pair<iterator, bool>		insert(const value_type &val);
			iterator						insert(iterator it, const value_type &val);
			template <class InputIt> void	insert(InputIt first, InputIt last);
			//erase
			//swap
			void							clear();

		/* Observers */
		public:
			key_compare						key_comp() const;
			value_compare					value_comp() const;

		/* Operations */
		public:
			iterator						find(const key_type &key);
			const_iterator					find(const key_type &key) const;
			size_type						count(const key_type &key) const;
			iterator						lower_bound(const key_type &key);
			const_iterator					lower_bound(const key_type &key) const;
			iterator						upper_bound(const key_type &key);
			const_iterator					upper_bound(const key_type &key) const;
			//equal_range

		/* Allocator */
		public:
			allocator_type					get_allocator() const;

		/* Member data */
		private:
			binary_search_tree<value_type, select_first<value_type>, \
								key_compare, allocator_type, false> _tree;
	};
}

# include "map_impl.tpp"

#endif
