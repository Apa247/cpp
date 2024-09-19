/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:13:46 by daparici          #+#    #+#             */
/*   Updated: 2024/09/19 17:35:28 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Memory address of str: " << &str << std::endl;
	std::cout << "Memory address of stringPTR: " << &stringPTR << std::endl;
	std::cout << "Memory address of stringREF: " << &stringREF << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "Value of str: " << str << std::endl;
	std::cout << "Value of pointed stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of pointed stringREF: " << stringREF << std::endl;

	return 0;
}