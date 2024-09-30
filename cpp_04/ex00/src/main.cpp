/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:10:53 by daparici          #+#    #+#             */
/*   Updated: 2024/09/30 21:54:55 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const Animal *animal = new Animal();
	std::cout << std::endl;
	std::cout << "\033[34mTesting\033[0m" << std::endl;

	std::cout << "Animal type: " << animal->getType() << std::endl;
	animal->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34mDestructing\033[0m" << std::endl;
	delete animal;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << std::endl;
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const Animal *cat = new Cat();
	std::cout << std::endl;
	
	std::cout << "\033[34mTesting\033[0m" << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;
	cat->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34mDestructing\033[0m" << std::endl;
	delete cat;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << std::endl;
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const Animal *dog = new Dog();
	std::cout << std::endl;
	
	std::cout << "\033[34mTesting\033[0m" << std::endl;
	std::cout << "Dog type: " << dog->getType() << std::endl;
	dog->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34mDestructing\033[0m" << std::endl;
	delete dog;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;
	
	std::cout << std::endl;
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const WrongAnimal *wrongAnimal = new WrongAnimal();
	std::cout << std::endl;

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	std::cout << "WrongAnimal type: " << wrongAnimal->getType() << std::endl;
	wrongAnimal->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34mDestructing\033[0m" << std::endl;
	delete wrongAnimal;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << std::endl;
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const WrongAnimal *wrongCat = new WrongCat();
	std::cout << std::endl;

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34mDestructing\033[0m" << std::endl;
	delete wrongCat;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << std::endl;
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const WrongCat *WrongCat2 = new WrongCat();
	std::cout << std::endl;

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	std::cout << "WrongCat2 type: " << WrongCat2->getType() << std::endl;
	WrongCat2->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34mDestructing\033[0m" << std::endl;
	delete WrongCat2;
	std::cout << std::endl;

	return 0;	
}