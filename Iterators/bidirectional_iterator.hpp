/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:08:57 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/22 19:47:56 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIDIRECTIONAL_ITERATOR_HPP
# define FT_BIDIRECTIONAL_ITERATOR_HPP

# include "iterator.hpp"

namespace	ft
{
	template <
		typename T,
		typename pair_type
	> class	bidirectional_iterator : public iterator<bidirectional_iteraotr_tag, T>
	{
		public:
			typedef typename iterator<bidirectional_iteraotr_tag, T>::iterator_category \
																iterator_category;
			typedef typename iterator<bidirectional_iteraotr_tag, T>::pointer	node_pointer;
			typedef typename iterator<bidirectional_iteraotr_tag, T>::reference	reference;
			typedef typename iterator<bidirectional_iteraotr_tag, T>::value_type	value_type;
			typedef typename iterator<bidirectional_iteraotr_tag, T>::difference_type \
																difference_type;

			typedef typename iterator<bidirectional_iteraotr_tag, pair_type>::pointer	pointer;
		public:
			bidirectional_iterator();
			bidirectional_iterator(node_pointer head, node_pointer ptr);
			bidirectional_iterator(const bidirectional_iterator &other);
			bidirectional_iterator		&operator=(const bidirectional_iterator &other);
			operator					bidirectional_iterator<const T, const pair_type> () const;
			virtual						~bidirectional_iterator();
		public:
			bidirectional_iterator<T, pair_type>	&operator++();
			bidirectional_iterator<T, pair_type>	operator++(int);
			bidirectional_iterator<T, pair_type>	&operator--();
			bidirectional_iterator<T, pair_type>	operator--(int);
			pair_type								&operator*() const;
			pair_type								*operator->() const;

			bool		operator==(const bidirectional_iterator &other) const;
			bool		operator!=(const bidirectional_iterator &other) const;
		private:
			node_pointer							_head;
			node_pointer							_elem;
	};
}

# include "bidirectional_iterator_impl.tpp"

#endif 
