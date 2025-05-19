/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:07:44 by lorey             #+#    #+#             */
/*   Updated: 2025/05/09 01:20:40 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
# include <iostream>
# include <iomanip>
# include <string>

class Cure : public virtual AMateria
{
	protected:
//[...]
	public:
		Cure();
		Cure(const Cure &cure);
		Cure& operator=(const Cure &cure);
		~Cure();
//[...]
		std::string const & getType() const; //Returns the materia type
		Cure* clone() const;
		void use(ICharacter& target);
};


#endif //  CURE_HPP
