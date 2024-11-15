/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:33:24 by daparici          #+#    #+#             */
/*   Updated: 2024/11/10 15:59:53 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//------------------------- constructors --------------------------//

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", SIGN_GRADE, EXEC_GRADE), _target("default")
{
	std::cout << "Default ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", SIGN_GRADE, EXEC_GRADE), _target(target)
{
	std::cout << "ShrubberyCreationForm Constructor with target " << this->_target << " called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm("ShrubberyCreationForm", SIGN_GRADE, EXEC_GRADE), _target(cpy._target)
{
	std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
	*this = cpy;
}

//-------------------------- destructor ---------------------------//

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

//--------------------------- operator ----------------------------//

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

//------------------------- member function ------------------------//

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream outfile ((this->_target + "_shrubbery").c_str());
	if (outfile.is_open())
	{
		for (int i = 0; i < 3; i++)
		{
			outfile <<
			"         v" << std::endl <<
			"        >X<" << std::endl <<
			"         A" << std::endl <<
			"        d$b" << std::endl <<
			"      .d\\$$b." << std::endl <<
			"    .d$i$$\\$$b." << std::endl <<
			"       d$$@b" << std::endl <<
			"      d\\$$$ib" << std::endl <<
			"    .d$$$\\$$$b" << std::endl <<
			"  .d$$@$$$$\\$$ib." << std::endl <<
			"      d$$i$$b" << std::endl <<
			"     d\\$$$$@$b" << std::endl <<
			"  .d$@$$\\$$$$$@b." << std::endl <<
			".d$$$$i$$$\\$$$$$$b." << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			std::endl;
		}
		outfile.close();
		 std::cout << "Shrubbery form executed, ASCII trees created." << std::endl;
	}
	else
		std::cerr << "Error: Unable to create shrubbery file." << std::endl;
}

