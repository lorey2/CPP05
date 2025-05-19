/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:07:58 by lorey             #+#    #+#             */
/*   Updated: 2025/05/09 01:20:47 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
# include <iostream>
# include <iomanip>
# include <string>

class Ice : public virtual AMateria
{
	protected:
//[...]
	public:
		Ice();
		Ice(const Ice &ice);
		Ice& operator=(const Ice &ice);
		~Ice();
//[...]
		std::string const & getType() const; //Returns the materia type
		Ice* clone() const;
		void use(ICharacter& target);
};


#endif //  CURE_HPP
