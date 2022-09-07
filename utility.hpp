/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:01:14 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/07 14:19:48 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILITY_HPP
# define FT_UTILITY_HPP

namespace	ft
{
	/*===============================*/
	/*              Pair             */
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
	};

	template <typename T1, typename t2>
	pair::pair() : first(), second()
	{
	}

	template <typename T1, typename t2>
	pair::pair(const first_type &a, const second_type &b) : first(a), second(b)
	{
	}
}

#endif
