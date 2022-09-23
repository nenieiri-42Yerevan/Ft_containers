/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:36:06 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/22 19:22:33 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REVERSE_ITERATOR_HPP
# define FT_REVERSE_ITERATOR_HPP

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

	template <typename It1, typename It2>
	bool	operator==(const reverse_iterator<It1> &lhs, \
						const reverse_iterator<It2> &rhs);

	template <typename It1, typename It2>
	bool	operator!=(const reverse_iterator<It1> &lhs, \
						const reverse_iterator<It2> &rhs);

	template <typename It1, typename It2>
	bool	operator<(const reverse_iterator<It1> &lhs, \
						const reverse_iterator<It2> &rhs);

	template <typename It1, typename It2>
	bool	operator<=(const reverse_iterator<It1> &lhs, \
						const reverse_iterator<It2> &rhs);

	template <typename It1, typename It2>
	bool	operator>(const reverse_iterator<It1> &lhs, \
						const reverse_iterator<It2> &rhs);

	template <typename It1, typename It2>
	bool	operator>=(const reverse_iterator<It1> &lhs, \
						const reverse_iterator<It2> &rhs);

	template <typename It>
	reverse_iterator<It> operator+(typename reverse_iterator<It>::difference_type n, \
									const reverse_iterator<It> &it);

	template <typename It>
	typename reverse_iterator<It>::difference_type \
	operator-(const reverse_iterator<It> &lhs, const reverse_iterator<It> &rhs);

	template <typename L_It, typename R_It>
	typename reverse_iterator<R_It>::difference_type \
	operator-(const reverse_iterator<L_It> &lhs, const reverse_iterator<R_It> &rhs);
}

# include "reverse_iterator_impl.tpp"

#endif
