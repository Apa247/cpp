/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:30:23 by daparici          #+#    #+#             */
/*   Updated: 2024/09/06 17:08:55 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	int i = 0;
	int j;
	
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (argc > 1)
	{
		while (argv[++i])
		{
			j = -1;
			while (argv[i][++j])
				std::cout << (char)std::toupper(argv[i][j]);
		}
		std::cout << std::endl;
	}
	return 0;
}

// std::string x = std::string(argv[i]);