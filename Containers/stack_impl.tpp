/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_impl.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:13:48 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/05 16:15:32 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_TPP
# define FT_STACK_TPP

# ifndef FT_STACK_HPP
#  error stack_impl.tpp should only be included from stack.hpp.
# endif

namespace	ft
{
	/*===================================*/
    /*    Constructors and Destructor	 */
    /*===================================*/

	template <typename T, typename Container>
	stack<T, Container>::stack(const container_type &cont)
	{
		this->_cont = cont;
	}

	template <typename T, typename Container>
	stack<T, Container>&	stack<T, Container>::operator=(const stack &other)
	{
		if (this != &other)
			this->_cont = other._cont;
		return (*this);
	}

	template <typename T, typename Container>
	stack<T, Container>::~stack()
	{
		this->_cont.clear();
	}

	/*=============================*/
    /*       Member functions      */
    /*=============================*/

	template <typename T, typename Container>
	typename stack<T, Container>::reference	stack<T, Container>::top()
	{
		return (this->_cont.back());
	}

	template <typename T, typename Container>
	typename stack<T, Container>::const_reference	stack<T, Container>::top() const
	{
		return (this->_cont.back());
	}

	template <typename T, typename Container>
	bool	stack<T, Container>::empty() const
	{
		return (this->_cont.empty());
	}

	template <typename T, typename Container>
	typename stack<T, Container>::size_type	stack<T, Container>::size() const
	{
		return (this->_cont.size());
	}

	template <typename T, typename Container>
	void	stack<T, Container>::push(const_reference value)
	{
		this->_cont.push_back(value);
	}

	template <typename T, typename Container>
	void	stack<T, Container>::pop()
	{
		this->_cont.pop_back();
	}

	/*=================================*/
    /*       Non-member functions      */
    /*=================================*/

	template <typename _T, typename _Cont>
	bool	operator==(const stack<_T, _Cont> &lhs, const stack<_T, _Cont> &rhs)
	{
		return (lhs._cont == rhs._cont);
	}

	template <typename _T, typename _Cont>
	bool	operator!=(const stack<_T, _Cont> &lhs, const stack<_T, _Cont> &rhs)
	{
		return (lhs._cont != rhs._cont);
	}

	template <typename _T, typename _Cont>
	bool	operator>(const stack<_T, _Cont> &lhs, const stack<_T, _Cont> &rhs)
	{
		return (lhs._cont > rhs._cont);
	}

	template <typename _T, typename _Cont>
	bool	operator>=(const stack<_T, _Cont> &lhs, const stack<_T, _Cont> &rhs)
	{
		return (lhs._cont >= rhs._cont);
	}

	template <typename _T, typename _Cont>
	bool	operator<(const stack<_T, _Cont> &lhs, const stack<_T, _Cont> &rhs)
	{
		return (lhs._cont < rhs._cont);
	}

	template <typename _T, typename _Cont>
	bool	operator<=(const stack<_T, _Cont> &lhs, const stack<_T, _Cont> &rhs)
	{
		return (lhs._cont <= rhs._cont);
	}
}

#endif
