/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:13:48 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/06 13:09:39 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_HPP
# define FT_STACK_HPP

# include "vector.hpp"

namespace	ft
{
	template <typename T, typename Container = vector<T>>
	class	stack
	{
		/* Member types */
		public:
			typedef Container					container_type;
			typedef Container::value_type		value_type;
			typedef Container::size_type		size_type;
			typedef Container::reference		reference;
			typedef Container::const_reference	const_reference;

		/* Constructers and Destructer */
		public:
			explicit		stack(const container_type &cont = container_type());
			stack			&operator=(const stack &other);
			~stack();

		/* Member funstions */
		public:
			reference			&top();
			const_reference		&top() const;
			bool				empty() const;
			size_type			size() const;
			void				push(const_reference value);
			void				pop();

		/* Non-member funstions */
		public:
			template <typename T, typename Container>
			friend bool	operator==(const stack<T, Container> &lhs, \
									const stack<T, Container> &rhs);

			template <typename T, typename Container>
			friend bool	operator!=(const stack<T, Container> &lhs, \
									const stack<T, Container> &rhs);

			template <typename T, typename Container>
			friend bool	operator>(const stack<T, Container> &lhs, \
									const stack<T, Container> &rhs);

			template <typename T, typename Container>
			friend bool	operator>=(const stack<T, Container> &lhs, \
									const stack<T, Container> &rhs);

			template <typename T, typename Container>
			friend bool	operator<(const stack<T, Container> &lhs, \
									const stack<T, Container> &rhs);

			template <typename T, typename Container>
			friend bool	operator<=(const stack<T, Container> &lhs, \
									const stack<T, Container> &rhs);

		protected:
			container_type	_cont;
	};
}

# include "stack_impl.tpp"

#endif
