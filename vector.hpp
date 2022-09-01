/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:22:31 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/01 16:10:56 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <memory>
# include <cstddef>
# include <stdexcept>
# include <string>
# include "random_access_iterator.hpp"
# include "type_traits.hpp"

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
			typedef value_type			&reference;
			typedef const value_type	&const_reference;
			typedef value_type			*pointer;
			typedef const value_type	*const_pointer;
			typedef ptrdiff_t			difference_type;
			typedef size_t				size_type;
			/* Member types (iterators) */
			typedef random_access_iterator<T>			iterator;
			typedef random_access_iterator<const T>		const_iterator;
//			typedef reverse_iterator<iterator>			reverse_iterator
//			typedef reverse_iterator<const_iterator>	const_reverse_iterator;
		
		/* Constructers and Destructer */
		public:
			explicit	vector(const allocator_type &alloc = allocator_type());
			explicit	vector( size_type n,
								const value_type &val = value_type(),
								const allocator_type &alloc = allocator_type());
	
			template <typename InputIterator>
			vector(InputIterator first, InputIterator last,
					const allocator_type &alloc = allocator_type(),
			typename enable_if<!is_integral<InputIterator>::value, 
								InputIterator>::type* = 0);

			vector(const vector &other);
			vector	&operator=(const vector &other);
			~vector();

		/* Member functions (Iterators) */
		public:
			iterator					begin();
			const_iterator				begin() const;
			iterator					end();
			const_iterator				end() const;
			// rbegin
			// rend

		/* Member functions (Capacity) */
		public:
			size_type					size() const;
			size_type					max_size() const;
			void						resize(size_type n, value_type val = value_type());
			size_type					capacity() const;
			bool						empty() const;
			void						reserve(size_type new_cap);

		/* Member functions (Element access) */
		public:
			reference					operator[](size_type pos);
			const_reference				operator[](size_type pos) const;
			reference					at(size_type pos);
			const_reference				at(size_type pos) const;
			reference					front();
			const_reference				front() const;
			reference					back();
			const_reference				back() const;
			pointer						data();
			const_pointer				data() const;

		/* Member functions (Modifiers) */
		public:
			//assign
			void						push_back(const value_type &val);
			void						pop_back();
			iterator					insert(iterator pos, const T &value);
			void						insert(iterator pos,size_type count, \
												const T &value);

			template <class InputIt>
			void			insert(iterator pos, InputIt first, InputIt last,
				typename enable_if<!is_integral<InputIt>::value, InputIt>::type* = 0);

			iterator					erase(iterator pos);
			iterator					erase(iterator first, iterator last);
			//swap
			void						clear();

		/* Member functions (Allocator) */
		public:
			allocator_type				get_allocator() const;

		/* Member data */
		private:
			size_type					_size;
			size_type					_capacity;
			pointer						_array;
			allocator_type				_alloc;
	};
}

# include "vector_impl.tpp"

#endif
