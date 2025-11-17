/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:41:25 by lorey             #+#    #+#             */
/*   Updated: 2025/11/17 11:06:13 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): AForm("Default name", false, 72, 45) {
	this->_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Form", false, 72, 45) {
	this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form): AForm(form) {
	this->_target = form._target;
	*this = form;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &form) {
	_target = form._target;
	this->_isSigned = form._isSigned;
	//we cannot copy the name and gradTo because it is const. Btw overload = operator is dumb here
	return (*this);
}

void RobotomyRequestForm::performAction() const {
	std::cout << "*Some drilling noises" << std::endl;
	if (std::rand() % 2 == 1)
		std::cout << this->_target << " has been robotomised" << std::endl;
	else
		throw RobotomizationFailed();
}

char const* RobotomyRequestForm::RobotomizationFailed::what(void) const throw() {
	return ("Robotomization failed");
}
