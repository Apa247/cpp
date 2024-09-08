/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:43:37 by daparici          #+#    #+#             */
/*   Updated: 2024/09/08 02:56:39 by daparici         ###   ########.fr       */
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

std::string formatString(const std::string& input) 
{
    if (input.length() > 10) {
        return input.substr(0, 9) + ".";
    } else {
        return std::string(10 - input.length(), ' ') + input;
    }
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
}

void	PhoneBook::searchContact(void)
{
	int			i;
	std::string	index;

	i = 0;
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	 while (i < this->c_index)
    {
        std::cout << "|" << std::setw(10) << i + 1;
        std::cout << "|" << formatString(this->contact[i].getFirstName());
        std::cout << "|" << formatString(this->contact[i].getLastName());
        std::cout << "|" << formatString(this->contact[i].getNickname());
        std::cout << "|" << std::endl;
        i++;
    }
    std::cout << " ___________________________________________ " << std::endl;
    std::cout << "Enter the index of the contact you want to see: ";
    std::getline(std::cin, index);
    if (index.size() == 1 && index[0] >= '1' && index[0] <= '0' + this->c_index)
	{
        i = (index[0] - '0') - 1;
        std::cout << "First Name: " << this->contact[i].getFirstName() << std::endl;
        std::cout << "Last Name: " << this->contact[i].getLastName() << std::endl;
        std::cout << "Nickname: " << this->contact[i].getNickname() << std::endl;
        std::cout << "Phone Number: " << this->contact[i].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << this->contact[i].getDarkestSecret() << std::endl;
    }
    else
        std::cout << "Invalid index" << std::endl;
}
