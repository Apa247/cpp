/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:09:57 by daparici          #+#    #+#             */
/*   Updated: 2024/11/10 15:59:58 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//------------------------- constructors --------------------------//

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", SIGN_GRADE, EXEC_GRADE), _target("default")
{
	std::cout << "Default RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", SIGN_GRADE, EXEC_GRADE), _target(target)
{
	std::cout << "RobotomyRequestForm Constructor with target " << this->_target << " called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm("RobotomyRequestForm", SIGN_GRADE, EXEC_GRADE), _target(cpy._target)
{
	std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
	*this = cpy;
}

//-------------------------- destructor ---------------------------//

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

//--------------------------- operator ----------------------------//

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

//------------------------- member function ------------------------//

void RobotomyRequestForm::executeAction() const
{
	std::cout << "Drilling noises... ";
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->_target << " robotomization failed." << std::endl;
}