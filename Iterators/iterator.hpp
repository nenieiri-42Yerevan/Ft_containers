/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:47:53 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/30 12:23:02 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_HPP
# define FT_ITERATOR_HPP

namespace	ft
{
	/*===================================*/
	/*           Category tags           */
	/*===================================*/

	struct	input_iterator_tag {};
	struct	output_iterator_tag {};
	struct	forward_iterator_tag : public input_iterator_tag {};
	struct	bidirectional_iteraotr_tag : public forward_iterator_tag {};
	struct	random_access_iterator_tag : public bidirectional_iteraotr_tag {};

	/*=================================*/
	/*           Iterator              */
	/*=================================*/

	template <
		typename Category,
		typename T,
		typename Distance = std::ptrdiff_t,
		typename Pointer = T*,
		typename Reference = T&
	> struct	iterator
	{
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};

	/*========================================*/
	/*           Iterator_traits              */
	/*========================================*/

	template <typename Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};

	template <typename T>
	struct iterator_traits<T*>
	{
		typedef random_access_iterator_tag				iterator_category;
		typedef T										value_type;
		typedef ptrdiff_t								difference_type;
		typedef T*										pointer;
		typedef T&										reference;
	};

	template <typename T>
	struct iterator_traits<const T*>
	{
		typedef random_access_iterator_tag				iterator_category;
		typedef T										value_type;
		typedef ptrdiff_t								difference_type;
		typedef const T*								pointer;
		typedef const T&								reference;
	};

	/*====================================*/
	/*               Distance             */
	/*====================================*/

	template <typename InputIt>
	typename ft::iterator_traits<InputIt>::difference_type
	distance(InputIt first, InputIt last)
	{
		typename ft::iterator_traits<InputIt>::difference_type	dist = 0;

		if (first != last)
		{
			++dist;
			++first;
		}
		return (dist);
	}
}

# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"

#endif
