/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:37:01 by daparici          #+#    #+#             */
/*   Updated: 2024/10/18 16:49:43 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

bool	replaceInFile(const std::string &filename, const std::string &s1, const std::string &s2)
{
	//función para abrir el archivo.
	std::ifstream	inputFile(filename.c_str());
	if (!inputFile)
	{
		std::cerr << "Error: Filename can't be open." << std::endl;
		return false;
	}
	
    // Comprobación para asegurar que el archivo no esté vacío.
    inputFile.seekg(0, std::ios::end); // Mueve el puntero al final del archivo.
    if (inputFile.tellg() == 0) // Comprueba si la posición del puntero es 0 (archivo vacío).
    {
        std::cerr << "Error: The file is empty." << std::endl;
        return false;
    }
    inputFile.seekg(0, std::ios::beg); // Mueve el puntero de nuevo al inicio del archivo para la lectura.
	
	std::ofstream	outputFile((filename + ".replace").c_str());
	if (!outputFile)
	{
		std::cerr << "Error: outputFile can't be created.";
	}

	std::string 	line;
	while (std::getline(inputFile, line))
	{
		size_t	pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outputFile << line << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return true;
}

int 	main (int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error in number of arguments: You must ingress <file name> <replaced string> <replacement stgring>." << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (replaceInFile(filename, s1, s2))
		std::cout << "Replacement is saccessfully into the file:" << filename + ".replace" << std::endl;
	else
	{
		std::cerr << "Error processing the file" << std::endl;
		return 1;
	}
	return 0;
}