/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:12:18 by lorey             #+#    #+#             */
/*   Updated: 2025/05/02 16:13:05 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Default constructor called" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrong_animal)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	this->type = wrong_animal.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &wrong_animal)
{
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	if (this == &wrong_animal)
	{
		std::cout << "self assignement..." << std::endl;
		return *this;
	}
	this->type = wrong_animal.type;
    return *this;
}
void	WrongAnimal::makeSound() const
{
	std::cout << "*generic animmal sound*" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}
