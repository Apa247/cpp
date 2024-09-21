/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:58:57 by daparici          #+#    #+#             */
/*   Updated: 2024/09/22 01:02:41 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
    levels["1"] = &Harl::debug;
    levels["2"] = &Harl::info;
    levels["3"] = &Harl::warning;
    levels["4"] = &Harl::error;
}

Harl::~Harl() {}

void Harl::debug(void) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	int i = atoi(level.c_str());
    std::map<std::string, void (Harl::*)(void)>::iterator it = levels.find(level);
    if (it != levels.end())
	{
		switch (i)
		{
			case	1:
				this->debug();
				std::cout << std::endl;
				this->info();
				std::cout << std::endl;
				this->warning();
				std::cout << std::endl;
				this->error();
				break;
			case	2:
				this->info();
				std::cout << std::endl;
				this->warning();
				std::cout << std::endl;
				this->error();
				break;
			case	3:
				this->warning();
				std::cout << std::endl;
				this->error();
				break;
			case	4:
				this->error();
				break;
			default:
				std::cout << "Nivel desconocido: " << level << std::endl;
				break;
		}
    } else {
        std::cout << "Nivel desconocido: " << level << std::endl;
    }
}
