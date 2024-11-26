/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:57:45 by daparici          #+#    #+#             */
/*   Updated: 2024/11/19 17:41:26 by daparici         ###   ########.fr       */
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



Para resolver el problema al instalar Ubuntu Server en un servidor ProLiant DL160 Gen10 con un RAID configurado, aquí tienes algunas opciones dependiendo de tus necesidades:

1. Verificar compatibilidad del RAID con Ubuntu
Los servidores HPE ProLiant suelen usar controladores RAID específicos (como HPE Smart Array). Ubuntu puede no reconocerlos correctamente durante la instalación si los controladores necesarios no están disponibles.
Solución:
Asegúrate de que el controlador RAID esté configurado en modo "RAID" y no en "HBA" o "AHCI".
Descarga los controladores adecuados desde el sitio oficial de HPE.
Carga los controladores durante la instalación utilizando una unidad USB o integrándolos en la imagen de instalación.
2. Usar el modo de "Passthrough" o "HBA"
Si el RAID actual está configurado en el controlador Smart Array, puede ser necesario cambiarlo a un modo "HBA" o "Passthrough" para que el sistema operativo gestione directamente los discos.
Esto te permite instalar Ubuntu y luego configurar el RAID mediante software en el sistema operativo.
Precaución: Cambiar a este modo puede afectar el RAID existente. Asegúrate de que los datos estén respaldados.
3. Usar un Live CD para analizar discos
Si Ubuntu no puede formatear los discos, podrías usar un Live CD para analizar y preparar los discos antes de la instalación:
Usa herramientas como fdisk o gparted para revisar el estado del RAID y los discos.
Limpia las particiones con:
bash
Copiar código
sudo dd if=/dev/zero of=/dev/sdX bs=1M count=100
(Reemplaza /dev/sdX con el identificador del disco).
4. Instalar Ubuntu sin desmontar el RAID
Asegúrate de que el RAID sea detectado como un único volumen lógico durante la instalación.
Si aparece un error al formatear:
Sal del instalador y accede a una terminal (Ctrl+Alt+F2).
Usa comandos como lsblk para identificar los discos.
Usa mkfs.ext4 (u otro sistema de archivos) manualmente en el volumen del RAID:
bash
Copiar código
sudo mkfs.ext4 /dev/sdX
Regresa al instalador e intenta nuevamente.
5. Actualizar Firmware y BIOS
Asegúrate de que el firmware del controlador RAID y el BIOS del servidor estén actualizados. Los problemas de compatibilidad suelen solucionarse con actualizaciones.
6. Crear una imagen personalizada con controladores
Si el RAID sigue sin ser reconocido, crea una imagen personalizada de Ubuntu con los controladores HPE integrados usando herramientas como Cubic o debootstrap.
Recomendación General:
Respalda los datos del cliente.
Comunica al cliente las implicaciones de la configuración RAID en Ubuntu.
Si necesitas mantener el RAID configurado por hardware, considera instalar una distribución compatible con HPE, como RHEL o SLES, y luego convertirlo a Ubuntu mediante contenedores o máquinas virtuales.
Si necesitas ayuda para implementar una de estas opciones, puedo guiarte en detalle.