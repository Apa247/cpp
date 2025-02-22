/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:36:17 by daparici          #+#    #+#             */
/*   Updated: 2025/02/20 19:45:17 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>

template <typename T, template <typename, typename> class Container>
class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(Container<T, std::allocator<T> > const & src);
		PmergeMe(PmergeMe const & src);
		~PmergeMe();
		PmergeMe & operator=(PmergeMe const & src);

		Container<T, std::allocator<T> > sort(const Container<T, std::allocator<T> > & array) const;
};