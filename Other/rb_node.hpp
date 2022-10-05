/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_node.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:21:57 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/05 11:40:56 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RB_NODE_HPP
# define FT_RB_NODE_HPP

namespace	ft
{
	template <typename T>
	struct	rb_node
	{
		rb_node();
		rb_node(const T &elem);
		rb_node(const binary_node &other);
		rb_node		&operator=(const rb_node &other);
		~rb_node();

		T			data;
		rb_node		*left;
		rb_node		*right;
		rb_node		*p;
		bool		color; // 0 == black; 1 == red
	};
}

# include "rb_node_impl.tpp"

#endif
