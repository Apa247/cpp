/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:31:03 by daparici          #+#    #+#             */
/*   Updated: 2024/11/09 12:21:00 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	thiery = Bureaucrat("Thiery", 3);
	std::cout << std::endl;
	Bureaucrat	thiery_copy = thiery;
	std::cout << std::endl;
	Bureaucrat	sophie = Bureaucrat("Sophie", 150);
	std::cout << std::endl;
	Bureaucrat	lou = Bureaucrat("Lou", 20);
	std::cout << std::endl;

	Form		f1 = Form("f1", 75, 1);
	Form		f2 = Form("f2", 2, 1);
	Form		f3 = Form("f3", 20, 1);
	std::cout << std::endl;

	std::cout << "Create a form with incorect grade: ";
	try
	{
		Form	f4 = Form("f4", 0, 184);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "SignForm: Sophie sign F1: ";
	try
	{
		sophie.signForm(f1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "BeSigned: Thiery sign F2: ";
	try
	{
		f2.beSigned(thiery);
		std::cout << "OK" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "BeSigned: Thierry_copy sign F2: ";
	try
	{
		f2.beSigned(thiery_copy);
		std::cout << "OK" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	thiery_copy.incrementGrade();
	//thiery.incrementGrade();

	std::cout << "BeSigned: Thiery sign F2: ";
	try
	{
		f2.beSigned(thiery);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "BeSigned: Thierry_copy sign F2: ";
	try
	{
		f2.beSigned(thiery_copy);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "BeSigned: Thierry_copy sign F2: ";
	try
	{
		f2.beSigned(thiery_copy);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "SignForm: Lou sign F3: ";
	try
	{
		lou.signForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	return 0;
}