/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:58:16 by daparici          #+#    #+#             */
/*   Updated: 2025/01/25 16:30:57 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructors

Span::Span(const unsigned int N) : _MaxSize(N) {}

Span::Span(const Span &src) : _Numbers(src._Numbers), _MaxSize(src._MaxSize) {}

// Destructor

Span::~Span() {}

// Operator

Span & Span::operator=(const Span & rhs)
{
	if (this != &rhs)
	{
		this->_Numbers = rhs._Numbers;
		this->_MaxSize = rhs._MaxSize;
	}
	return *this;
}

// Member functions

void Span::addNumber(const int n)
{
	if (this->_Numbers.size() >= this->_MaxSize)
		throw std::out_of_range("Error: Span is full");
	_Numbers.push_back(n);
	std::cout << "Number " << n << " added" << std::endl;
}

int Span::shortestSpan(void) const
{
	if (this->_Numbers.size() <= 1)
		throw Span::EmptySpanException();
	
	std::vector<int> tmp = this->_Numbers;
	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());
	return *std::min_element(tmp.begin() + 1, tmp.end());
}

int Span::longestSpan(void) const
{
	if (this->_Numbers.size() < 1)
		throw Span::EmptySpanException();
	if (this->_Numbers.size() == 1)
		throw Span::OneNumberException();

	int max = *std::max_element(this->_Numbers.begin(), this->_Numbers.end());
	int min = *std::min_element(this->_Numbers.begin(), this->_Numbers.end());
	
	return max - min;
}

void Span::fillRandom(unsigned int N)
{
	if (this->_Numbers.size() + N > this->_MaxSize)
		throw std::out_of_range("Error: MaxSize exceeded");
	
	srand(time(NULL));
	for (unsigned int i = 0; i < N; i++)
		this->addNumber(rand());
}

// Exception class

const char *Span::EmptySpanException::what() const throw()
{
	return "Error: Span is empty";
}

const char *Span::OneNumberException::what() const throw()
{
	return "Error: Span has only one number";
}