/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:36:17 by daparici          #+#    #+#             */
/*   Updated: 2025/03/17 17:37:10 by daparici         ###   ########.fr       */
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

	std::deque<T> sort(const std::deque<T> &array) const;
	std::vector<T> sort(const std::vector<T> &array) const ;
};

# include "../src/PmergeMe.tpp"