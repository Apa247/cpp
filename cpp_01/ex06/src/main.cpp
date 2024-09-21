/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:59:01 by daparici          #+#    #+#             */
/*   Updated: 2024/09/22 00:00:02 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	print_menu(void)
{
	std::cout << std::endl;
	std::cout << "What messenge do you want display?" << std::endl;
	std::cout << "1. debug" << std::endl;
	std::cout << "2. info" << std::endl;
	std::cout << "3. warning" << std::endl;
	std::cout << "4. error" << std::endl;
	std::cout << "Press ENTER to exit" << std::endl;
}

std::string	get_option(void)
{
	std::string	option;

	std::cout << "Harl> ";
	std::getline(std::cin, option);
	std::cout << std::endl;
	if (std::cin.eof() == true)
	{
		std::cin.clear();
		std::clearerr(stdin);
	}
	return (option);
}

int	main(void)
{
	std::string	option;
	Harl		harl;

	while (1)
	{
		print_menu();
		option = get_option();
		if (option == "")
		{
			std::cout << "Goodbye!" << std::endl;
			break;
		}
		else
		{
			harl.complain(option);
		}
	}
	return 0;
}