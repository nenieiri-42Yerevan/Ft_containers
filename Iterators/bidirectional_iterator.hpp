/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:08:57 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/08 14:03:09 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIDIRECTIONAL_ITERATOR_HPP
# define FT_BIDIRECTIONAL_ITERATOR_HPP

# include "iterator.hpp"

namespace	ft
{
	template <
		typename T,
		typename pair_type
	> class	bidirectional_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
            typedef ft::iterator<ft::bidirectional_iterator_tag, T>	iterator_type;
            typedef ft::iterator<ft::bidirectional_iterator_tag, pair_type> \
															iterator_pair_type;

			typedef typename iterator_type::iterator_category	iterator_category;
			typedef typename iterator_type::pointer				node_pointer;
			typedef typename iterator_type::reference			node_reference;
			typedef typename iterator_type::value_type			value_type;
			typedef typename iterator_type::difference_type		difference_type;

			typedef typename iterator_pair_type::pointer		pointer;
			typedef typename iterator_pair_type::reference		reference;
		public:
			bidirectional_iterator();
			bidirectional_iterator(node_pointer null_node, node_pointer ptr);
			bidirectional_iterator(const bidirectional_iterator &other);
			bidirectional_iterator		&operator=(const bidirectional_iterator &other);
			operator					bidirectional_iterator \
											<const T, const pair_type> () const;
			virtual						~bidirectional_iterator();
		public:
			bidirectional_iterator<T, pair_type>	&operator++();
			bidirectional_iterator<T, pair_type>	operator++(int);
			bidirectional_iterator<T, pair_type>	&operator--();
			bidirectional_iterator<T, pair_type>	operator--(int);
			pair_type								&operator*() const;
			pair_type								*operator->() const;
			node_pointer							get_node() const;

			bool		operator==(const bidirectional_iterator &other) const;
			bool		operator!=(const bidirectional_iterator &other) const;
		private:
			node_pointer							_null_node;
			node_pointer							_elem;
	};
}

# include "bidirectional_iterator_impl.tpp"

#endif 
