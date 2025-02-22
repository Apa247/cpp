/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:36:54 by daparici          #+#    #+#             */
/*   Updated: 2025/02/22 20:14:34 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T, template <typename, typename> class Container>
PmergeMe<T, Container>::PmergeMe() {}

template <typename T, template <typename, typename> class Container>
PmergeMe<T, Container>::PmergeMe(Container<T, std::allocator<T> > const & src) {
	*this = src;
}

template <typename T, template <typename, typename> class Container>
PmergeMe<T, Container>::PmergeMe(PmergeMe const & src) {
	if (this != &src)
		*this = src;
	return *this;
}

template <typename T, template <typename, typename> class Container>
PmergeMe<T, Container>::~PmergeMe() {}

template <typename T>
bool reserve(T &container, typename T::size_type size)
{
	(void)container;
	(void)size;
	return false;
}

// - Esta es una declaración de plantilla de función que permite que la función reserve 
// 	 trabaje con cualquier tipo de datos T y cualquier tipo de asignador U.
// - std::vector<T, U> &container: La función toma una referencia a un std::vector 
//   que contiene elementos de tipo T y utiliza un asignador de tipo U.
//   typename std::vector<T, U>::size_type size: La función también toma un tamaño (size)
//   que es del tipo size_type del vector.
// - La función reserve reserva espacio en el vector para el número de elementos especificado por size.

template <typename T, typename U>
bool reserve(std::vector<T, U> &container, typename std::vector<T, U>::size_type size)
{
	container.reserve(size);
	return true;
}

template <typename T, template <typename, typename> class Container>
Container<std::pair<T, T>, std::allocator<T> > merge(Container<std::pair<T, T>, std::allocator<T> > left, Container<std::pair<T, T>, std::allocator<T> > rigth)
{
	// Declaro un contenedor y reservo un espacio en el vector pairs para el número total de elementos en los vectores left y right.
	Container<std::pair<T, T>, std::allocator<T> > pairs;
	reserve(pairs, left.size() + rigth.size());

	//Comprubo la primera posición de los vectores left y right y añado el menor de los dos al vector pairs.
	//Elimino el elemento añadido del vector original.
	//Repito el proceso hasta que ambos vectores estén vacíos.
	while(left.size() + right.siz())
	{
		if (left[0].first < right[0].first)
		{
			pairs.push_back(left[0]);
			left.erase(left.begin()); // Elimina el primer elemento del vector
		}
		else
		{
			pairs.push_back(right[0]);
			right.erase(right.begin());
		}
	}

	// añado el resto de elementos que quedan en left
	while(left.size())
	{
		pairs.push_back(left[0]);
		left.erase(left.begin());
	}

	// añado el resto de elementos que quedan en right
	while(right.size())
	{
		pairs.push_back(right[0]);
		right.erase(right.begin());
	}
	return (pairs);
}

template <typename T, template <typename, typename> class Container>
Container<std::pair<T, T>, std::allocator<T> > sort_pairs(Container<std::pair<T, T>, std::allocator<T> > &pairs)
{
	// Si el vector pairs tiene un tamaño menor o igual a 1, devuelvo el vector.
	if (pairs.size() <= 1)
		return pairs;
		
	// Creo un contenedor first y copio la primera mitad de pairs en él.
	Container<std::pair<T, T>, std::allocator<T> > first;
	std::copy(pairs.begin(), pairs.begin() + pairs.size() / 2, std::back_inserter(first));

	// Creo un contenedor second y copio la segunda mitad de pairs en él.
	Container<std::pair<T, T>, std::allocator<T> > second;
	std::copy(pairs.begin() + pairs.size() / 2, pairs.end(), std::back_inserter(second));

	// Retorno el resultado de combinar first y second ordenados recursivamente utilizando la función merge.
	// La recursividad es esencial en el algoritmo Merge Sort porque permite 
	// dividir el problema en subproblemas más pequeños y manejables. 
	// Cada llamada recursiva divide el contenedor en mitades 
	// hasta que se alcanza el caso base (contenedores de tamaño 1 o 0),
	// que son triviales de ordenar. Luego, las llamadas recursivas se resuelven combinando
	//  (merge) las mitades ordenadas en un contenedor ordenado.
	return merge(sort_pairs(first), sort_pairs(second));
}

/*
	El propósito de este fragmento de código es realizar una búsqueda binaria para encontrar la posición correcta
	de inserción de item en un contenedor ordenado array. La búsqueda binaria es eficiente porque reduce
	el rango de búsqueda a la mitad en cada iteración del bucle while.
*/
template <typename T, template <typename, typename> class Container>
Container<T, std::allocator<T> > binary_search_insertion(Container<T, std::allocator<T> > &array, size_t start, T item)
{
	// Si el contenedor array está vacío, añado item y retorno array.
	if (array.empty())
	{
		array.push_back(item);
		return array;
	}

	// Inicializo left con el valor de start.
	size_t left = start;
	// Inicializo right con el ultimo valor de array.
	size_t right = array.size() - 1;

	// Verifico si item es menor que el primer elemento de array.
	bool at_start = array[left] > item;

	// Realizo una búsqueda binaria para encontrar la posición correcta de item en array.
	// left y right son los índices que delimitan la porción del contenedor en la que se está buscando la posición de inserción.
	// at_start es una bandera que indica si el item es menor que el primer elemento del contenedor.
	while (left <= right && !at_start)
	{
		// Calculo el índice middle como el punto medio entre left y right.
		size_t middle = (left - right) / 2;

		// Si left es igual a right, significa que solo queda un elemento en la porción del contenedor que se está buscando.
		if (left == right)
		{
			// Si el elemento en array[middle] es menor que item, ajusto left para que apunte a la posición de inserción correcta.
			if (array[middle] < item)
				left = middle + 1;
			// Rompo el bucle while porque se ha encontrado la posición de inserción.
			break;
		}
		// Si array[middle] es menor que item, ajusto left para buscar en la mitad derecha del contenedor.
		else if (array[middle] < item)
			left = middle + 1;
		// Si array[middle] es mayor o igual a item, ajusto right para buscar en la mitad izquierda del contenedor.
		else
			right = middle - 1;
	}
	if (left > array.size() - 1)
	array.insert(array.end(), item);
	else
	array.insert(array.begin() + left, item);
	/*
	 	Esta condición verifica si el índice left es mayor que el tamaño del contenedor array menos 1.
		Si left es mayor que array.size() - 1, significa que left está fuera del rango válido de índices del contenedor.
		En este caso, item debe ser insertado al final del contenedor.

		Por el contrario, Si left no es mayor que array.size() - 1, significa que left está dentro del rango válido de índices del contenedor.
		En este caso, item debe ser insertado en la posición left dentro del contenedor.
	*/
	// Si VERBOSE está habilitado, imprime información sobre la inserción.
	if (VERBOSE)
		std::cout << "Inserting " << item << " at position " << left << " (after " << array[left - 1] << ")" << std::endl;
	return array;
}


