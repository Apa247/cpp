/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:36:17 by daparici          #+#    #+#             */
/*   Updated: 2025/02/23 16:07:23 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>

# define VERBOSE false

template <typename T, template <typename, typename> class Container>
class PmergeMe
{
	public:
	PmergeMe<T, Container>(void);
	PmergeMe<T, Container>(const PmergeMe<T, Container> &src);
	~PmergeMe<T, Container>(void);
	PmergeMe<T, Container>	&operator =(const PmergeMe<T, Container> &src);

	Container<T, std::allocator<T> > sort(const Container<T, std::allocator<T> > &array) const;
};

# include "../src/PmergeMe.tpp"