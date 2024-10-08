/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:31:03 by daparici          #+#    #+#             */
/*   Updated: 2024/10/08 22:31:05 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	thiery = Bureaucrat("Thiery", 3);
	std::cout << thiery << std::endl;

	try
	{
		for (int cur = 0; cur < 3; cur++)
		{
			thiery.incrementGrade();
			std::cout << "\t" << thiery << std::endl;
		}
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "\t" << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\t" << "Problem catched..." << std::endl;
	}

	std::cout << std::endl;
	Bureaucrat	thiery_copy = thiery;
	std::cout << thiery_copy << std::endl;
	std::cout << std::endl;

	Bureaucrat	sophie = Bureaucrat("Sophie", 150);
	std::cout << sophie << std::endl;
	try
	{
		sophie.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "\t" << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat	lou = Bureaucrat("Lou", 151);
		std::cout << lou << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}