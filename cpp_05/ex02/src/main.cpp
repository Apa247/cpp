/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:31:03 by daparici          #+#    #+#             */
/*   Updated: 2024/11/10 14:01:54 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:13:00 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/15 20:05:56 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
     try
	{
		std::cout << "\033[1;36m\nCreating a Bureaucrat John with grade 2 -> Bureaucrat john(\"John\", 2);\033[0m" << std::endl;
        Bureaucrat john("John", 2);
        std::cout << john << std::endl;

		std::cout << "\033[1;36m\nIncrementing John's grade -> john.incrementGrade();\033[0m" << std::endl;
        john.incrementGrade(); // Goes to 1
        std::cout << john << std::endl;
	
        // This should throw an exception because it tries to go below 1
		std::cout << "\033[1;36m\nTrying to increment John's grade -> john.incrementGrade();\033[0m" << std::endl;
        john.incrementGrade();
    }
	catch (const std::exception &e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
	{
		std::cout << "\033[1;36m\nCreating a Bureaucrat Mike with grade 149 -> Bureaucrat mike(\"Mike\", 149);\033[0m" << std::endl;
        Bureaucrat mike("Mike", 149);
        std::cout << mike << std::endl;

        mike.decrementGrade(); // Lowers to 150
		std::cout << "\033[1;36m\nDecrementing Mike's grade -> mike.decrementGrade();\033[0m" << std::endl;
        std::cout << mike << std::endl;

        //This should throw an exception because it tries to go above 150
		std::cout << "\033[1;36m\nTrying to decrement Mike's grade -> mike.decrementGrade();\033[0m" << std::endl;
        mike.decrementGrade();
    }
	catch (const std::exception &e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
	{
        // Try to create a Bureaucrat with an invalid grade
		std::cout << "\033[1;36m\nTrying to create a Bureaucrat with an invalid grade ->";
		std::cout << " Bureaucrat invalidBureaucrat(\"Invalid\", 151);\033[0m" << std::endl;
        Bureaucrat invalidBureaucrat("Invalid", 151);
    }
	catch (const std::exception &e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
	{
        // Try to create a Bureaucrat with an invalid grade
		std::cout << "\033[1;36m\nTrying to create a Bureaucrat with an invalid grade ->";
		std::cout << " Bureaucrat invalidBureaucrat(\"Invalid\", 0);\033[0m" << std::endl;
        Bureaucrat invalidBureaucrat("Invalid", 0);
    }
	catch (const std::exception &e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

	try
	{
		std::cout << "\033[1;31m\n\nEX02\033[0m" << std::endl;
		std::cout << "\033[1;36m\nCreating a Bureaucrat bureaucrat_grade_1 with grade 1 ->";
		std::cout << " Bureaucrat bureaucrat_grade_1(\"bureaucrat_grade_1\", 1);\033[0m" << std::endl;
        Bureaucrat bureaucrat_grade_1("bureaucrat_grade_1", 1);
		std::cout << bureaucrat_grade_1 << std::endl;

		std::cout << "\n" << std::endl;
		
		std::cout << "\033[1;36m\nCreating a Bureaucrat bureaucrat_grade_50 with grade 50 ->";
		std::cout << " Bureaucrat bureaucrat_grade_50(\"bureaucrat_grade_50\", 1);\033[0m" << std::endl;
        Bureaucrat bureaucrat_grade_50("bureaucrat_grade_50", 50);
		std::cout << bureaucrat_grade_50 << std::endl;

		std::cout << "\n" << std::endl;

		std::cout << "\033[1;36m\nCreating a Bureaucrat bureaucrat_grade_138 with grade 138 ->";
		std::cout << " Bureaucrat bureaucrat_grade_138(\"bureaucrat_grade_138\", 138);\033[0m" << std::endl;
		Bureaucrat bureaucrat_grade_138("bureaucrat_grade_138", 138);
		std::cout << bureaucrat_grade_138 << std::endl;

		std::cout << "\n" << std::endl;
		
		std::cout << "\033[1;36m\nCreating a Bureaucrat bureaucrat_grade_150 with grade 150 ->";
		std::cout << " Bureaucrat bureaucrat_grade_150(\"bureaucrat_grade_150\", 150);\033[0m" << std::endl;
		Bureaucrat bureaucrat_grade_150("bureaucrat_grade_150", 150);
		std::cout << bureaucrat_grade_150 << std::endl;

		std::cout << "\n" << std::endl;
		
		std::cout << "\033[1;36m\nCreating a Shrubbery Creation Form ->";
		std::cout << " ShrubberyCreationForm shrubbery(\"Home\");\033[0m" << std::endl;
        ShrubberyCreationForm shrubbery("Home");
		std::cout << shrubbery << std::endl;

		std::cout << "\n" << std::endl;
		
		std::cout << "\033[1;36m\nCreating a Robotomy Request Form ->";
		std::cout << " RobotomyRequestForm robot(\"Alice\");\033[0m" << std::endl;
        RobotomyRequestForm robot("Alice");
		std::cout << robot << std::endl;

		std::cout << "\n" << std::endl;
		
		std::cout << "\033[1;36m\nCreating a Presidential Pardon Form ->";
		std::cout << " PresidentialPardonForm pardon(\"Marvin\");\033[0m" << std::endl;
        PresidentialPardonForm pardon("Marvin");
		
		std::cout << "\n" << std::endl;

        // Execution tests
		std::cout << "\033[1;31m\n\nTESTS\033[0m" << std::endl;
		std::cout << "\033[1;36m\nTrying to sign and execute the forms with bureaucrat_grade_150 ->";
		std::cout << " bureaucrat_grade_150.signForm(shrubbery); bureaucrat_grade_150.executeForm(shrubbery);\033[0m" << std::endl;
		bureaucrat_grade_150.signForm(shrubbery);
		bureaucrat_grade_150.executeForm(shrubbery);
		std::cout << "\033[1;36m\nTrying to sign and execute the forms with bureaucrat_grade_138 ->";
		std::cout << " bureaucrat_grade_138.signForm(shrubbery); bureaucrat_grade_138.executeForm(shrubbery);\033[0m" << std::endl;
		bureaucrat_grade_138.signForm(shrubbery);
		bureaucrat_grade_138.executeForm(shrubbery);
		std::cout << "\033[1;36m\nTrying to sign and execute the forms with bureaucrat_grade_50 ->";
		std::cout << " bureaucrat_grade_50.signForm(shrubbery); bureaucrat_grade_50.executeForm(shrubbery);\033[0m" << std::endl;
		bureaucrat_grade_50.signForm(shrubbery);
		bureaucrat_grade_50.executeForm(shrubbery);

		std::cout << "\n" << std::endl;

		std::cout << "\033[1;36m\nTrying to sign and execute the forms with bureaucrat_grade_138 ->";
		std::cout << " bureaucrat_grade_138.signForm(robot); bureaucrat_grade_138.executeForm(robot);\033[0m" << std::endl;
		bureaucrat_grade_138.signForm(robot);
		bureaucrat_grade_138.executeForm(robot);
		std::cout << "\033[1;36m\nTrying to sign and execute the forms with bureaucrat_grade_50 ->";
		std::cout << " bureaucrat_grade_50.signForm(robot); bureaucrat_grade_50.executeForm(robot);\033[0m" << std::endl;
		bureaucrat_grade_50.signForm(robot);
		bureaucrat_grade_50.executeForm(robot);
		std::cout << "\033[1;36m\nTrying to sign and execute the forms with bureaucrat_grade_1 ->";
		std::cout << " bureaucrat_grade_1.signForm(robot); bureaucrat_grade_1.executeForm(robot);\033[0m" << std::endl;
        bureaucrat_grade_1.signForm(robot);
        bureaucrat_grade_1.executeForm(robot);

		std::cout << "\n" << std::endl;

		std::cout << "\033[1;36m\nTrying to sign and execute the forms with bureaucrat_grade_50 ->";
		std::cout << " bureaucrat_grade_50.signForm(pardon); bureaucrat_grade_50.executeForm(pardon);\033[0m" << std::endl;
		bureaucrat_grade_50.signForm(pardon);
		bureaucrat_grade_50.executeForm(pardon);
        std::cout << "\033[1;36m\nTrying to sign and execute the forms with bureaucrat_grade_1 ->";
		std::cout << " bureaucrat_grade_1.signForm(pardon); bureaucrat_grade_1.executeForm(pardon);\033[0m" << std::endl;
		bureaucrat_grade_1.signForm(pardon);
        bureaucrat_grade_1.executeForm(pardon);
		std::cout << "\033[1;36m\nTrying to execute the forms with bureaucrat_grade_50 -> bureaucrat_grade_50.executeForm(pardon);\033[0m" << std::endl;
		bureaucrat_grade_50.executeForm(pardon);
		
		std::cout << "\n" << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	
	std::cout << "\n" << std::endl;
	
    return 0;
}