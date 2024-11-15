/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:57:48 by daparici          #+#    #+#             */
/*   Updated: 2024/11/14 22:09:58 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

/*	En C++, los contenedores son estructuras de datos proporcionadas por la Biblioteca
	Estándar de Plantillas (STL) que almacenan colecciones de objetos. Los contenedores
	te permiten gestionar y acceder a tus datos de manera eficiente y ofrecen operaciones
	integradas como inserción, eliminación, búsqueda y ordenamiento. Existen varios tipos
	de contenedores, cada uno optimizado para diferentes casos de uso, dependiendo de
	cómo quieras almacenar y recuperar los datos.

	Tipos de Contenedores:
	
	->	CONTENEDORES DE SECUENCIA: Almacenan elementos en una secuencia lineal. Los elementos
		se almacenan en el orden en que se insertan.
		->	Vector (std::vector): Un array dinámico que puede cambiar de tamaño automáticamente.
			Permite un acceso rápido aleatorio, pero la inserción o eliminación de elementos
			(excepto al final) puede ser costosa.
			Ejemplo: std::vector<int> v = {1, 2, 3};
		->	Lista (std::list): Una lista doblemente enlazada. Permite inserciones y eliminaciones
			rápidas en cualquier punto, pero un acceso aleatorio más lento (sin indexación directa).
			Ejemplo: std::list<int> l = {1, 2, 3};
		->	Deque (std::deque): Cola de doble extremo que permite inserciones y eliminaciones
			rápidas en ambos extremos, además de soportar un acceso aleatorio eficiente.
			Ejemplo: std::deque<int> d = {1, 2, 3};
	->	CONTENEDORES ASOCIATIVOS: Almacenan elementos en pares clave-valor y los ordenan
		automáticamente según las claves. Estos contenedores ofrecen una búsqueda,
		inserción y eliminación rápidas.
		->	Mapa (std::map): Un contenedor asociativo ordenado que almacena pares clave-valor,
			donde cada clave es única.
			Ejemplo: std::map<int, std::string> m; m[1] = "uno";
		->	Conjunto (std::set): Una colección de elementos únicos almacenados en un
			orden específico. Útil para eliminar duplicados.
			Ejemplo: std::set<int> s = {1, 2, 3};
		->	Multimap (std::multimap): Similar a map, pero permite múltiples valores para
			la misma clave.
			Ejemplo: std::multimap<int, std::string> mm;
		->	Multiset (std::multiset): Similar a set, pero permite valores duplicados.
			Ejemplo: std::multiset<int> ms = {1, 1, 2, 3};
	->	CONTENEDORES ASOCIATIVOS DESORDENADOS: Al igual que los contenedores asociativos,
		pero los elementos no están ordenados. Utilizan hashing para un acceso rápido.
		->	Mapa desordenado (std::unordered_map): Un contenedor asociativo basado en hashing
			para pares clave-valor, donde las claves no están ordenadas, sino que se
			hash-ean para una búsqueda rápida.
			Ejemplo: std::unordered_map<int, std::string> umap;
		->	Conjunto desordenado (std::unordered_set): Una colección basada en hashing de
			elementos únicos, sin ningún orden.
			Ejemplo: std::unordered_set<int> uset = {1, 2, 3};
	->	ADAPTADORES DE CONTENEDORES: Estos contenedores modifican otros contenedores para
		proporcionar interfaces específicas. Son, por lo general, envoltorios alrededor
		de otros contenedores.
		->	Pila (std::stack): Proporciona un patrón de acceso Último en Entrar, Primero
			en Salir (LIFO). Generalmente se implementa usando un deque o un vector.
			Ejemplo: std::stack<int> s;
		->	Cola (std::queue): Proporciona un patrón de acceso Primero en Entrar,
			Primero en Salir (FIFO). Se implementa con un deque o lista.
			Ejemplo: std::queue<int> q;
		->	Cola de prioridad (std::priority_queue): Una cola donde los elementos están
			ordenados según la prioridad (típicamente el elemento más grande va primero).
			Ejemplo: std::priority_queue<int> pq;

Propiedades Clave de los Contenedores:

	->	Seguridad de Tipo: Los contenedores de STL están basados en plantillas, lo que
		significa que pueden contener elementos de cualquier tipo, ofreciendo seguridad
		de tipo en tiempo de compilación.
		Ejemplo: std::vector<int> contiene enteros, y tratar de almacenar otro tipo
		provoca un error en tiempo de compilación.
	->	Iteradores: Todos los contenedores proporcionan iteradores, que son objetos que
		permiten recorrer los elementos en el contenedor. Los iteradores abstraen la
		estructura subyacente y permiten interactuar con los contenedores de manera
		consistente.
		Ejemplo: std::vector<int>::iterator it = v.begin();
	->	Algoritmos: Los contenedores pueden trabajar perfectamente con algoritmos de la STL
		como std::sort, std::find, etc., lo que permite manipular y acceder a los
		elementos de manera eficiente.

Cuándo Usar Cada Contenedor:

	->	Usa un vector cuando necesites acceso rápido por índice y no necesites insertar
		o eliminar elementos con frecuencia (excepto al final).
	->	Usa una lista cuando necesites inserciones y eliminaciones frecuentes desde ambos
		extremos o en el medio, pero no requieras acceso aleatorio.
	->	Usa un map o unordered_map cuando necesites asociar claves con valores
		y buscar elementos eficientemente.
	->	Usa un set o unordered_set cuando quieras almacenar elementos únicos y
		necesites capacidades de búsqueda rápida.

Conclusión:

Los contenedores de C++ ofrecen formas flexibles y eficientes de almacenar y manipular datos.
Elegir el contenedor adecuado depende de los requisitos específicos de tu
aplicación, como cómo necesitas acceder a los elementos, cómo quieres almacenarlos
y qué tipo de rendimiento necesitas.
*/

class Span
{
    private:
        unsigned int		_Numbers; // Stores the integers
        std::vector<int>	_MaxSize; // Maximum number of elements (N)
        
    public:
        
        // Constructors
        Span(unsigned int N);
        Span(Span const &src);

        // Destructor
        ~Span();

        // Operator
        Span & operator=(Span const & rhs);

        // Member functions
        void	        addNumber(int n);
        int		        shortestSpan(void);
        int		        longestSpan(void);
        unsigned int    size(void) const;

        template <typename Iterator>
        void	        addNumbers(Iterator begin, Iterator end);
};

// La definición de una función plantilla debe estar en el archivo de encabezado
// o en un archivo de código fuente incluido en el archivo de encabezado.

// Plantilla de función para calcular la diferencia más corta entre dos elementos
template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
    if (std::distance(begin, end) + this->_numbers.size() > this->_maxSize)
        throw std::out_of_range("Error: Span is full");
        _numbers.insert(_numbers.end(), begin, end);
}
