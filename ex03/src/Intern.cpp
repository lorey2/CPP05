/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:42:16 by lorey             #+#    #+#             */
/*   Updated: 2025/07/17 13:07:49 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {

}

Intern::~Intern() {

}

Intern::Intern(const Intern &intern) {
	(void) intern;
}

Intern &Intern::operator=(const Intern &intern) {
	(void) intern;
	return (*this);
}

AForm* Intern::makeForm(const std::string form_name, const std::string target) {
	int i = 0;
	std::string form_names[] = {"ShrubberyCreationForm", "robotomy request", "PresidentialPardonForm"};

	while (i < 3 && form_name != form_names[i])
		i++;
	
	switch (i) {
	case 0:
		std::cout << "Intern creates " << form_name << std::endl;
		return (new ShrubberyCreationForm(target));
	case 1:
		std::cout << "Intern creates " << form_name << std::endl;
		return (new RobotomyRequestForm(target));
	case 2:
		std::cout << "Intern creates " << form_name << std::endl;
		return (new PresidentialPardonForm (target));
	default:
		std::cout << "Form does not exist" << std::endl;
		return NULL;
	}
}
