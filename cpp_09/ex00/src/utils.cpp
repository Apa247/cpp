/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:11:27 by daparici          #+#    #+#             */
/*   Updated: 2025/01/26 20:27:49 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstring>
#include <sstream>

bool checkDateFormat(std::string str)
{
	// Check field length
	std::string test_length = str;
	char *ptr;
	ptr = strtok((char *)test_length.c_str(), "-");

	int ctr = 0;
	while (ptr != NULL)
	{
		if (ctr == 0 && strlen(ptr) != 4) // Verifica que el año tenga 4 digitos
			return false;
		else if (ctr > 0 && strlen(ptr) != 2) // Verifica que el mes y el dia tengan 2 digitos
			return false;
		
		ptr = strtok(NULL, "-");
		ctr++;
	}
	if (ctr != 3) // Verifica que la fecha tenga 3 campos (año, mes, dia)
		return false;

	// Check Format 
	struct tm result;
	if (strptime(str.c_str(), "%Y-%m-%d", &result) == NULL) // Verifica que la fecha sea valida
		return false;
	
	return true;
}

bool checkValue(std::string str)
{
	std::stringstream s(str);
	float f;

	if (!(s >> f) || !s.eof()) // Verifica que el valor sea un numero
		return false;

	if (f < 0) // Verifica que el valor sea positivo
		return false;
	
	return true;
}

float strToFloat(std::string str)
{
	std::stringstream s(str);
	float f;

	if (!(s >> f) || !s.eof()) // Verifica que el valor sea un numero
		return -1;
	
	return f;
}