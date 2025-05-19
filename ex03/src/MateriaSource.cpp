/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:31:51 by lorey             #+#    #+#             */
/*   Updated: 2025/05/09 13:36:32 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->ma_inventory[0] = NULL;
	this->ma_inventory[1] = NULL;
	this->ma_inventory[2] = NULL;
	this->ma_inventory[3] = NULL;
	std::cout << "Materia source created (default)" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &materia_source)
{
	*this = materia_source;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->ma_inventory[i])
			delete (this->ma_inventory[i]);
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &materia_source)
{
	if (this == &materia_source)
	{
		std::cout << "self assignement..." << std::endl;
		return *this;
	}
	for(int i = 0; i < 4; i++)
	{
		if (this->ma_inventory[i])
			delete (this->ma_inventory[i]);
		if (materia_source.ma_inventory[i])
			this->ma_inventory[i] = materia_source.ma_inventory[i]->clone();
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	for(int i = 0; i < 4; i++)
	{
		if(!this->ma_inventory[i])
		{
			ma_inventory[i] = materia;
	 		std::cout << "materia " << materia->getType() << " learned" << std::endl;
			return ;
		}
	}
}

 AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (ma_inventory[i]->getType() == type)
			return (ma_inventory[i]->clone());
	}
	return(NULL);
}
