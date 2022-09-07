/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:01:14 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/07 15:23:22 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILITY_HPP
# define FT_UTILITY_HPP

namespace	ft
{
	/*===============================*/
	/*              pair             */
	/*===============================*/

	template <typename T1, typename T2>
	struct	pair
	{
		typedef T1		first_type;
		typedef T2		second_type;

		first_type		first;
		second_type		second;

		pair();
		pair(const first_type &a, const second_type &b);
		template <typename U1, typename U2> pair(const pair<U1, U2> &pr);

		pair			&operator=(const pair &rhs);
	};

	template <typename T1, typename T2>
	bool	operator==(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs);

	template <typename T1, typename T2>
	bool	operator!=(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs);

	template <typename T1, typename T2>
	bool	operator<(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs);

	template <typename T1, typename T2>
	bool	operator<=(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs);

	template <typename T1, typename T2>
	bool	operator>(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs);

	template <typename T1, typename T2>
	bool	operator>=(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs);

	/*================================*/
	/*           make_pair            */
	/*================================*/

	template <typename T1, typename T2>
	pair<T1, T2>	make_pair(T1 x, T2 y);
}

# include "utility_impl.tpp"

#endif
