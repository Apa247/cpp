/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:36:06 by daparici          #+#    #+#             */
/*   Updated: 2024/10/08 17:50:40 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "\033[34m Prueba ANIMAL\033[0m" << std::endl;
	const Animal	animal;

	std::cout << std::endl;
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const Animal	*meta[10];
	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
		{
			meta[i] = new Cat();
			std::cout << std::endl;
			if (meta[i] == NULL)
			{
				perror("Cat allocation failed");
				std::cerr << "Exiting process now";
				exit(1);
			}
		}
		else
		{
			meta[i] = new Dog();
			std::cout << std::endl;
			if (meta[i] == NULL)
			{
				perror("Dog allocation failed");
				std::cerr << "Exiting process now";
				exit(1);
			}
		}
	}
	std::cout << std::endl;

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		std::cout << "Animal _type: " << meta[i]->getType() << std::endl;
		meta[i]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		delete(meta[i]);
		std::cout << std::endl;
	}

//THIS PART IS FOR TESTING DEEP COPY ↓

	std::cout << std::endl << std::endl;
	std::cout << "#### showing that the Dog copy constructor creates a deep copy ####" << std::endl << std::endl;;
	std::cout << "------------------------- DOG -------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	Dog *a = new Dog();
	std::cout << std::endl;
	// Cat *a = new Cat();
	if (a == NULL)
	{
		perror("Allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}

	a->setIdea(0, "I have to sniff it");
	a->setIdea(1, "I have to pee on it");
	a->setIdea(2, "I have to sniff it again");
	a->setIdea(101, "some shit");
	a->setIdea(102, "some shit");

	Dog *b = new Dog(*a);
	std::cout << std::endl;
	// Cat *b = new Cat(*a);
	if (b == NULL)
	{
		perror("Allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
	std::cout << std::endl;

	std::cout << "\033[34mTesting a\033[0m" << std::endl;
	std::cout << "The " << a->getType() << " a has the following ideas: " << std::endl;
	a->getIdea();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing a\033[0m" << std::endl;
	delete(a);
	std::cout << std::endl;

	std::cout << "\033[34mTesting b\033[0m" << std::endl;
	std::cout << "The " << b->getType() << " b has the following ideas: " << std::endl;
	b->getIdea();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
	delete(b);
	std::cout << std::endl;

	std::cout << std::endl << std::endl;
	std::cout << "#### showing that the Cat copy constructor creates a deep copy ####" << std::endl << std::endl;;
	std::cout << "---------------------------- CAT --------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	Cat *c = new Cat();
	std::cout << std::endl;
	// Cat *a = new Cat();
	if (c == NULL)
	{
		perror("Allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}

	c->setIdea("I have to sniff it", 0);
	c->setIdea("I have to pee on it", 1);
	c->setIdea("I have to sniff it again", 2);
	c->setIdea("some shit", 102);
	c->setIdea("some shit", 101);

	Cat *d = new Cat(*c);
	std::cout << std::endl;
	// Cat *b = new Cat(*a);
	if (d == NULL)
	{
		perror("Allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
	std::cout << std::endl;

	std::cout << "\033[34mTesting a\033[0m" << std::endl;
	std::cout << "The " << c->getType() << " a has the following ideas: " << std::endl;
	c->getIdea();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing a\033[0m" << std::endl;
	delete(c);
	std::cout << std::endl;

	std::cout << "\033[34mTesting b\033[0m" << std::endl;
	std::cout << "The " << d->getType() << " b has the following ideas: " << std::endl;
	d->getIdea();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
	delete(d);
	std::cout << std::endl;


	return (0);
}