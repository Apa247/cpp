/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:19:27 by daparici          #+#    #+#             */
/*   Updated: 2024/10/16 10:33:03 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iomanip>
#include <iostream>
#include "Contact.hpp"
#include <stdio.h>
#include <limits>


class PhoneBook
{
	private:
		Contact	contact[8];
		int		c_index;
		int		index_serch;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	setIndex_serch(int index);
		void	setC_index(int index);
		void	addContact(void);
		void	searchContact(void);
};

#endif