/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:22:46 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/21 17:40:54 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FUNCTIONAL_HPP
# define FT_FUNCTIONAL_HPP

namespace	ft
{
	template <typename Arg, typename Result>
	struct	unary_function
	{
		typedef Arg		argument_type;
		typedef Result	result_type;
	};

	template <typename Arg1, typename Arg2, typename Result>
	struct	binary_function
	{
		typedef Arg1 	first_argument_type;
		typedef Arg2 	second_argument_type;
		typedef Result	result_type;
	};

	template <typename T>
	struct	less : binary_function<T, T, bool>
	{
		bool	operator()(const T &x, const T &y) const
		{
			return (x < y);
		}
	};

	template <typename Pair>
	struct	select_first : unary_function<Pair, typename Pair::first_type>
	{
		typename Pair::first_type	&operator()(Pair &x)
		{
			return (x.first);
		}
	};

	template <typename T>
	struct	select_self : unary_function<T, T>
	{
		T	&operator()(T &x)
		{
			return (x);
		}
	};
}

#endif
