/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:53:07 by daparici          #+#    #+#             */
/*   Updated: 2025/01/26 20:03:43 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

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
	
	// Open the file
	std::string line;
	std::ifstream dbfile(this->_db_path.c_str());

	if (!dbfile.is_open()) {
		throw CantReadDataFile();
	}

	this->_db.clear();
	
	// Read the file by line
	int ctr = -1;
	while (getline(dbfile, line)) {
		ctr++;
		if (ctr == 0) 
			continue;
		
		bool ignore = false;

		// Split the line by comma
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

		// Check date format
		if 
	}
}
