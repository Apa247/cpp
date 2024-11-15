/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:52:25 by daparici          #+#    #+#             */
/*   Updated: 2024/11/13 19:40:40 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

// Ejemplo de función para aplicar a cada elemento de un array
template <typename T>
void printElement(T const &elem)
{
    std::cout << elem << std::endl;
}

// Otra función ejemplo que multiplica cada elemento por 2
template <typename T>
void multiplyByTwo(T& elem) {
    elem *= 2;
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    std::string strArray[] = {"one", "two", "three", "four", "five"};
    size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);
    size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);

    //	Necesitamos usar una referencia explícita a la plantilla para decirle al compilador
    //	qué versión debe usar.

    std::cout << "Iterating over intArray:" << std::endl;
    ::iter(intArray, 5, printElement<int>);

    std::cout << "\nIterating over strArray:" << std::endl;
    ::iter(strArray, 3, printElement<std::string>);

    // Prueba con un array de enteros

    std::cout << std::endl << "Array de enteros antes de multiplicar por 2: " << std::endl;
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;

    iter(intArray, intArrayLength, multiplyByTwo<int>);

    std::cout << std::endl << "Array de enteros después de multiplicar por 2: " << std::endl;
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;

    // Prueba con un array de strings

    std::cout << std::endl << "Array de strings: "<< std::endl;
    iter(strArray, strArrayLength, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}