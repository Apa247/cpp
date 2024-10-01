/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:48:38 by daparici          #+#    #+#             */
/*   Updated: 2024/10/01 19:44:33 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//------------------ Constructors ------------------//

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain &cpy)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = cpy;
}

//------------------ Destructor ------------------//

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

//------------------ Operator ------------------//

Brain &Brain::operator=(const Brain &rhs)
{
	std::cout << "Brain Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		for (size_t i = 0; i < 100; i++)
		{
			if (rhs._ideas[i].length() > 0)
				this->_ideas[i].assign(rhs._ideas[i]);
		}
	}
	return *this;
}

//------------------ Getters ------------------//

const std::string Brain::getIdea(int idx) const
{
	if (idx < 0 || idx >= 100)
		return ("\033[33mThere is only 100 ideas per brain.\033[0m");
	return this->_ideas[idx];
}

const std::string *Brain::getIdeaAdress(size_t i) const
{
	if (i >= 100)
		return NULL;
	return &this->_ideas[i];
}

//------------------ Setters ------------------//

void Brain::setIdea(size_t i, std::string idea)
{
	if (i >= 100)
		std::cerr << "\033[31mError: There is only 100 ideas per brain.\033[0m" << std::endl;
	else
		this->_ideas[i] = idea;
}