/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:52:54 by lorey             #+#    #+#             */
/*   Updated: 2025/05/02 18:42:01 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Default constructor called" << std::endl;
	this->type = "Animal";
}

Animal::~Animal(void)
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	this->type = animal.type;
}

Animal& Animal::operator=(const Animal &animal)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this == &animal)
	{
		std::cout << "self assignement..." << std::endl;
		return *this;
	}
	this->type = animal.type;
    return *this;
}

std::string Animal::getType() const
{
	return this->type;
}
