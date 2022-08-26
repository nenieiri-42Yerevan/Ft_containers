/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:47:53 by vismaily          #+#    #+#             */
/*   Updated: 2022/08/26 16:24:11 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ft_ITERATOR_HPP
# define ft_ITERATOR_HPP

struct	input_iterator_tag
{
};

struct	output_iterator_tag
{
};

struct	forward_iterator_tag : public input_iterator_tag
{
};

struct	bidirectional_iteraotr_tag : public forward_iterator_tag
{
};

struct	random_access_iterator_tag : public bidirectional_iteraotr_tag
{
};

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

#endif
