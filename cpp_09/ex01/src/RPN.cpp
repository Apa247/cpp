/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:29:34 by daparici          #+#    #+#             */
/*   Updated: 2025/02/06 21:59:57 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const &src) {
	*this = src;
}

RPN::~RPN() {}

RPN &RPN::operator=(RPN const &rhs) {
	(void)rhs;
	return *this;
}

float RPN::result(std::string expr) {
	std::list<float> elems;

	bool is_space = false;
	for (std::string::const_iterator it = expr.begin(); it != expr.end(); it++)
	{
		// Si no es un espacio, y el caracter anterior tampoco lo es
		if (*it != ' ' && !is_space && elems.size() != 0)
			throw RPN::ErrorExpression();
		is_space = *it == ' ';
		if (*it == ' ')
			continue;

		// std::cout << "elem: " << *it << std::endl;
		if (isdigit(*it))
		{
			elems.push_back(*it - '0');
			// for (std::list<float>::const_iterator it2 = elems.begin(); it2 != elems.end(); it2++)
			// 	std::cout << *it2 << " ";
		}
		else
		{
			if (elems.size() < 2)
				throw RPN::ErrorExpression();
			
			float l1 = elems.back();
			elems.pop_back();
			float l2 = elems.back();
			elems.pop_back();

			switch (*it)
			{
				case '+':
					elems.push_back(l2 + l1);
					break;
				case '-':
					elems.push_back(l2 - l1);
					break;
				case '*':
					elems.push_back(l2 * l1);
					break;
				case '/':
					if (l1 == 0)
						throw RPN::ErrorDivisionByZero();
					elems.push_back(l2 / l1);
					break;
				default:
					throw RPN::ErrorExpression();
					break;
			}

			// for (std::list<float>::const_iterator it2 = elems.begin(); it2 != elems.end(); it2++)
			// 	std::cout << *it2 << " ";
		}

		// std::cout << std::endl;
	}
	if (elems.size() != 1)
		throw RPN::RemainingTerms();

	return elems.front();
}

const char *RPN::ErrorExpression::what() const throw() {
	return "Error: Malformed expression";
}

const char *RPN::ErrorDivisionByZero::what() const throw() {
	return "Error: Division by zero is not allowed";
}

const char *RPN::RemainingTerms::what() const throw() {
	return "Error: Remaining terms";
}