/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:50:12 by daparici          #+#    #+#             */
/*   Updated: 2024/09/26 16:50:34 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*------------- Contructor and Destructor -----------------*/

Fixed::Fixed(void) : _raw(0)
{
}

Fixed::Fixed(const int value)
{	
	this->_raw = value << this->_frac;
}

Fixed::Fixed(const float value)
{
	this->_raw = roundf(value * (1 << this->_frac));
}

Fixed::~Fixed() 
{
}

Fixed::Fixed(Fixed const &other) 
{
	*this = other;
}

/*------------- Operator Overload --------------------*/

Fixed&	Fixed::operator=(const Fixed &rhs) 
{
	if (this != &rhs)
		this->_raw = rhs.getRawBits();
	return *this;
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	Fixed	result(this->toFloat() + rhs.toFloat());
	return result;
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	Fixed	result(this->toFloat() - rhs.toFloat());
	return result;
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	Fixed	result(this->toFloat() * rhs.toFloat());
	return result;
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	Fixed	result(this->toFloat() / rhs.toFloat());
	return result;
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return this->toFloat() > rhs.toFloat();
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return this->toFloat() < rhs.toFloat();
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return this->toFloat() >= rhs.toFloat();
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return this->toFloat() <= rhs.toFloat();
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return this->toFloat() == rhs.toFloat();
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return this->toFloat() != rhs.toFloat();
}

Fixed	Fixed::operator++(int value)
{
	Fixed tmp(*this);

	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() + value);
	return tmp;
}

Fixed	Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed	Fixed::operator--(int value)
{
	Fixed tmp(*this);

	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() - value);
	return tmp;
}

Fixed	Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

/*------------- Min and Max -----------------*/

const Fixed	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return a;
	return b;
}

/*------------- Getters and Setters -----------------*/

int Fixed::getRawBits(void) const 
{
	return this->_raw;
} 

void Fixed::setRawBits(int const raw) 
{
	this->_raw = raw;
}

/*----------------- Conversion ----------------------*/

float Fixed::toFloat( void ) const
{
	return (float)this->_raw / (float)(1 << this->_frac);
}

int Fixed::toInt( void ) const
{
	return this->_raw >> this->_frac;
}

/*---------------- Other Functions ---------------------*/

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}