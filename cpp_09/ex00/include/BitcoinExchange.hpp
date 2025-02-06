/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:25:51 by daparici          #+#    #+#             */
/*   Updated: 2025/01/29 18:28:36 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <fstream>
# include <string>
# include <cstring>
# include <map>
# include <ctime>
# include <sstream>
# include <utility>

class BitcoinExchange {
	
	private:
		std::string _db_path;
		std::map<std::string, float> _db;

	public:
		BitcoinExchange(void);
		BitcoinExchange(std::string db_path);
		BitcoinExchange(BitcoinExchange const & src);
		~BitcoinExchange(void);
		BitcoinExchange & operator=(BitcoinExchange const & rhs);

		void construct_db(void);
		std::string dbPath(void) const;
		float getRate(std::string date);

		class CantReadDataFile : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};