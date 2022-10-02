/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_node.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:14:03 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/02 14:15:13 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BINARY_NODE_HPP
# define FT_BINARY_NODE_HPP

namespace	ft
{
	/* Node */
	template <typename T>
	struct	binary_node
	{
		binary_node();
		binary_node(const T &elem);
		binary_node(const binary_node &other);
		binary_node		&operator=(const binary_node &other);
		~binary_node();

		T			data;
		binary_node	*left;
		binary_node	*right;
		binary_node	*p;
		bool		multi;
	};
}

# include "binary_node_impl.tpp"

#endif
