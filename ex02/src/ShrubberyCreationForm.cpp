/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:33:37 by lorey             #+#    #+#             */
/*   Updated: 2025/07/17 12:58:24 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Default name", false, 145, 137) {
	this->_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Reforestation form", false, 145, 137) {
	this->_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form): AForm(form) {
	this->_target = form._target;
	*this = form;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form) {
	_target = form._target;
	this->_isSigned = form._isSigned;
	//we cannot copy the name and gradTo because it is const. Btw overload = operator is dumb here
	return (*this);
}

void ShrubberyCreationForm::performAction() const {
	std::ofstream outFile((_target + std::string("_shrubbery")).c_str());

	if (outFile) {
		outFile << "       _-_       \n";
		outFile << "    /~~   ~~\\    \n";
		outFile << "   /~~       ~~\\   \n";
		outFile << "  {           }  \n";
		outFile << "   \\  _-   -_  /   \n";
		outFile << "    ~  \\\\ //  ~    \n";
		outFile << "  _- -  | | _- _  \n";
		outFile << "    _ - | |   -_   \n";
		outFile << "        // \\\\      \n";
		outFile.close();
	}
	else
		throw ShrubberyCreationForm::OpenFileException();
}

char const* ShrubberyCreationForm::OpenFileException::what(void) const throw() {
	return ("cannot open file");
}
