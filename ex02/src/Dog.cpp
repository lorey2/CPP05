/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:52:54 by lorey             #+#    #+#             */
/*   Updated: 2025/05/02 18:21:25 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new(Brain);
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
	delete(this->brain);
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	this->type = dog.type;
}

Dog& Dog::operator=(const Dog &dog)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this == &dog)
	{
		std::cout << "self assignement..." << std::endl;
		return *this;
	}
	this->type = dog.type;
    return *this;
}

void	Dog::makeSound() const
{
	std::cout << "*dog sound*" << std::endl;
}
