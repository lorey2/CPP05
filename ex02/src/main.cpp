/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:59:45 by lorey             #+#    #+#             */
/*   Updated: 2025/05/09 13:46:49 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	test_wrong_animal()
{
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();
	delete(meta);
	delete(i);
}


void	draw_separation(void)
{
	std::cout	<< "\n\n"
				<< "\033[37m-=-=-=-=-=-=-=-=-=-"	<< std::endl
				<< "-=TEST  SEPARATOR=-"			<< std::endl
				<< "-=-=-=-=-=-=-=-=-=-\033[0m"
				<< "\n\n"
				<<std::endl;
}

void	animal_array(void)
{

	Animal *animal[4];
	for(int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			animal[i] = new(Cat);
		else
			animal[i] = new(Dog);
	}
	draw_separation();
	for(int i = 0; i < 4; i++)
		delete(animal[i]);
}

int main()
{
	test_wrong_animal();
	draw_separation();
	animal_array();
	return 0;
}
