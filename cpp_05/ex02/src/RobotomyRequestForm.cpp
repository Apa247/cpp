/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:09:57 by daparici          #+#    #+#             */
/*   Updated: 2024/11/07 20:25:58 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//------------------------- constructors --------------------------//

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", SIGN_GRADE, EXEC_GRADE), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", SIGN_GRADE, EXEC_GRADE), _target(target)
{
}