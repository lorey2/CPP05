/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:12:50 by lorey             #+#    #+#             */
/*   Updated: 2025/11/17 11:13:00 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &intern);
		~Intern();
		Intern& operator=(const Intern &intern);
		AForm* makeForm(const std::string form_name, const std::string target);
	class FormNotFoundException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};
