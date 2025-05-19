/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:09:11 by lorey             #+#    #+#             */
/*   Updated: 2025/05/02 18:11:01 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Brain
{
	protected:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &brain);
		~Brain();
		Brain& operator=(const Brain &brain);
};

#endif
