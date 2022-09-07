/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_impl.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:01:14 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/07 14:32:58 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILITY_IMPL_TPP
# define FT_UTILITY_IMPL_TPP

# ifndef FT_UTILITY_HPP
#  error utility_impl.tpp should only be included from utility.hpp.
# endif

namespace	ft
{
	/*===============================*/
	/*              pair             */
	/*===============================*/

	template <typename T1, typename T2>
	pair<T1, T2>::pair() : first(), second()
	{
	}

	template <typename T1, typename T2>
	pair<T1, T2>::pair(const first_type &a, const second_type &b) : first(a), second(b)
	{
	}

	template <typename T1, typename T2>
	template <typename U1, typename U2>
	pair<T1, T2>::pair(const pair<U1, U2> &other) :
		first(other.first),
		second(other.second)
	{
	}

	template <typename T1, typename T2>
	pair<T1, T2>	&pair<T1, T2>::operator=(const pair &rhs)
	{
		if (this != &rhs)
		{
			this->first = rhs.first;
			this->second = rhs.second;
		}
		return (*this);
	}

	template <typename T1, typename T2>
	bool	operator==(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <typename T1, typename T2>
	bool	operator!=(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <typename T1, typename T2>
	bool	operator<(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs)
	{
		if (lhs.first < rhs.first)
			return (true);
		else if (lhs.first == rhs.first)
			return (lhs.second < rhs.second);
		return (false);
	}

	template <typename T1, typename T2>
	bool	operator<=(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs)
	{
		return (!(rhs < lhs));
	}

	template <typename T1, typename T2>
	bool	operator>(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs)
	{
		return (rhs < lhs);
	}

	template <typename T1, typename T2>
	bool	operator>=(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs)
	{
		return (!(lhs < rhs));
	}

	/*================================*/
	/*           make_pair            */
	/*================================*/

	template <typename T1, typename T2>
	pair<T1, T2>	make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}
}

#endif
