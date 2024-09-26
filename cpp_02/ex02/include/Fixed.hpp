/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:45:44 by daparici          #+#    #+#             */
/*   Updated: 2024/09/26 16:46:47 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int					_raw;
		static const int	_frac = 8;

	public:
	
		/* Contructor and Destructor */
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed const &src);
		Fixed(const int value);
		Fixed(const float value);
		
		/* Operator Overload */
		Fixed	&operator=(const Fixed &rhs);
		Fixed	operator+(const Fixed &rhs) const;
		Fixed	operator-(const Fixed &rhs) const;
		Fixed	operator*(const Fixed &rhs) const;
		Fixed	operator/(const Fixed &rhs) const;
		bool	operator>(const Fixed &rhs) const;
		bool	operator<(const Fixed &rhs) const;
		bool	operator>=(const Fixed &rhs) const;
		bool	operator<=(const Fixed &rhs) const;
		bool	operator==(const Fixed &rhs) const;
		bool	operator!=(const Fixed &rhs) const;
		Fixed	operator++(int value);
		Fixed	operator++(void);
		Fixed	operator--(int value);
		Fixed	operator--(void);

		/* Min and Max */
		static const Fixed	&min(Fixed const &a, Fixed const &b);
		static const Fixed	&max(Fixed const &a, Fixed const &b);
		
		/*Getters and Setters */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		/* Conversion */
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);