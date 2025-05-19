/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:14:46 by lorey             #+#    #+#             */
/*   Updated: 2025/05/02 16:07:20 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>
# include <iomanip>
# include <string>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &wrong_animal);
		virtual ~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal &wrong_animal);
		void	makeSound() const;
		std::string	getType() const;
};

#endif
