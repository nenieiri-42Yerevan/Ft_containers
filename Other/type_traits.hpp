/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:48:05 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/08 13:55:01 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPE_TRAITS_HPP
# define FT_TYPE_TRAITS_HPP

namespace	ft
{
	/*===================================*/
	/*         Integral_constant         */
	/*===================================*/

	template <typename T, T v>
	struct	integral_constant
	{
		typedef T						value_type;
		typedef integral_constant<T, v>	type;
		static const T					value = v;
		operator T() {return v;}
	};

	typedef ft::integral_constant<bool, true>	true_type;
	typedef ft::integral_constant<bool, false>	false_type;

	/*===================================*/
	/*            Is_integral            */
	/*===================================*/

	template <typename T> struct	is_integral : ft::integral_constant<bool, false> {};

	template <> struct	is_integral<bool> : ft::integral_constant<bool, true> {};
	template <> struct	is_integral<char> : ft::integral_constant<char, true> {};
	template <> struct	is_integral<signed char> : ft::integral_constant<signed char, true> {};
	template <> struct	is_integral<unsigned char> : ft::integral_constant<unsigned char, true> {};
	template <> struct	is_integral<short> : ft::integral_constant<short, true> {};
	template <> struct	is_integral<unsigned short> : ft::integral_constant<unsigned short, true> {};
	template <> struct	is_integral<int> : ft::integral_constant<int, true> {};
	template <> struct	is_integral<unsigned int> : ft::integral_constant<unsigned int, true> {};
	template <> struct	is_integral<long> : ft::integral_constant<long, true> {};
	template <> struct	is_integral<unsigned long> : ft::integral_constant<unsigned long, true> {};
	template <> struct	is_integral<long long> : ft::integral_constant<long long, true> {};
	template <> struct	is_integral<unsigned long long> : ft::integral_constant<unsigned long long, true> {};
	template <> struct	is_integral<wchar_t> : ft::integral_constant<wchar_t, true> {};
	template <> struct	is_integral<char16_t> : ft::integral_constant<char16_t, true> {};

	/*===================================*/
	/*             Enable_if             */
	/*===================================*/

	template <bool B, class T = void>
	struct enable_if
	{
	};

	template <class T>
	struct enable_if<true, T>
	{
		typedef T			type;
	};

	/*===================================*/
	/*             Is_same               */
	/*===================================*/

	template <typename T, typename U>
	struct	is_same : ft::false_type
	{
	};

	template <typename T>
	struct	is_same<T, T> : ft::true_type
	{
	};
}

#endif
