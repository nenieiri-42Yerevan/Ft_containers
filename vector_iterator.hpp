/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:36:50 by vismaily          #+#    #+#             */
/*   Updated: 2022/08/27 13:41:42 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_ITERATOR_HPP
# define FT_VECTOR_ITERATOR_HPP

# include "iterator.hpp"

namespace	ft
{
	template <typename T>
	class	vector_iterator : public iterator<random_access_iterator_tag, T>
	{
		public:

	};
}

#endif
