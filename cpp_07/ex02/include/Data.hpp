/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:42:40 by daparici          #+#    #+#             */
/*   Updated: 2024/11/14 01:45:22 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

// Simple Data structure with some example members
struct Data
{
    int			number;
    std::string	text;

    // Canonical form
    Data()
    {};
    Data(const Data &other)
    {
        *this = other;
    };
    Data &operator=(const Data &other)
    {
        number = other.number;
        text = other.text;
        return *this;
    };
    ~Data()
    {};
};