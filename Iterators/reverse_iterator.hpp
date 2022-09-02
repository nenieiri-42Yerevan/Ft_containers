/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:36:06 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/02 14:51:37 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REVERSE_ITERATOR_HPP
# define FT_REVERSE_ITERATOR_HPP

# include "iterator.hpp"

namespace	ft
{
	template <typename It>
	class	reverse_iterator
	{
		public:
			typedef It										iterator_type;
			typedef iterator_traits<It>::iterator_category	iterator_category;
			typedef iterator_traits<It>::value_type			value_type;
			typedef iterator_traits<It>::difference_type	difference_type;
			typedef iterator_traits<It>::pointer			pointer;
			typedef iterator_traits<It>::reference			reference;
		public:
			reverse_iterator();
			virtual	~reverse_iterator();
		protected:
			It		_elem;
	};
}

#endif
