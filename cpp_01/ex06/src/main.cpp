/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:59:01 by daparici          #+#    #+#             */
/*   Updated: 2024/10/18 16:42:29 by daparici         ###   ########.fr       */
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
	int			i;

	while (1)
	{
		print_menu();
		option = get_option();
		i = atoi(option.c_str());
		if (option == "")
		{
			std::cout << "Goodbye!" << std::endl;
			break;
		}
		else	
		{
			switch (i)
			{
				case 1:
					harl.complain("0");
					// fall through
				case 2:
					harl.complain("1");
					// fall through
				case 3:
					harl.complain("2");
					// fall through
				case 4:
					harl.complain("3");
					break;
				default:
					std::cout << "Invalid option" << std::endl;
					break;
			}
		}
	}
	return 0;
}