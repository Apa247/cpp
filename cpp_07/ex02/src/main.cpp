/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:28:32 by daparici          #+#    #+#             */
/*   Updated: 2024/11/14 01:45:50 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Array.hpp"
#include "Data.hpp"

int main()
{
    try
	{
        // Create an array of 5 integers
        std::cout << "\033[1;36mCreating an array of 5 integers -> Array<int>	intArray(5);\033[0m" << std::endl;
        Array<int>	intArray(5);
        std::cout << "\033[1;34m\nArray size: " << intArray.size() << "\033[0m" << std::endl;

        // Assign values to the array elements
        std::cout << "\033[1;36m\nAssigning values to the array elements:\033[0m" << std::endl;
        for (unsigned int i = 0; i < intArray.size(); ++i)
		{
			std::cout << "Assigning value " << i * 10 << " to element " << i << std::endl;
            intArray[i] = i * 10;
		}

        // Print the array elements
        std::cout << "\033[1;36m\nArray elements: \033[0m";
        for (unsigned int i = 0; i < intArray.size(); ++i)
            std::cout << intArray[i] << " ";
        std::cout << std::endl;

        // Copy the array using copy constructor
        std::cout << "\033[1;36m\nCopying the array using copy constructor -> Array<int>	copyArray(intArray);\033[0m" << std::endl;
        Array<int> copyArray(intArray);
        std::cout << "\033[1;36m\nCopy Array elements: \033[0m";
        for (unsigned int i = 0; i < copyArray.size(); ++i)
            std::cout << copyArray[i] << " ";
        std::cout << std::endl;

        // Test assignment operator
        std::cout << "\033[1;36m\nAssigning the array using assignment operator -> Array<int>	assignArray = intArray;\033[0m" << std::endl;
        Array<int> assignArray;
        assignArray = intArray;
        std::cout << "\033[1;36m\nAssigned Array elements: \033[0m";
        for (unsigned int i = 0; i < assignArray.size(); ++i)
            std::cout << assignArray[i] << " ";
        std::cout << std::endl;

        // Attempt to access out-of-bounds element
        std::cout << "\033[1;36m\nAccessing out-of-bounds element: \033[0m" << std::endl;
        std::cout << intArray[10] << std::endl;

    }
	catch (const std::exception& e)
	{
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
	{
        std::cout << "\033[1;32m\n\nData Struct Example:\n\033[0m" <<std::endl;
        std::cout << "\033[1;36mCreating an array of 3 Data -> Array<Data>	dataArray(3);\033[0m" << std::endl;
        Array<Data>	dataArray(3);
        std::cout << "\033[1;34m\nArray size: " << dataArray.size() << "\033[0m" << std::endl;

        for (unsigned int i = 0; i < dataArray.size(); ++i)
		{
            std::stringstream ss;
            ss << i;
			std::cout << "Assigning values to element " << i << std::endl;
            dataArray[i].number = i;
            dataArray[i].text = "Text " + ss.str();
		}

        // Print the array elements
        std::cout << "\033[1;36m\nArray elements: \033[0m";
        for (unsigned int i = 0; i < dataArray.size(); ++i)
        {
            std::cout << "Element " << i << ":" << std::endl;
            std::cout << "text: " << dataArray[i].text << " " << std::endl;
            std::cout << "number: " << dataArray[i].number << " " << std::endl;
        }
        std::cout << std::endl;

        // Copy the array using copy constructor
        std::cout << "\033[1;36m\nCopying the array using copy constructor -> Array<Data>	copyArray(dataArray);\033[0m" << std::endl;
        Array<Data> copyArray(dataArray);
        std::cout << "\033[1;36m\nCopy Array elements: \033[0m";
        for (unsigned int i = 0; i < copyArray.size(); ++i)
        {
            std::cout << "Element " << i << ":" << std::endl;
            std::cout << "text: " << copyArray[i].text << " " << std::endl;
            std::cout << "number: " << copyArray[i].number << " " << std::endl;
        }
        std::cout << std::endl;

        // Test assignment operator
        std::cout << "\033[1;36m\nAssigning the array using assignment operator -> Array<int>	assignArray = intArray;\033[0m" << std::endl;
        Array<Data> assignArray;
        assignArray = dataArray;
        std::cout << "\033[1;36m\nAssigned Array elements: \033[0m";
        for (unsigned int i = 0; i < assignArray.size(); ++i)
        {
            std::cout << "Element " << i << ":" << std::endl;
            std::cout << "text: " << assignArray[i].text << " " << std::endl;
            std::cout << "number: " << assignArray[i].number << " " << std::endl;
        }
        std::cout << std::endl;

        // Attempt to access out-of-bounds element
        std::cout << "\033[1;36m\nAccessing out-of-bounds element: \033[0m" << std::endl;
        std::cout << dataArray[10].text << std::endl;

    }
	catch (const std::exception& e)
	{
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
