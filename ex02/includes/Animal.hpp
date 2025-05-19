/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:14:46 by lorey             #+#    #+#             */
/*   Updated: 2025/05/02 18:44:02 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal &animal);
		virtual ~Animal();
		virtual Animal& operator=(const Animal &animal);
		virtual void	makeSound() const = 0;
		std::string	getType() const;
};

#endif
