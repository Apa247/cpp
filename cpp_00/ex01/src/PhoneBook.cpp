/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:43:37 by daparici          #+#    #+#             */
/*   Updated: 2024/09/09 21:52:55 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->c_index = 0;
	this->index_serch = 0;
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::setC_index(int index)
{
	this->c_index = index;
}

void	PhoneBook::setIndex_serch(int index)
{
	this->index_serch = index;
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
	
	input = "";
	if (this->c_index >= 8)
	{
		this->setC_index(0);
		this->setIndex_serch(8);
	}
	if (this->c_index < 8)
	{
		while(!std::cin.eof() && input == "")
		{
			std::cout << "First Name: ";
			if(std::getline(std::cin, input) && input != "")
				this->contact[this->c_index].setFirstName(input);	
		}
		input = "";
		while(!std::cin.eof() && input == "")
		{
			std::cout << "Last Name: ";
			if(std::getline(std::cin, input) && input != "")
				this->contact[this->c_index].setLastName(input);	
		}
		input = "";
		while(!std::cin.eof() && input == "")
		{
			std::cout << "Nickname: ";
			if(std::getline(std::cin, input) && input != "")
				this->contact[this->c_index].setNickname(input);	
		}
		input = "";
		// Validación para que solo se acepten números en el campo "Phone Number"
 		bool valid = false;
		while(!std::cin.eof() && input == "")
		{
			while (!valid)
			{
				std::cout << "Phone Number: ";
      			if (!std::getline(std::cin, input)) {
           			if (std::cin.eof()) {
                		std::cerr << "Input error (EOF). Exiting addContact." << std::endl;
                		return; // Salir de la función si se detecta EOF
            		} else {
                		std::cerr << "Input error. Please try again." << std::endl;
                		std::cin.clear(); // Limpiar el estado de error
               			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar la entrada incorrecta
                		continue;
            		}
        		}
        		if (input != "") {
            		valid = true;
            		for (size_t i = 0; i < input.length(); ++i) {
                		if (!isdigit(input[i])) {
                    		valid = false;
                    		std::cout << "Invalid input. Please enter only numbers." << std::endl;
                    		break;
                		}
            		}
            		if (valid) {
                		this->contact[this->c_index].setPhoneNumber(input);
            		}
        		}
			}
		}
		input = "";
		while(!std::cin.eof() && input == "")
		{
			std::cout << "Darkest Secret: ";
			if(std::getline(std::cin, input) && input != "")
				this->contact[this->c_index].setDarkestSecret(input);
		}
		this->c_index++;
		if (this->index_serch < 8)
			this->index_serch++;
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
	 while (i < this->index_serch)
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
