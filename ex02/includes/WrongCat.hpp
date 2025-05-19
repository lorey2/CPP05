/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:28:15 by lorey             #+#    #+#             */
/*   Updated: 2025/05/02 16:18:01 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include "WrongAnimal.hpp"
# include <iostream>
# include <iomanip>
# include <string>

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &wrong_cat);
		~WrongCat();
		WrongCat& operator=(const WrongCat &wrong_cat);
		void	makeSound() const;
};

#endif
