/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:32:14 by daparici          #+#    #+#             */
/*   Updated: 2024/09/06 19:13:47 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	while (input != "EXIT")
	{
		std::cout << "Enter ADD, SEARCH or EXIT: ";
		std::getline(std::cin, input);
		if (std::cin.eof()) // Verifica si se ha alcanzado el EOF
        {
            std::cout << std::endl; // Opcional: Imprime una nueva línea para una salida más limpia
            break; // Sale del bucle
        }
		if (input == "ADD" )
			phonebook.addContact();
		else if (std::cin.eof())
			continue;
	} 
	return (0);
}