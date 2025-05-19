/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:52:54 by lorey             #+#    #+#             */
/*   Updated: 2025/05/02 16:21:44 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat Default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrong_cat) :WrongAnimal(wrong_cat)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	this->type = wrong_cat.type;
}

WrongCat& WrongCat::operator=(const WrongCat &wrong_cat)
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if (this == &wrong_cat)
	{
		std::cout << "self assignement..." << std::endl;
		return *this;
	}
	this->type = wrong_cat.type;
    return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "*cat sound*" << std::endl;
}
