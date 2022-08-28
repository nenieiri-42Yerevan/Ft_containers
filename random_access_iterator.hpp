/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:36:50 by vismaily          #+#    #+#             */
/*   Updated: 2022/08/28 13:23:02 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANDOM_ACCESS_ITERATOR_HPP
# define FT_RANDOM_ACCESS_ITERATOR_HPP

# include "iterator.hpp"

namespace	ft
{
	template <typename T>
	class	random_access_iterator : public iterator<random_access_iterator_tag, T>
	{
		public:
			typedef random_access_iterator_tag	iterator_category;
            typedef T*							pointer;
            typedef T&							reference;
            typedef std::ptrdiff_t				difference_type;
            typedef T							value_type;
		public:
			random_access_iterator();
			random_access_iterator(pointer	ptr);
			random_access_iterator(const random_access_iterator &other);
			random_access_iterator		&operator=(const random_access_iterator &other);
			virtual						~random_access_iterator();
		public:
			bool						operator==(const random_access_iterator &other) const;
			bool						operator!=(const random_access_iterator &other) const;
			reference					operator*() const;
			pointer						operator->() const;
			random_access_iterator<T>	&operator++();
			random_access_iterator<T>	operator++(int);
			random_access_iterator<T>	&operator--();
			random_access_iterator<T>	operator--(int);
			reference					operator[](difference_type num) const;
			random_access_iterator<T>	operator+(difference_type num) const;
			random_access_iterator<T>	operator-(difference_type num) const;
			random_access_iterator<T>	&operator+=(difference_type num);
			random_access_iterator<T>	&operator-=(difference_type num);
			difference_type				operator-(const random_access_iterator<T> &other) const;
			bool						operator>(const random_access_iterator<T> &other) const;
			bool						operator<(const random_access_iterator<T> &other) const;
			bool						operator>=(const random_access_iterator<T> &other) const;
			bool						operator<=(const random_access_iterator<T> &other) const;
		private:
			pointer						_elem;
	};
}

# include "random_access_iterator.tpp"

#endif
