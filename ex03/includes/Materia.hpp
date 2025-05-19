/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:04:28 by lorey             #+#    #+#             */
/*   Updated: 2025/05/08 23:55:35 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_HPP
# define MATERIA_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <iostream>
# include <iomanip>
# include <string>

class Materia : public AMateria
{
	protected:
		std::string mat_type;
	public:
		Materia();
        Materia(const Materia &);
        Materia(std::string const &type);
        ~Materia();
		Materia& operator=(const AMateria &amateria);
		Materia(const AMateria &amateria);
//[...]
		std::string const & getType() const; //Returns the materia type
		Materia* clone() const;
		void use(ICharacter& target);
};

#endif // MATERIA_HPP
