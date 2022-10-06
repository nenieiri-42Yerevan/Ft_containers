/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_node.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:21:57 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/06 14:18:27 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RB_NODE_HPP
# define FT_RB_NODE_HPP

namespace	ft
{
	typedef enum e_rb_color
	{
		BLACK,
		RED
	}				t_rb_color;

	template <typename T>
	struct	rb_node
	{
		rb_node();
		rb_node(const T &elem);
		rb_node(const rb_node &other);
		rb_node		&operator=(const rb_node &other);
		~rb_node();

		T			data;
		rb_node		*left;
		rb_node		*right;
		rb_node		*p;
		t_rb_color	color;
	};
}

# include "rb_node_impl.tpp"

#endif
