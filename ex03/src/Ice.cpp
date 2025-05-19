/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:28:45 by lorey             #+#    #+#             */
/*   Updated: 2025/05/09 13:35:30 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	this->mat_type = "ice";
	std::cout << this->mat_type << " created" << std::endl;
}

Ice::~Ice()
{

}

Ice::Ice(const Ice &ice) : AMateria(ice)
{
	*this = ice;
}

Ice& Ice::operator=(const Ice &ice)
{
	if (this == &ice)
	{
		std::cout << "self assignement..." << std::endl;
		return *this;
	}
	this->mat_type = ice.mat_type;
	return *this;
}

std::string const &Ice::getType() const
{
	return (this->mat_type);
}

Ice* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout	<< "* shoots an ice bolt at "
				<< target.getName()
				<< " *"
				<< std::endl;
}
