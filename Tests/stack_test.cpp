/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:14:23 by vismaily          #+#    #+#             */
/*   Updated: 2022/09/06 17:28:13 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <stdexcept>
#include "../Containers/stack.hpp"

#ifndef	MYCOLORS_HPP
# define MYCOLORS_HPP

# define COLOR_YELLOW_B "\033[1;33m"
# define COLOR_PURPLE_B "\033[1;35m"
# define COLOR_BLUE_B "\033[1;34m"
# define COLOR_GREEN_B "\033[1;32m"
# define COLOR_GREEN "\033[0;32m"
# define COLOR_RED_B "\033[1;31m"
# define COLOR_END "\033[0m"

static void	example1()
{
	/* Example 1 */
	/* Example for constructor without parametrs */
	/* Example for size and push_back */

	std::stack<int, std::vector<int> >	st;
	std::cout << COLOR_PURPLE_B << "Example 1" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::stack -> size: " << st.size();
	st.push(42);
	std::cout << ", push[42] top: " << st.top();
	std::cout << ", size: " << st.size();
	st.push(84);
	std::cout << ", push[84] top: " << st.top();
	std::cout << ", size: " << st.size();
	st.push(168);
	std::cout << ", push[168] top: " << st.top();
	std::cout << ", size: " << st.size();
	st.push(336);
	st.push(672);
	std::cout << ", push[336],[672] top: " << st.top();
	st.pop();
	std::cout << ", pop and top: " << st.top();
	std::cout << ", empty: " << st.empty();
	std::cout << ", size: " << st.size() << '.';
	std::cout << COLOR_END << std::endl;

	ft::stack<int>	ft_st;
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::stack  -> size: " << ft_st.size();
	ft_st.push(42);
	std::cout << ", push[42] top: " << ft_st.top();
	std::cout << ", size: " << ft_st.size();
	ft_st.push(84);
	std::cout << ", push[84] top: " << ft_st.top();
	std::cout << ", size: " << ft_st.size();
	ft_st.push(168);
	std::cout << ", push[168] top: " << ft_st.top();
	std::cout << ", size: " << ft_st.size();
	ft_st.push(336);
	ft_st.push(672);
	std::cout << ", push[336],[672] top: " << ft_st.top();
	ft_st.pop();
	std::cout << ", pop and top: " << ft_st.top();
	std::cout << ", empty: " << ft_st.empty();
	std::cout << ", size: " << ft_st.size() << '.' << std::endl;
	std::cout << COLOR_END << std::endl;
}

static void	example2()
{
	/* Example 2 */
	/* Example for deque */

	std::stack<int, std::deque<int> >	st;
	std::cout << COLOR_PURPLE_B << "Example 2" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "std::stack -> size: " << st.size();
	st.push(42);
	std::cout << ", push[42] top: " << st.top();
	std::cout << ", size: " << st.size();
	st.push(84);
	std::cout << ", push[84] top: " << st.top();
	std::cout << ", size: " << st.size();
	st.push(168);
	std::cout << ", push[168] top: " << st.top();
	std::cout << ", size: " << st.size();
	st.push(336);
	st.push(672);
	std::cout << ", push[336],[672] top: " << st.top();
	st.pop();
	std::cout << ", pop and top: " << st.top();
	std::cout << ", empty: " << st.empty();
	std::stack<int, std::deque<int> >	st2;
	std::cout << ", ==: " << (st == st2);
	std::cout << ", !=: " << (st != st2);
	std::cout << ", >: " << (st > st2);
	std::cout << ", >=: " << (st >= st2);
	std::cout << ", <: " << (st < st2);
	std::cout << ", <=: " << (st <= st2);
	st2.push(42);
	st2.push(84);
	st2.push(168);
	st2.push(336);
	std::cout << ", ==: " << (st == st2);
	std::cout << ", !=: " << (st != st2);
	std::cout << ", >: " << (st > st2);
	std::cout << ", >=: " << (st >= st2);
	std::cout << ", <: " << (st < st2);
	std::cout << ", <=: " << (st <= st2);
	std::cout << ", size: " << st.size();
	st2.pop();
	st2 = st;
	std::cout << ", top: " << st2.top();
	std::cout << ", size: " << st2.size() << '.';
	std::cout << COLOR_END << std::endl;

	ft::stack<int, std::deque<int> >	ft_st;
	std::cout << COLOR_GREEN_B;
	std::cout << "ft::stack  -> size: " << ft_st.size();
	ft_st.push(42);
	std::cout << ", push[42] top: " << ft_st.top();
	std::cout << ", size: " << ft_st.size();
	ft_st.push(84);
	std::cout << ", push[84] top: " << ft_st.top();
	std::cout << ", size: " << ft_st.size();
	ft_st.push(168);
	std::cout << ", push[168] top: " << ft_st.top();
	std::cout << ", size: " << ft_st.size();
	ft_st.push(336);
	ft_st.push(672);
	std::cout << ", push[336],[672] top: " << ft_st.top();
	ft_st.pop();
	std::cout << ", pop and top: " << ft_st.top();
	std::cout << ", empty: " << ft_st.empty();
	ft::stack<int, std::deque<int> >	ft_st2;
	std::cout << ", ==: " << (ft_st == ft_st2);
	std::cout << ", !=: " << (ft_st != ft_st2);
	std::cout << ", >: " << (ft_st > ft_st2);
	std::cout << ", >=: " << (ft_st >= ft_st2);
	std::cout << ", <: " << (ft_st < ft_st2);
	std::cout << ", <=: " << (ft_st <= ft_st2);
	ft_st2.push(42);
	ft_st2.push(84);
	ft_st2.push(168);
	ft_st2.push(336);
	std::cout << ", ==: " << (ft_st == ft_st2);
	std::cout << ", !=: " << (ft_st != ft_st2);
	std::cout << ", >: " << (ft_st > ft_st2);
	std::cout << ", >=: " << (ft_st >= ft_st2);
	std::cout << ", <: " << (ft_st < ft_st2);
	std::cout << ", <=: " << (ft_st <= ft_st2);
	std::cout << ", size: " << ft_st.size();
	ft_st2.pop();
	ft_st2 = ft_st;
	std::cout << ", top: " << ft_st2.top();
	std::cout << ", size: " << ft_st2.size() << '.';
	std::cout << COLOR_END << std::endl;
}

void	stack_test()
{
	example1();
	example2();
}

#endif
