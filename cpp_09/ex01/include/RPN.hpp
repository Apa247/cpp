/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:29:28 by daparici          #+#    #+#             */
/*   Updated: 2025/02/06 20:45:42 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <list>

class RPN {
	
	private:
		
	public:
		RPN();
		RPN(RPN const &src);
		~RPN();
		RPN &operator=(RPN const &rhs);

		float result(std::string expr);

		class ErrorExpression : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class ErrorDivisionByZero : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class RemainingTerms : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};