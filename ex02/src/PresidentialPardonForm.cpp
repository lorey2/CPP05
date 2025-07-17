/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:55:43 by lorey             #+#    #+#             */
/*   Updated: 2025/07/17 12:57:23 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Default name", false, 72, 45) {
	this->_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Robotomy Form", false, 72, 45) {
	this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form): AForm(form) {
	this->_target = form._target;
	*this = form;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &form) {
	_target = form._target;
	this->_isSigned = form._isSigned;
	//we cannot copy the name and gradTo because it is const. Btw overload = operator is dumb here
	return (*this);
}

void PresidentialPardonForm::performAction() const {
	std::cout << this->_target << " has been pardoned by Zaphod Beeblerox." << std::endl;
}
