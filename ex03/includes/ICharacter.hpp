/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:59:51 by lorey             #+#    #+#             */
/*   Updated: 2025/05/09 13:07:06 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_CHARACTER_HPP
# define I_CHARACTER_HPP

#include <string>

class AMateria;
class Materia;

class ICharacter
{
protected:
	std::string name;
	AMateria *inventory[4];
	AMateria *unequiped_materia[100];
public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif
