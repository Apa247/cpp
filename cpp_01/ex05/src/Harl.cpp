/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 01:08:51 by daparici          #+#    #+#             */
/*   Updated: 2024/09/21 15:21:28 by daparici         ###   ########.fr       */
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
    std::cout << "Debug: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "Info: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "Warning: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "Error: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    std::map<std::string, void (Harl::*)(void)>::iterator it = levels.find(level);
    if (it != levels.end()) {
        (this->*(it->second))();
    } else {
        std::cout << "Nivel desconocido: " << level << std::endl;
    }
}
