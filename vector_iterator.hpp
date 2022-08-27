/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:36:50 by vismaily          #+#    #+#             */
/*   Updated: 2022/08/27 16:32:35 by vismaily         ###   ########.fr       */
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
			vector_iterator();
			vector_iterator(const vector_iterator &other);
			vector_iterator		&operator=(const vector_iterator &other);
			~vector_iterator();
		public:
			bool				operator==(const vector_iterator &other) const;
			bool				operator!=(const vector_iterator &other) const;
			reference			operator*() const;
			pointer				operator->() const;
			vector_iterator<T>	&operator++();
			vector_iterator<T>	operator++(int);
			vector_iterator<T>	&operator--();
			vector_iterator<T>	operator--(int);
			reference			operator[](difference_type num) const;
			vector_iterator<T>	operator+(difference_type num) const;
			vector_iterator<T>	operator-(difference_type num) const;
			vector_iterator<T>	&operator+=(difference_type num);
			vector_iterator<T>	&operator-=(difference_type num);
			difference_type		operator-(const vector_iterator<T> &other) const;
			bool				operator>(const vector_iterator<T> &other) const;
			bool				operator<(const vector_iterator<T> &other) const;
			bool				operator>=(const vector_iterator<T> &other) const;
			bool				operator<=(const vector_iterator<T> &other) const;
		private:
			pointer				_elem;
	};
}

#endif
