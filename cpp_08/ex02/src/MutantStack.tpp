/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:50:21 by daparici          #+#    #+#             */
/*   Updated: 2025/01/25 17:12:04 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// Constructors & Destructor

template <typename T>
MutantStack<T>::MutantStack(void){}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>(src) {}

// Operator Overloads

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

// Iterator Functions

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const
{
	return this->c.end();
}

// Destructor

template <typename T>
MutantStack<T>::~MutantStack(void){}

