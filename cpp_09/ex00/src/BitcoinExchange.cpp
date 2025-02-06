/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:53:07 by daparici          #+#    #+#             */
/*   Updated: 2025/02/04 21:15:14 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"
#include "../include/btc.hpp"

BitcoinExchange::BitcoinExchange(void) : _db_path("input/data.csv") {}

BitcoinExchange::BitcoinExchange(std::string db_path) : _db_path(db_path) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) : _db_path(src._db_path){
	this->_db_path = src._db_path;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs) {
	
	this->_db_path = rhs._db_path;
	
	std::map<std::string, float>::const_iterator it;;
	for (it = rhs._db.begin(); it != rhs._db.end(); it++) {
		this->_db[it->first] = it->second;
	} 
	return *this;
}

BitcoinExchange::~BitcoinExchange(void) {}

std::string BitcoinExchange::dbPath(void) const {
	return this->_db_path;
}

void BitcoinExchange::construct_db(void) {
	
	// Abrir el archivo
	std::string line;
	std::ifstream dbfile(this->_db_path.c_str());

	if (!dbfile.is_open()) {
		throw CantReadDataFile();
	}

	this->_db.clear();
	
	// Leer el archivo linea por linea
	int ctr = -1;
	while (getline(dbfile, line)) {
		ctr++;
		if (ctr == 0) 
			continue;
		
		bool ignore = false;

		// splitear la linea por coma
		char *ptr = strtok((char *)line.c_str(), ",");
		std::string date;
		std::string value;
		while (ptr != NULL)
		{
			if (date.empty())
				date = ptr;
			else if (value.empty())
				value = ptr;
			else
				ignore = true;

			// std::cout << ptr << std::endl;
			ptr = strtok(NULL, ",");
		}
		
		// chekeo formato de fecha
		if (!checkDateFormat(date) && !ignore)
		{
			std::cerr << "Error: Invalid date format (" << date << ")" << std::endl;
			ignore = true;
		}

		// chekeo formato de valor
		if (!checkValue(value) && !ignore)
		{
			std::cerr << "Error: Invalid value format (" << value << ")" << std::endl;
			ignore = true;
		}

		// si no hay errores, insertar en el mapa
		if (!ignore)
			this->_db[date] = strToFloat(value);
			//std::cout << "db[\"" << date << "\"] = " << this->_db[date] << std::endl;
	}
	dbfile.close();
}

float BitcoinExchange::getRate(std::string date){
	
	if (this->_db.size() == 0)
		return 0;

	if (this->_db.find(date) == this->_db.end())
	{
		std::map<std::string, float>::iterator it;
		std::string best_date;

		for (it = this->_db.begin(); it != this->_db.end(); ++it)
		{
			int comp = date.compare(it->first);

			// La fecha se puede ordenar alfabeticamente
			// ATM comp es -1, la fecha actual puede insertarse en la posicion de it
			
			if (comp == -1)
			{
				if (it != this->_db.begin())
					it--;		
				best_date = it->first;
				break;
			}
		}
		if (best_date.empty())
		{
			it--;
			best_date = it->first;
		}
		return this->_db[best_date];
	}
	return this->_db[date];
}

const char* BitcoinExchange::CantReadDataFile::what() const throw() {
	return "Error: Could not open file";
}


