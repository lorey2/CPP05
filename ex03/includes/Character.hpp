/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:14:47 by lorey             #+#    #+#             */
/*   Updated: 2025/05/09 13:04:51 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : virtual public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(const Character &character);
		Character& operator=(const Character &character);
		~Character();
		const std::string & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif // !CHARACTER_HPP
