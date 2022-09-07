/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:13:48 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/06 17:48:50 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_HPP
# define FT_STACK_HPP

# include "vector.hpp"

namespace	ft
{
	template <typename T, typename Container = vector<T> >
	class	stack
	{
		/* Member types */
		public:
			typedef Container					container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;

		/* Constructers and Destructer */
		public:
			explicit		stack(const container_type &cont = container_type());
			stack			&operator=(const stack &other);
			~stack();

		/* Member funstions */
		public:
			reference			top();
			const_reference		top() const;
			bool				empty() const;
			size_type			size() const;
			void				push(const_reference value);
			void				pop();

		/* Non-member funstions */
		public:
			template <typename _T, typename _Cont>
			friend bool	operator==(const stack<_T, _Cont> &lhs, \
									const stack<_T, _Cont> &rhs);

			template <typename _T, typename _Cont>
			friend bool	operator!=(const stack<_T, _Cont> &lhs, \
									const stack<_T, _Cont> &rhs);

			template <typename _T, typename _Cont>
			friend bool	operator>(const stack<_T, _Cont> &lhs, \
									const stack<_T, _Cont> &rhs);

			template <typename _T, typename _Cont>
			friend bool	operator>=(const stack<_T, _Cont> &lhs, \
									const stack<_T, _Cont> &rhs);

			template <typename _T, typename _Cont>
			friend bool	operator<(const stack<_T, _Cont> &lhs, \
									const stack<_T, _Cont> &rhs);

			template <typename _T, typename _Cont>
			friend bool	operator<=(const stack<_T, _Cont> &lhs, \
									const stack<_T, _Cont> &rhs);

		protected:
			container_type	_cont;
	};
}

# include "stack_impl.tpp"

#endif
