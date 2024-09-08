/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:19:27 by daparici          #+#    #+#             */
/*   Updated: 2024/09/08 02:18:37 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iomanip>
#include <iostream>
#include "Contact.hpp"


class PhoneBook
{
	private:
		Contact	contact[8];
		int		c_index;
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	setC_index(int index);
		void	addContact(void);
		void	searchContact(void);
};

#endif