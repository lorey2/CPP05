/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:11:29 by lorey             #+#    #+#             */
/*   Updated: 2025/05/02 18:20:45 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "";
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
}

Brain& Brain::operator=(const Brain &brain)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this == &brain)
	{
		std::cout << "self assignement..." << std::endl;
		return *this;
	}
    return *this;
}
