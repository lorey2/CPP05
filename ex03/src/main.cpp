/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:59:45 by lorey             #+#    #+#             */
/*   Updated: 2025/08/20 13:28:43 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

void	testTree() {
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	Bureaucrat b("hey", 1);
	ShrubberyCreationForm s("./hey");
	PresidentialPardonForm p("oui");
	RobotomyRequestForm r("non");
	b.signForm(s);
	b.signForm(p);
	b.signForm(r);
	b.signForm(*rrf);
	try {
		s.execute(b);
		p.execute(b);
		r.execute(b);
	}
	catch (const RobotomyRequestForm::RobotomizationFailed& e) {
		std::cerr << "Caught an exception: " << e.what() << std::endl;
	}
	try {
		rrf->execute(b);
	}
	catch (const RobotomyRequestForm::RobotomizationFailed& e) {
		std::cerr << "Caught an exception: " << e.what() << std::endl;
	}
}

int main() {
    srand(time(NULL));
	testTree();
    std::cout << "\n--- All tests completed ---" << std::endl;
    return 0;
}
