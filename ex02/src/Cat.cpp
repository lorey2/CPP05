/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:52:54 by lorey             #+#    #+#             */
/*   Updated: 2025/05/02 18:21:39 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new(Brain);
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
	delete(this->brain);
}

Cat::Cat(const Cat &cat) :Animal(cat)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->type = cat.type;
}

Cat& Cat::operator=(const Cat &cat)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this == &cat)
	{
		std::cout << "self assignement..." << std::endl;
		return *this;
	}
	this->type = cat.type;
    return *this;
}

void	Cat::makeSound() const
{
	std::cout << "*cat sound*" << std::endl;
}
