/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:57:01 by daparici          #+#    #+#             */
/*   Updated: 2024/11/10 12:49:13 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//------------------------- constructors --------------------------//

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", SIGN_GRADE, EXEC_GRADE), _target("default")
{
	std::cout << "Default PresidentialPardonForm Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", SIGN_GRADE, EXEC_GRADE), _target(target)
{
	std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : AForm("PresidentialPardonForm", SIGN_GRADE, EXEC_GRADE), _target(cpy._target)
{
	std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
	*this = cpy;
}

//-------------------------- destructor ---------------------------//

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

//--------------------------- operator ----------------------------//

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

//------------------------- member function ------------------------//

void PresidentialPardonForm::executeAction() const
{
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
