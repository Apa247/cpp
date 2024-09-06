/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:43:37 by daparici          #+#    #+#             */
/*   Updated: 2024/09/06 18:30:27 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->c_index = 0;
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::setC_index(int index)
{
	this->c_index = index;
}

void	PhoneBook::addContact(void)
{
	std::string	input;
	
	if (this->c_index >= 8)
		this->setC_index(0);
	if (this->c_index < 8)
	{
		std::cout << "First Name: ";
		std::getline(std::cin, input);
		this->contact[this->c_index].setFirstName(input);
		std::cout << "Last Name: ";
		std::getline(std::cin, input);
		this->contact[this->c_index].setLastName(input);
		std::cout << "Nickname: ";
		std::getline(std::cin, input);
		this->contact[this->c_index].setNickname(input);
		std::cout << "Phone Number: ";
		std::getline(std::cin, input);
		this->contact[this->c_index].setPhoneNumber(input);
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, input);
		this->contact[this->c_index].setDarkestSecret(input);
		this->c_index++;
	}
	else
		std::cout << "PhoneBook is full" << std::endl;
}