/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:57:45 by daparici          #+#    #+#             */
/*   Updated: 2024/11/14 01:51:12 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

//--------------------- Constructores ---------------------//

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
    std::cout << "Array default constructor (nullptr, 0) called." << std::endl;
}

//------ Constructor con tamaño: crea un array de tamaño n ------//

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
    std::cout << "Array constructor with size (" << n << ") called." << std::endl;
}

//--------------------- Constructor de copia ---------------------//

template <typename T>
Array<T>::Array(const Array &src) : _array(new T[src._size]), _size(src._size)
{
    std::cout << "Array copy constructor called." << std::endl;
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = src._array[i];
}

//----------------------------- Destructor -----------------------------//

template <typename T>
Array<T>::~Array()
{
    std::cout << "Array destructor called." << std::endl;
    delete[] _array;
}

//--------------------- Operador de asignación ---------------------//

template <typename T>
Array<T> &Array<T>::operator=(const Array &rhs)
{
    std::cout << "Array assignment operator called." << std::endl;

    if (this != &rhs)
    {
        delete[] _array;
        this->_array = new T[rhs._size];
        this->_size = rhs._size;
        for (unsigned int i = 0; i < _size; i++)
            this->_array[i] = rhs._array[i];
    }
    return *this;
}

//--------------------- Operador de acceso ---------------------//

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    std::cout << "Array operator[] function called." << std::endl;
    if (index >= this->_size)
        throw std::out_of_range("Array index out of bounds.");
    return this->_array[index];
}

//--------------------- Métodos ---------------------//

template <typename T>
unsigned int Array<T>::size() const
{
    std::cout << "Array size() function called." << std::endl;
    return this->_size;
}


/*  La razón de tener dos operadores [] , uno const y uno no const, es permitir un acceso seguro y flexible a los elementos del array en diferentes contextos (constante y no constante). Cada versión tiene un propósito específico:

    Operador [] no const (T &operator[](unsigned int index)):
        Este operador permite el acceso y la modificación de los elementos del array.
        Se usa cuando hay una instancia no constante de Array, y quieres obtener
        una referencia modificable a un elemento.

    Operador [] const (const T &operator[](unsigned int index) const):
        Este operador permite un acceso solo de lectura a los elementos del array.
        Se usa cuando hay una instancia de Array declarada como const, asegurando que
        los elementos no puedan ser modificados accidentalmente.

    Razón principal para tener ambas versiones:
        Seguridad: Permite diferenciar entre acceso de lectura y escritura. Cuando
            se accede a una instancia const de Array, solo se puede usar el operador const [],
            asegurando que los datos no sean modificados.
        Flexibilidad: Permite que el operador [] se use en cualquier contexto. Incluso si
            el array es const, puedes acceder a sus elementos sin violar la inmutabilidad.

    Ejemplo:
        Array<int> arr(5);
        arr[0] = 10;  // Accede al operador no const para modificar el elemento

        const Array<int> constArr(5);
        int value = constArr[0];  // Accede al operador const para acceso solo lectura
*/

