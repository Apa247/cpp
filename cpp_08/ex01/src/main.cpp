/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:58:27 by daparici          #+#    #+#             */
/*   Updated: 2025/01/25 16:32:00 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
 {
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------------------" << std::endl;
	std::cout << "Testing addNumbers" << std::endl << std::endl;

	Span sp2 = Span(5);
	std::vector<int> v;
	v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
	try
	{
		sp2.addNumbers(v.begin(), v.end());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "-------------------" << std::endl;
	std::cout << "Testing full Span" << std::endl << std::endl;

	try
	{
		sp2.addNumber(6);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "-------------------" << std::endl;
	std::cout << "Testing empty Span" << std::endl << std::endl;

	Span sp3 = Span(1);
	try
	{
		sp3.shortestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------------------" << std::endl;
	std::cout << "Testing one number Span" << std::endl << std::endl;

	Span sp4 = Span(1);
	sp4.addNumber(1);
	try
	{
		sp4.longestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------------------" << std::endl;
	std::cout << "Testing fillRandom" << std::endl << std::endl;

	Span sp5 = Span(5);
	try
	{
		sp5.fillRandom(5);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "-------------------" << std::endl;
	std::cout << "Testing fillRandom with exceeded numbers" << std::endl << std::endl;
	
	Span sp6 = Span(5);
	try
	{
		sp6.fillRandom(6);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
 }
