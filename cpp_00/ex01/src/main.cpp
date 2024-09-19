/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:32:14 by daparici          #+#    #+#             */
/*   Updated: 2024/09/09 20:50:08 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int		valid_option(std::string option)
{
	if (option == "ADD" || option == "SEARCH" 
		|| option == "1" || option == "2")
		return (1);
	return (0);
}

void	print_menu(void)
{
	std::cout << "*------------------------------------------*\n"
            "|                                          |\n"
            "|      Daparici	-    Phone Book         |\n"
            "|                                          |\n"
            "|  Write the action or the option number   |\n"
            "|                                          |\n"
            "|      (1) ADD - Add a new contact         |\n"
            "|      (2) SEARCH - Display a contact      |\n"
            "|      (3) EXIT - Exit PhoneBook           |\n"
            "|                                          |\n"
            "*------------------------------------------*" << std::endl;
			std::cout << "Option> ";
}

int main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	while (input != "EXIT" && input != "3")
	{
		print_menu();
		std::getline(std::cin, input);
		if (valid_option(input))
		{
			if (input == "ADD" || input == "1")
				phonebook.addContact();
			else if (input == "SEARCH" || input == "2")
				phonebook.searchContact();
		}
		else if (input != "EXIT" && input != "3")
			std::cout << "Invalid option" << std::endl;
		if (std::cin.eof()) // Verifica si se ha alcanzado el EOF
        {
            std::cin.clear(); // Limpia el estado del flujo
			clearerr(stdin); // Limpia el error del flujo
			std::cout << std::endl; // Opcional: Imprime una nueva línea para una salida más limpia
        }
	} 
	return (0);
}