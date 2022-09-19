/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:22:46 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/19 13:53:10 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FUNCTIONAL_HPP
# define FT_FUNCTIONAL_HPP

namespace	ft
{
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
}

#endif
