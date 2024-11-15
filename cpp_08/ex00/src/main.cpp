/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:00:10 by daparici          #+#    #+#             */
/*   Updated: 2024/11/14 21:01:22 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

/*	std::vector<int>::iterator result = easyfind(myVector, 3);
	->	std::vector<int>::iterator: Esto define una variable llamada result de tipo
		iterador para un vector de enteros (std::vector<int>). Los iteradores son objetos
		que permiten recorrer los elementos de un contenedor (como un vector),
		de manera similar a los punteros. El tipo de iterador depende del tipo de contenedor;
		en este caso, dado que myVector es un std::vector<int>, el tipo de iterador es
		std::vector<int>::iterator.
	->	result = easyfind(myVector, 3): Esto llama a la función easyfind, pasando
		myVector (un vector de enteros) como primer parámetro, y 3 como segundo
		parámetro (el entero que queremos encontrar en el vector).
	->	easyfind(myVector, 3) busca la primera aparición del número 3
		en myVector. Si encuentra el número, devuelve un iterador que apunta a
		la ubicación del número en el vector. Si no encuentra el número,
		lanza una excepción. Si la búsqueda es exitosa, el iterador devuelto
		se asigna a la variable result, que luego puede usarse para acceder al
		elemento encontrado (de manera similar a un puntero).	
*/

int main()
{
    try
	{
        std::vector<int> myVector;
        myVector.push_back(1);
        myVector.push_back(2);
        myVector.push_back(3);
        myVector.push_back(4);
        myVector.push_back(5);

        // Test with an element that exists
        std::cout << "Searching for 3 in the vector..." << std::endl;
        std::vector<int>::iterator result = easyfind(myVector, 3);
        std::cout << "Found: " << *result << std::endl;

        // Test with an element that does not exist
        std::cout << "Searching for 10 in the vector..." << std::endl;
        result = easyfind(myVector, 10);
        std::cout << "Found: " << *result << std::endl;
    }
	catch (const std::exception &e)
	{
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

/*
    Este código es el punto de entrada de un programa en C++ que prueba la función easyfind.
    La función easyfind (asumida aquí como implementada en otra parte) busca un valor entero
    en un contenedor genérico. Vamos a analizar cada parte del main:

    Bloque try:
        - Se utiliza un bloque try-catch para manejar posibles excepciones que puedan surgir 
        durante la ejecución de easyfind.
    
    Creación y llenado de myVector:
        - std::vector<int> myVector; declara un vector de enteros llamado myVector.
        - push_back se utiliza para agregar los valores 1, 2, 3, 4 y 5 al vector.
    
    Prueba de easyfind con un valor existente:
        - std::cout << "Searching for 3 in the vector..." << std::endl; imprime un mensaje indicando
        que está buscando el valor 3 en el vector.
        - std::vector<int>::iterator result = easyfind(myVector, 3); llama a easyfind con el vector
        y el valor 3.
        - Si 3 se encuentra en el vector, easyfind devolverá un iterador (result)
        apuntando a la posición del 3 en el vector.
        - std::cout << "Found: " << *result << std::endl; imprime el valor encontrado,
        desreferenciando el iterador para mostrar el valor (3).
    
    Prueba de easyfind con un valor no existente:
        - std::cout << "Searching for 10 in the vector..." << std::endl; imprime un mensaje
        indicando que ahora busca el valor 10.
        - result = easyfind(myVector, 10); llama a easyfind con el valor 10.
        - Si 10 no se encuentra en el vector, es probable que easyfind arroje una excepción
        (por ejemplo, si el código está implementado para lanzar una excepción en lugar de devolver un valor de error).
    
    Manejo de excepciones:
        - Si ocurre una excepción, el bloque catch captura la excepción std::exception
        y muestra el mensaje de error usando std::cerr << e.what() << std::endl;.
*/