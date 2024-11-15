/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:52:16 by daparici          #+#    #+#             */
/*   Updated: 2024/11/13 18:57:10 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
// Función template `iter` que toma un array, su longitud y una función para aplicar a cada elemento
template <typename T, typename F>
void iter(T* array, size_t length, F func) 
{
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}