/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:03:17 by lorey             #+#    #+#             */
/*   Updated: 2025/05/08 21:46:38 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	this->mat_type = "Default AMateria";
}

AMateria::AMateria(std::string const & type)
{
	this->mat_type = type;
}

AMateria::~AMateria()
{

}

AMateria::AMateria(const AMateria &amateria)
{
	this->mat_type = amateria.mat_type;
}

AMateria& AMateria::operator=(const AMateria &amateria)
{
	if (this == &amateria)
	{
		std::cout << "self assignement..." << std::endl;
		return *this;
	}
	this->mat_type = amateria.mat_type;
	return *this;
}


const std::string& AMateria::getType() const
{
	return (this->mat_type);
}
