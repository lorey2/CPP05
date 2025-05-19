/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:28:15 by lorey             #+#    #+#             */
/*   Updated: 2025/05/02 18:13:59 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
# include <iostream>
# include <iomanip>
# include <string>

class Dog: public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &dog);
		~Dog();
		Dog& operator=(const Dog &dog);
		void	makeSound() const;
};

#endif
