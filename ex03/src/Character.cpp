/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:52:06 by lorey             #+#    #+#             */
/*   Updated: 2025/05/09 13:37:57 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <ostream>

Character::Character()
{
	this->name = "default character";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->unequiped_materia[i] = NULL;
	std::cout << "Hey I'm " << this->name << std::endl;
}

Character::Character(std::string cname)
{
	this->name = cname;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->unequiped_materia[i] = NULL;
	std::cout << "Hey I'm " << this->name << std::endl;
}

Character::Character(const Character &character)
{
	*this = character;
}

Character& Character ::operator=(const Character &character)
{
	if (this == &character)
	{
		std::cout << "self assignement..." << std::endl;
		return *this;
	}
	this->name = character.name;
	for(int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete (this->inventory[i]);
		if (character.inventory[i])
			this->inventory[i] = character.inventory[i]->clone();
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete (this->inventory[i]);
	}
	for (int i = 0; i < 100; i++)
	{
		if (this->unequiped_materia[i])
			delete (this->unequiped_materia[i]);
	}
}

const std::string& Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			std::cout << this->name << " learned " << m->getType() << std::endl;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	int	i;

	std::cout << "unequip called index: " << idx << std::endl;
	if (idx >= 0 && idx <= 3)
	{
		if (this->inventory[idx])
		{
			for (i = 0; unequiped_materia[i]; i++)
				;
			this->unequiped_materia[i] = this->inventory[idx];
			std::cout << this->name << " unequiped " << this->inventory[idx]->getType() << std::endl;
			this->inventory[idx] = NULL;
		}
		else
			std::cout << "no materia equiped at index " << idx << std::endl;
	}
	else
		std::cout << "bad index" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && this->inventory[idx])
		this->inventory[idx]->use(target);
	else
		std::cout << "bad index or no materia at index " << idx << std::endl;
}
