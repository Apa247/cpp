/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:57:36 by daparici          #+#    #+#             */
/*   Updated: 2024/11/14 01:49:57 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>  // For std::exception
#include <stdexcept>  // For std::exception

template <typename T>
class Array
{
    private:
    
        T               *_array;   // Puntero a un array asignado dinámicamente
        unsigned int    _size;     // Numero de elementos en el array

    public:

        // Constructores
        Array();
        Array(unsigned int n);
        Array(const Array &src);

        // Destructor
        ~Array();

        // Operador de asignación
        Array &operator=(const Array &rhs);

        // Operador de acceso
        T &operator[](unsigned int index);

        // Métodos
        unsigned int size() const;
};

#include "../src/Array.tpp"  // Implementación de la plantilla


/*	Las plantillas deben ser completamente visibles para el compilador en el momento en que se utilizan.
	A diferencia de las funciones no plantilla, donde puedes separar la declaración en el archivo de cabecera (.hpp) 
	y la definición en un archivo fuente (.cpp), las plantillas requieren que su código esté disponible en el archivo 
	de cabecera o que se incluya directamente.

	->	Compilación de plantillas: Las plantillas no se instancian hasta que el compilador encuentra una instancia 
		específica de ellas. Por lo tanto, cuando se declara una plantilla en un archivo de cabecera, la definición 
		de la plantilla también debe estar disponible en el mismo archivo o en un archivo incluido (como un archivo .tpp). 
		Si solo incluyes la declaración y no la definición en la cabecera, el compilador no podrá instanciar la plantilla 
		cuando se utilice en otros archivos.

	->	Usando el archivo .tpp: Para mantener el código organizado y evitar sobrecargar el archivo de cabecera, 
		puedes separar la implementación de la plantilla de clase en un archivo .tpp (o en un archivo .cpp específico 
		para plantillas). Este archivo se incluye al final del archivo de cabecera, asegurando que tanto la declaración 
		como la definición estén disponibles para el compilador al mismo tiempo.

	->	¿Por qué incluirlo al final?: El archivo .tpp se incluye al final de la cabecera 
		para asegurar que las declaraciones estén presentes antes de las definiciones. 
		El compilador necesita conocer las interfaces (declaraciones) antes de procesar las implementaciones (definiciones). 
*/