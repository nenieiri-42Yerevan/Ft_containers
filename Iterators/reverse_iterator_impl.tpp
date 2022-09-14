/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator_impl.tpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:36:06 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/02 14:42:04 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REVERSE_ITERATOR_IMPL_TPP
# define FT_REVERSE_ITERATOR_IMPL_TPP

# ifndef FT_REVERSE_ITERATOR_HPP
#  error reverse_iterator_impl.tpp should only be included from reverse_iterator.hpp.
# endif

namespace	ft
{
	template <typename It>
	reverse_iterator<It>::reverse_iterator()
	{
		this->_elem = It();
	}

	template <typename It>
	reverse_iterator<It>::reverse_iterator(iterator_type it)
	{
		this->_elem = it;
	}

	template <typename It>
	template <typename Iter>
	reverse_iterator<It>::reverse_iterator(const reverse_iterator<Iter> &other)
	{
		this->_elem = other.base();
	}

	template <typename It>
	reverse_iterator<It>::~reverse_iterator()
	{
	}

	template <typename It>
	typename reverse_iterator<It>::iterator_type	reverse_iterator<It>::base() const
	{
		return (this->_elem);
	}

	template <typename It>
	reverse_iterator<It>	&reverse_iterator<It>::operator=(const reverse_iterator &other)
	{
		if (this != &other)
			this->_elem = other._elem;
		return (*this);
	}

	template <typename It>
	typename reverse_iterator<It>::reference	reverse_iterator<It>::operator*() const
	{
		iterator_type	tmp;

		tmp = this->_elem;
		return (*(--tmp));
	}

	template <typename It>
	typename reverse_iterator<It>::pointer	reverse_iterator<It>::operator->() const
	{
		iterator_type	tmp;

		tmp = this->_elem;
		return (&(*--tmp));
	}

	template <typename It>
	reverse_iterator<It>	reverse_iterator<It>::operator-(difference_type n) const
	{
		return (reverse_iterator(this->_elem + n));
	}

	template <typename It>
	reverse_iterator<It>	reverse_iterator<It>::operator+(difference_type n) const
	{
		return (reverse_iterator(this->_elem - n));
	}

	template <typename It>
	reverse_iterator<It>	&reverse_iterator<It>::operator-=(difference_type n)
	{
		this->_elem += n;
		return (*this);
	}

	template <typename It>
	reverse_iterator<It>	&reverse_iterator<It>::operator+=(difference_type n)
	{
		this->_elem -= n;
		return (*this);
	}

	template <typename It>
	reverse_iterator<It>	&reverse_iterator<It>::operator--()
	{
		++(this->_elem);
		return (*this);
	}

	template <typename It>
	reverse_iterator<It>	reverse_iterator<It>::operator--(int)
	{
		reverse_iterator<It>	tmp(*this);
		++(this->_elem);
		return (tmp);
	}

	template <typename It>
	reverse_iterator<It>	&reverse_iterator<It>::operator++()
	{
		--(this->_elem);
		return (*this);
	}

	template <typename It>
	reverse_iterator<It>	reverse_iterator<It>::operator++(int)
	{
		reverse_iterator<It>	tmp(*this);
		--(this->_elem);
		return (tmp);
	}

	template <typename It>
	typename reverse_iterator<It>::reference \
	reverse_iterator<It>::operator[](difference_type n) const
	{
		return (*(this->_elem - n - 1));
	}

	/*============================*/
	/* 	  Non-member functions    */
	/*============================*/

	template <typename It1, typename It2>
	bool	operator==(const reverse_iterator<It1> &lhs, \
						const reverse_iterator<It2> &rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <typename It1, typename It2>
	bool	operator!=(const reverse_iterator<It1> &lhs, \
						const reverse_iterator<It2> &rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <typename It1, typename It2>
	bool	operator<(const reverse_iterator<It1> &lhs, \
						const reverse_iterator<It2> &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <typename It1, typename It2>
	bool	operator<=(const reverse_iterator<It1> &lhs, \
						const reverse_iterator<It2> &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <typename It1, typename It2>
	bool	operator>(const reverse_iterator<It1> &lhs, \
						const reverse_iterator<It2> &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename It1, typename It2>
	bool	operator>=(const reverse_iterator<It1> &lhs, \
						const reverse_iterator<It2> &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <typename It>
	reverse_iterator<It> operator+(typename reverse_iterator<It>::difference_type n, \
									const reverse_iterator<It> &it)
	{
		return (it + n);
	}

	template <typename It>
	typename reverse_iterator<It>::difference_type \
	operator-(const reverse_iterator<It> &lhs, const reverse_iterator<It> &rhs)
	{
		return (rhs.base() - lhs.base());
	}

	template <typename L_It, typename R_It>
	typename reverse_iterator<R_It>::difference_type \
	operator-(const reverse_iterator<L_It> &lhs, const reverse_iterator<R_It> &rhs)
	{
		return (rhs.base() - lhs.base());
	}
}

#endif
