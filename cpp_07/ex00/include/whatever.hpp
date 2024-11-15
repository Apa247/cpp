/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:28:25 by daparici          #+#    #+#             */
/*   Updated: 2024/11/13 18:46:30 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ¿Qué son los templates en C++?

   Un template es una definición genérica de una función o clase que puede aceptar
   uno o más parámetros de tipo. Estos parámetros de tipo actúan como "marcadores
   de posición", permitiendo que el compilador genere automáticamente versiones específicas
   de funciones o clases en función de los tipos de datos reales utilizados en el código.
   Hay dos tipos principales de templates en C++:
   -> Templates de función: Permiten definir funciones que funcionan con cualquier
      tipo de dato.
   -> Templates de clase: Permiten crear clases genéricas que pueden manejar
      cualquier tipo de dato.
      
   ¿Para qué se utilizan los templates en C++?

   Los templates se usan para escribir código que puede trabajar con cualquier tipo de dato sin
   duplicar código para cada tipo. Esto mejora la reutilización del código y simplifica
   el mantenimiento.

   Beneficios:
   -> Reutilización de código: Evita tener que escribir la misma función o clase para diferentes
      tipos de datos.
   -> Generalización: Permite crear algoritmos o estructuras de datos que son
      independientes de los tipos de datos que manejan.
   -> Menos duplicación de código: En lugar de escribir múltiples versiones de una función
      para manejar diferentes tipos, se puede escribir un único template que funcione para
      todos.
   -> Flexibilidad: El compilador genera código específico para cada tipo en función de los tipos
      utilizados, garantizando eficiencia mientras se mantiene la seguridad de tipos.

   Conclusión:
   Los templates en C++ son fundamentales para desarrollar bibliotecas genéricas como la
   STL (Standard Template Library), que contiene estructuras de datos y algoritmos
   que pueden usarse con cualquier tipo de dato.
*/

// Template de función para swap: Intercambia los valores de dos argumentos
template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// Template de función para min: Devuelve el valor mínimo de dos argumentos
template <typename T>
T min(T a, T b)
{
    return (a < b) ? a : b; // condición ? valor_si_verdadero : valor_si_falso;
}

// Template de función para max: Devuelve el valor máximo de dos argumentos
template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b; // condición ? valor_si_verdadero : valor_si_falso;
}
