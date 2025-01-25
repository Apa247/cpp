/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:50:19 by daparici          #+#    #+#             */
/*   Updated: 2025/01/25 17:11:46 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <iostream>
#include <string>
#include <list>
#include <stdlib.h>
#include <time.h>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		// Constructors & Destructor
		MutantStack(void);
		MutantStack(const MutantStack &src);
		virtual ~MutantStack();

		// Operator Overloads
		MutantStack &operator=(const MutantStack &rhs);

		// Iterator Functions
		typedef typename std::stack<T>::container_type::iterator 			iterator;
		typedef typename std::stack<T>::container_type::const_iterator 	const_iterator;
		iterator 			begin(void);
		const_iterator 		begin(void) const;
		iterator 			end(void);
		const_iterator 		end(void) const;
};

#include "../src/MutantStack.tpp"