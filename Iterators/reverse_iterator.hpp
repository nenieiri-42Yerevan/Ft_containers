/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:36:06 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/02 17:14:06 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REVERSE_ITERATOR_HPP
# define FT_REVERSE_ITERATOR_HPP

# include "iterator.hpp"

namespace	ft
{
	template <typename It>
	class	reverse_iterator
	{
		public:
			typedef It												iterator_type;
			typedef typename iterator_traits<It>::iterator_category	iterator_category;
			typedef typename iterator_traits<It>::value_type		value_type;
			typedef typename iterator_traits<It>::difference_type	difference_type;
			typedef typename iterator_traits<It>::pointer			pointer;
			typedef typename iterator_traits<It>::reference			reference;
		public:
			reverse_iterator();
			explicit		reverse_iterator(iterator_type it);

			template <typename Iter>
			reverse_iterator (const reverse_iterator<Iter> &other);

			virtual			~reverse_iterator();
		public:
			iterator_type			base() const;
			reverse_iterator<It>	&operator=(const reverse_iterator &other);
			reference				operator*() const;
			pointer					operator->() const;
			reverse_iterator<It>	operator-(difference_type n) const;
			reverse_iterator<It>	operator+(difference_type n) const;
			reverse_iterator<It>	&operator-=(difference_type n);
			reverse_iterator<It>	&operator+=(difference_type n);
			reverse_iterator<It>	&operator--();
			reverse_iterator<It>	operator--(int);
			reverse_iterator<It>	&operator++();
			reverse_iterator<It>	operator++(int);
			reference				operator[](difference_type n) const;
		protected:
			iterator_type	_elem;
	};
}

# include "reverse_iterator.tpp"

#endif
