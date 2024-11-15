/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:00:27 by daparici          #+#    #+#             */
/*   Updated: 2024/11/14 21:06:32 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>  // For std::find
#include <iterator>   // For std::distance
#include <exception>  // For std::exception

// Excepcion personalizada
class NotFoundException : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return "Element not found in the container";
        }
};

// Template function easyfind
template <typename T>
typename T::iterator easyfind(T &container, int n)
{
    // Usa std::find para buscar el valor en el contenedor
    typename T::iterator it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw NotFoundException();
    return it;
}
/*
    	typename T::iterator it = std::find(container.begin(), container.end(), value);
	->	typename T::iterator: Esto declara una variable it de tipo iterador para el
		contenedor genérico T. El uso de typename es necesario en las plantillas para indicar
		que T::iterator es un tipo, ya que el compilador de C++ no siempre puede deducir esto
		automáticamente.
		T representa el tipo de contenedor genérico (por ejemplo, podría ser un std::vector<int>,
		std::list<int>, etc.), y T::iterator es el tipo de iterador asociado con
		ese contenedor. Este tipo varía para cada contenedor, por lo que typename es requerido
		en una plantilla.
	->	std::find(container.begin(), container.end(), value): std::find es una función estándar
		de la biblioteca <algorithm>. Busca un valor en el rango de elementos definido
		por dos iteradores (begin() y end()).
			container.begin() devuelve un iterador que apunta al primer elemento del
			contenedor container.
			container.end() devuelve un iterador que apunta justo después del último elemento
			del contenedor.
	->	La función std::find recorrerá todos los elementos entre container.begin()
		y container.end() y devolverá un iterador que apunta a la primera aparición de
		value. Si value no se encuentra, std::find devuelve el iterador end() del contenedor,
		lo que indica que no se encontró el valor.	
*/


