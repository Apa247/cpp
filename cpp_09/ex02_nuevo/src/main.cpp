/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:36:29 by daparici          #+#    #+#             */
/*   Updated: 2025/03/17 14:48:30 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sys/time.h>
#include <cstring>
#include <limits>
#include "PmergeMe.hpp"
#include <cstdio>

/*
	Un ejemplo de como actua el algoritmo:
	Supongamos que tenemos el siguiente contenedor de enteros:
	
	std::vector<int> array = {5, 2, 9, 1, 5, 6};

	Paso 1: Verificar el tamaño del contenedor

		El tamaño del contenedor es 6, por lo que continuamos con el siguiente paso.

	Paso 2: Verificar si el número de elementos es impar
	
		bool is_odd = array.size() % 2 != 0;
		
		is_odd será false porque el tamaño del contenedor es par (6).

	Paso 3: Agrupar los elementos en pares
	
		Agrupamos los elementos en pares y comparamos cada par:
		(5, 2) -> (2, 5)
		(9, 1) -> (1, 9)
		(5, 6) -> (5, 6)

		El contenedor pairs será: [(2, 5), (1, 9), (5, 6)]

	Paso 4: Imprimir los pares si VERBOSE está habilitado

		Pairs: [2, 5], [1, 9], [5, 6],

	Paso 5: Ordenar recursivamente los pares
	
		Llamamos a sort_pairs para ordenar los pares:
		sort_pairs divide los pares en dos mitades y las ordena recursivamente:
		Primera mitad: [(2, 5)]
		Segunda mitad: [(1, 9), (5, 6)]
		Ordenamos la segunda mitad:
		Dividimos en dos mitades: [(1, 9)] y [(5, 6)]
		Ambas mitades ya están ordenadas, así que las combinamos: [(1, 9), (5, 6)]
		Combinamos las dos mitades ordenadas: [(1, 9), (2, 5), (5, 6)]

	Paso 6: Imprimir los pares ordenados si VERBOSE está habilitado

		Pair sorted: [1, 9], [2, 5], [5, 6],

	Paso 7: Crear la secuencia ordenada S

		Creamos el contenedor sorted y añadimos el primer elemento de cada par ordenado: 
		sorted = [1, 2, 5]
	
	Paso 8: Imprimir los elementos ordenados si VERBOSE está habilitado
	
		Sorted: [1, 2, 5]

	Paso 9: Insertar los elementos restantes utilizando búsqueda binaria

		Insertamos los elementos restantes de los pares en sorted utilizando búsqueda binaria:
		Insertamos 9: sorted = [1, 2, 5, 9]
		Insertamos 5: sorted = [1, 2, 5, 5, 9]
		Insertamos 6: sorted = [1, 2, 5, 5, 6, 9]
	
	Paso 10: Retornar el contenedor ordenado
*/

/*
	- static: La función get_timestamp se declara como static, lo que significa que su alcance está limitado al archivo en el que se define. No puede ser llamada desde otros archivos.
	- timestamp_t get_timestamp(void): La función devuelve un valor de tipo timestamp_t y no toma argumentos.
	- struct timeval now;: Se declara una variable now de tipo struct timeval. Esta estructura se utiliza para almacenar el tiempo en segundos y microsegundos.
	- gettimeofday(&now, NULL);: La función gettimeofday llena la estructura now con el tiempo actual. El primer argumento es un puntero a la estructura timeval y el segundo argumento es un puntero a una estructura timezone, que en este caso es NULL porque no se utiliza.
	- return (now.tv_usec + (timestamp_t)now.tv_sec * 1000000);: La función devuelve la marca de tiempo en microsegundos. Se convierte el tiempo en segundos (now.tv_sec) a microsegundos multiplicándolo por 1,000,000 y se suma el valor de microsegundos (now.tv_usec).
*/

typedef unsigned long long timestamp_t;

static	timestamp_t get_timestamp(void)
{
	struct timeval now;
	gettimeofday(&now, NULL);
	return (now.tv_usec + (timestamp_t)now.tv_sec * 1000000);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <values>" << std::endl;
		return 1;
	}

	// Convertimos los argumentos en un contenedor de enteros
	std::vector<int> vector_vals;
	std::deque<int> deque_vals;
	/*
		El propósito de esta declaración es crear un contenedor deque que se utilizará para almacenar
		una secuencia de enteros. Los deque son útiles cuando necesitas insertar o eliminar elementos
		tanto al principio como al final del contenedor de manera eficiente.
	*/

	for (int i = 1; i < argc; i++)
	{
		for (size_t j = 0; j < strlen(argv[i]); j++)
		{
			if (argv[i][j] == '-' && j == 0)
			{
				std::cerr << "Error: " << argv[i] << " is negative" << std::endl;
				return 1;
			}
			if (!isdigit(argv[i][j]))
			{
				std::cerr << "Error: " << argv[i] << " is not a number" << std::endl;
				return 1;
			}
		}

		if (atoi(argv[i]) > std::numeric_limits<int>::max())
		{
			std::cerr << "Error: " << argv[i] << " exceed numeric limit (" << std::numeric_limits<int>::max() << ")" <<  std::endl;
			return 1;
		}
		
		vector_vals.push_back(atoi(argv[i]));
		deque_vals.push_back(atoi(argv[i]));
	}

	// Compruebo si hay duplicados
	std::vector<int> sorted;
	std::copy(vector_vals.begin(), vector_vals.end(), std::back_inserter(sorted));
	std::sort(sorted.begin(), sorted.end());
	std::vector<int>::iterator uniqit = std::unique(sorted.begin(), sorted.end());
	if (uniqit != sorted.end())
	{
		std::cerr << "Error: there is some duplicates values" << std::endl;
		return 1;
	}
	
	std::cout << "Values before: ";
	for (size_t i = 0; i < vector_vals.size(); i++)
		std::cout << vector_vals[i] << " ";
	std::cout << std::endl;

	/////
	// Vector
	/////

	// Medir el tiempo de ejecución
	timestamp_t start = get_timestamp();
	
	// Crear un objeto PmergeMe para ordenar el contenedor de enteros
	PmergeMe<int, std::vector > vector_merge;
	std::vector<int> vector_sorted = vector_merge.sort(vector_vals);

	std::cout << "Values after: ";
	for (size_t i = 0; i < vector_sorted.size(); i++)
		std::cout << vector_sorted[i] << " ";
	std::cout << std::endl;

	// Paro el temporizador
	timestamp_t end = get_timestamp();
	std::cout << "Time to process a range of " << vector_vals.size() << " elements with std::vector : " << end - start << " us" << std::endl;
	
	/////
	// Deque
	/////

	// Mido el tiempo de ejecución
	start = get_timestamp();

	// Crear un objeto PmergeMe para ordenar el contenedor de enteros
	PmergeMe<int, std::deque > deque_merge;
	std::deque<int> deque_sorted = deque_merge.sort(deque_vals);
	
	// Paro el temporizador
	end = get_timestamp();
	std::cout << "Time to process a range of " << deque_vals.size() << " elements with std::deque : " << end - start << " us" << std::endl;

	/////
	// Compruebo si se han ordenado correctamente
	/////

	for (size_t i = 0; i < sorted.size(); i++)
	{
		if (sorted[i] != vector_sorted[i] || sorted[i] != deque_sorted[i])
		{
			std::cerr << "Error: " << sorted[i] << " is not in the correct position" << std::endl;
			return 1;
		}
	}
	if (sorted.size() != vector_sorted.size() || sorted.size() != deque_sorted.size())
	{
		std::cerr << "Error: The number of elements is not the same" << std::endl;
		return 1;
	}
}
